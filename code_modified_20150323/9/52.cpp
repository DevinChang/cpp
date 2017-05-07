#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <stdexcept>
using namespace std;

// ��ʾջ�ж���Ĳ�ͬ����
enum obj_type {LP, RP, ADD, SUB, VAL};
struct obj
{
    obj(obj_type type, double val = 0) { t = type; v = val; }
    obj_type t;
    double v;
};

inline void skipws(string &exp, size_t &p)
{
    p = exp.find_first_not_of(" ", p);
}

inline void new_val(stack<obj> &so, double v)
{
    if (so.empty() || so.top().t == LP)  // ��ջ��������
    {
        so.push(obj(VAL, v));
        //cout << "push " << v << endl;
    }
    else if (so.top().t == ADD || so.top().t == SUB)
    {
        // ֮ǰ�������
        obj_type type = so.top().t;
        so.pop();
        /*if (type == ADD)
          cout << "pop +" << endl;
        else cout << "pop -" << endl;*/
        //cout << "pop " << so.top().v << endl;
        // ִ�мӼ���
        if (type == ADD)
        {
            v += so.top().v;
        }
        else
        {
            v = so.top().v - v;
        }
        so.pop();
        so.push(obj(VAL, v));   // ������ѹջ
        //cout << "push " << v << endl;
    } else throw invalid_argument("ȱ�������");
}

int main()
{
    stack<obj> so;
    string exp;
    size_t p = 0, q;
    double v;

    cout << "��������ʽ��";
    getline(cin, exp);

    while (p < exp.size())
    {
        skipws(exp, p);     // �����ո�
        if (exp[p] == '(')  // ������ֱ��ѹջ
        {
            so.push(obj(LP));
            p++;
            //cout << "push LP" << endl;
        }
        else if (exp[p] == '+' || exp[p] == '-')
        {
            // �������
            if (so.empty() || so.top().t != VAL)
            {
                // ��ջ��֮ǰ����������
                throw invalid_argument("ȱ��������");
            }

            if (exp[p] == '+')    // �����ѹջ
            {
                so.push(obj(ADD));
            }
            else
            {
                so.push(obj(SUB));
            }
            p++;
            //cout << "push " << exp[p - 1] << endl;
        }
        else if (exp[p] == ')') //������
        {
            p++;

            if (so.empty())   // ֮ǰ����Զ�������
            {
                throw invalid_argument("δƥ��������");
            }

            if (so.top().t == LP)   // һ�Զ�����֮��������
            {
                throw invalid_argument("������");
            }

            if (so.top().t == VAL)  // ��ȷ��������������
            {
                v = so.top().v;
                so.pop();
                //cout << "pop " << v << endl;

                if (so.empty() || so.top().t != LP)
                {
                    throw invalid_argument("δƥ��������");
                }

                so.pop();
                //cout << "pop LP" << endl;
                new_val(so, v);   // �����������߼�һ��
            }
            else  // ջ���ض��������
            {
                throw invalid_argument("ȱ��������");
            }
        }
        else  // Ӧ����������
        {
            v = stod(exp.substr(p), &q);
            p += q;
            new_val(so, v);
        }
    }

    if (so.size() != 1 || so.top().t != VAL)
    {
        throw invalid_argument("�Ƿ����ʽ");
    }
    cout << so.top().v << endl;
    return 0;
}
