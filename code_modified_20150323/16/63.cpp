#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template <typename T>
int occur(vector<T> &vec, const T &v)
{
    int ret = 0;

    for (auto a : vec)
    {
        if (a == v)
        {
            ret++;
        }
    }
    return ret;
}

template <>
int occur(vector<char *> &vec, char * const &v)
{
    int ret = 0;

    for (auto a : vec)
    {
        if (!strcmp(a, v))
        {
            ret++;
        }
    }
    return ret;
}

int main()
{
    vector<double> vd = { 1.1, 3.14, 2.2, 3.14, 3.3, 4.4};
    cout << occur(vd, 3.14) << endl;

    vector<int> vi = { 0, 1, 2, 3, 4, 5 };
    cout << occur(vi, 0) << endl;

    vector<string> vs = { "Hello", "World", "!" };
    cout << occur(vs, string("end")) << endl;

    vector<char *> vp;
    vp.push_back(new char[6]);
    vp.push_back(new char[6]);
    vp.push_back(new char[2]);
    strcpy(vp[0], "Hello");
    strcpy(vp[1], "World");
    strcpy(vp[2], "!");
    char *w = new char[6];
    strcpy(w, "World");
    cout << occur(vp, w) << endl;
    delete w;
    delete vp[2];
    delete vp[1];
    delete vp[0];

    return 0;
}
