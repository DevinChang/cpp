#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>  // Ҫʹ��EXIT_FAILURE
#include "make_plural.h"
using namespace std;
using line_no = vector<string>::size_type;

vector<string> file;      // �ļ�ÿ������
map<string, set<line_no>> wm; // ���ʵ��к�set��ӳ��

string cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it)
    {
        if (!ispunct(*it))
        {
            ret += tolower(*it);
        }
    }
    return ret;
}

void input_text(ifstream &is)
{
    string text;
    while (getline(is, text)) 		// ���ļ���ÿһ��
    {
        file.push_back(text); 		// ��������ı�
        int n = file.size() - 1; 	// ��ǰ�к�
        istringstream line(text); 	// �����ı��ֽ�Ϊ����
        string word;
        while (line >> word) 		// ������ÿ������
        {
            // ����ǰ�кŲ��뵽���к�set��
            // ������ʲ���wm�У���֮Ϊ�±���wm�����һ��
            wm[cleanup_str(word)].insert(n);
        }
    }
}

ostream &query_and_print(const string &sought, ostream & os)
{
    // ʹ��find�������±�����������ҵ��ʣ����⽫������ӵ�wm�У�
    auto loc = wm.find(sought);
    if (loc == wm.end())  // δ�ҵ�
    {
        os << sought << "������0��" << endl;
    }
    else
    {
        auto lines = loc->second;   // �к�set
        os << sought << "������" << lines.size() << "��" << endl;
        for (auto num : lines)    // ��ӡ���ʳ��ֵ�ÿһ��
        {
            os << "\t(��" << num + 1 << "��) " << *(file.begin() + num) << endl;
        }
    }
    return os;
}

void runQueries(ifstream &infile)
{
    // infile��һ��ifstream��ָ������Ҫ��ѯ���ļ�
    input_text(infile); // �����ı���������ѯmap
    // ���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // �������ļ�β���û������ˡ�q��ʱѭ����ֹ
        if (!(cin >> s) || s == "q")
        {
            break;
        }
        // ָ���ѯ����ӡ���
        query_and_print(s, cout) << endl;
    }
}

// �������Ψһ�������в�������ʾ�ı��ļ���
int main(int argc, char **argv)
{
    // ��Ҫ��ѯ���ļ�
    ifstream infile;
  	// ���ļ�ʧ�ܣ������쳣�˳�
    if (argc < 2 || !(infile.open(argv[1]), infile))
    {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }
  	runQueries(infile);
    return 0;
}
