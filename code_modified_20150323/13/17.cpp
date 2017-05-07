#include <iostream>
using namespace std;

class numbered
{
private:
    static int seq;
public:
    numbered () { mysn = seq++; }
    //13.15
    //numbered (numbered &n) { mysn = seq++; }
    int mysn;
};

int numbered::seq = 0;

//13.16
//void f(const numbered &s)
void f(numbered s)
{
    cout << s.mysn << endl;
}

int main(int argc, char **argv)
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
