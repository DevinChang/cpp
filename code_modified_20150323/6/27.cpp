#include <iostream>
using namespace std;

int iCount(initializer_list<int> il)
{
    int count = 0;
    //����il��ÿһ��Ԫ��
    for (auto val : il)
    {
        count += val;
    }
    return count;
}

int main()
{
    //ʹ���б��ʼ���ķ�ʽ����initializer_list<int>����
    //Ȼ�������Ϊʵ�δ��ݸ�����iCount
    cout << "1,6,9�ĺ��ǣ�" << iCount({1, 6, 9}) << endl;
    cout << "4,5,9,18�ĺ��ǣ�" << iCount({4, 5, 9, 18}) << endl;
    cout << "10,10,10,10,10,10,10,10,10�ĺ��ǣ�" << iCount({10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;
    return 0;
}
