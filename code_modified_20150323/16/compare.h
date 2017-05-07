#ifndef COMPARE_H
#define COMPARE_H
#include <cstring>

// implement strcmp-like generic compare function 
// returns 0 if the values are equal, 1 if v1 is larger, -1 if v1 is smaller
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// special version of compare to handle C-style character strings
template <>
inline
int compare(const char* const &v1, const char* const &v2)
{
    return std::strcmp(v1, v2);
}

#endif
