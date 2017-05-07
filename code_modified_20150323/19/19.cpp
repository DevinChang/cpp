#include <iostream>
#include <fstream>
#include <vector>
#include "Sales_data.h"
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_value(Sales_data &sd, double t)
{
  return sd.avg_price() > t;
}

vector<Sales_data>::iterator find_first_high(vector<Sales_data> &vsd, double t)
{
  auto f = bind(check_value, _1, t);

  return find_if(vsd.begin(), vsd.end(), f);
}

int main(int argc, char *argv[])
{
  ifstream in(argv[1]);
  if (!in) {
    cout << "打开输入文件失败！" << endl;
    exit(1);
  }

  vector<Sales_data> vsd;
  Sales_data sd;
  while (read(in, sd))
    vsd.push_back(sd);

  print(cout, *find_first_high(vsd, 25));

  return 0;
}

