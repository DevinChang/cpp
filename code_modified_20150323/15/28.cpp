#include <iostream>
#include <string>
#include <vector>
#include "Bulk_quote.h"
using namespace std;

int main()
{
    vector<Quote> itemVec;
    for (size_t i = 0; i != 10; ++i)
    {
        Bulk_quote item("C++ Primer", 6, 5, 0.5);
        itemVec.push_back(item);
    }
 
    double sum = 0;
    for (vector<Quote>::iterator iter = itemVec.begin(); iter != itemVec.end(); ++iter)
    {
        sum += iter->net_price(10);   //调用Quote:: net_price
    }
 
    cout << sum << endl;    //output 600
}
