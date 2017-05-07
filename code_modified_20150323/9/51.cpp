#include <iostream>
#include <string>
#include "date.h"
using namespace std;

int main()
{
    string dates[] = {"Jan 1,2014", "February 1 2014", "3/1/2014",
                      //"Jcn 1,2014",
                      //"Janvary 1,2014",
                      //"Jan 32,2014",
                      //"Jan 1/2014",
                      "3 1 2014 ",
                      };
    try
    {
        for (auto ds : dates)
        {
            date d1(ds);
            cout << d1;
        }
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
