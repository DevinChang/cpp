#include <iostream>
#include <fstream>
#include "Sales_data.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "������ļ���" << endl;
        return -1;
    }

    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "�޷��������ļ�" << endl;
        return -1;
    }

    Sales_data total;  // ���浱ǰ��ͽ���ı���
    if (read(in, total))  // �����һ�ʽ���
    {
        Sales_data trans; 	// ������һ���������ݵı���
        while(read(in, trans))  // ����ʣ��Ľ���
        {
            if (total.isbn() == trans.isbn()) 	// ���isbn
            {
                total.combine(trans);	 // ���±���total��ǰ��ֵ
            }
            else
            {
                print(cout, total) << endl; 	// ������
                total = trans;  // ������һ����
            }
        }
        print(cout, total) << endl; 	// ������һ������
    }
    else
    { 									      // û�������κ���Ϣ
        cerr << "û������" << endl; 	// ֪ͨ�û�
    }

    return 0;
}
