#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main()
{
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec = {7, 6, 5, 4, 3, 2, 1};
    
    // �������Ͳ�ͬ������ʹ�ÿ�����ʼ��
    // vector<double> ivec(ilist);
    // Ԫ���������ݣ���˿ɲ��÷�Χ��ʼ��
    vector<double> dvec(ilist.begin(), ilist.end());
  
    // �������Ͳ�ͬ������ʹ�ÿ�����ʼ��
    // vector<double> dvec1(ivec);
    // Ԫ���������ݣ���˿ɲ��÷�Χ��ʼ��
    vector<double> dvec1(ivec.begin(), ivec.end());

    cout << dvec.capacity() << " " << dvec.size() << " " << dvec[0] << " " << dvec[dvec.size()-1]  << endl;
    cout << dvec1.capacity() << " " << dvec1.size() << " " << dvec1[0] << " " << dvec1[dvec1.size()-1]  << endl;

    return 0;
}
