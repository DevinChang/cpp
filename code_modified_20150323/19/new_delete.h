#ifndef NEW_DELETE_H
#define NEW_DELETE_H

#include <cstdlib>
#include <new>
using namespace std;

void *operator new(size_t size)
{
    if (void *mem = malloc(size))
    {
        return mem;
    }
    else
    {
        throw bad_alloc();
    }
}

void operator delete(void *mem) noexcept
{
    free(mem);
}

#endif  // NEW_DELETE_H

