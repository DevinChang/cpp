#include <iostream>
#include <utility>




template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}