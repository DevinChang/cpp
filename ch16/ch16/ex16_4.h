#include <iostream>


template<typename I, typename T>
I ifind(I b, I e, const T &v) {
	while (b != e && *b != v)
		++b;
	return b;
}

