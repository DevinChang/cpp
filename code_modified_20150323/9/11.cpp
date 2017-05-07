#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ilist = {1, 2, 3.0, 4, 5, 6, 7};      // 列表初始化
    vector<int> ilist_1{1, 2, 3.0, 4, 5, 6, 7};
    vector<int> ilist1;                               // 默认初始化
    vector<int> ilist2(ilist);                        // 拷贝初始化
    vector<int> ilist2_1=ilist;
    vector<int> ilist3(ilist.begin()+2, ilist.end()-1);   // 范围初始化
    vector<int> ilist4(7);                            // 缺省值初始化
    vector<int> ilist5(7, 3);                            // 指定值初始化

    cout << ilist.capacity() << " " << ilist.size() << endl;
    cout << ilist_1.capacity() << " " << ilist_1.size() << endl;
    cout << ilist1.capacity() << " " << ilist1.size() << endl;
    cout << ilist2.capacity() << " " << ilist2.size() << endl;
    cout << ilist2_1.capacity() << " " << ilist2_1.size() << endl;
    cout << ilist3.capacity() << " " << ilist3.size() << " " << ilist3[0] << " " << ilist3[ilist3.size()-1]  << endl;
    cout << ilist4.capacity() << " " << ilist4.size() << " " << ilist4[0] << " " << ilist4[ilist4.size()-1]  << endl;
    cout << ilist5.capacity() << " " << ilist5.size() << " " << ilist5[0] << " " << ilist5[ilist5.size()-1]  << endl;

    return 0;
}
