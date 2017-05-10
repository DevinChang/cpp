#include <iostream>



template <typename T1, typename T2>
auto func(T1 a, T2 b) -> decltype(a + b) {
	return a + b;
}