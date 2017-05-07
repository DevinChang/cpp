#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_empty_string(vector<string> &vs)
{
  auto f = mem_fn(&string::empty);
  return count_if(vs.begin(), vs.end(), f);
}

int main(int argc, char *argv[])
{
  vector<string> vs = { "Hello", "", "world", "", "!" };
  cout << count_empty_string(vs);

  return 0;
}
