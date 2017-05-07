#include <iostream>
using std::string;

//6_36
string(&func())[10];

//6_37
typedef string arrt[10];
arrt &func1();

//trailing return type
auto func2() ->string (&)[10];

string arr[10];
decltype(arr) &arrre();


