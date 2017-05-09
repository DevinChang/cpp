#pragma once


template <typename V>
std::ostream &mprint(std::ostream &os, V &v) {
	for (typename V::size_type i = 0; i < v.size(); ++i) {
		os << v[i] << " ";
	}
	return os;
}

template <typename V>
std::ostream &mprint2(std::ostream &os, V &v) {
	for (auto it = v.cbegin(); it != v.cend(); ++it)
		os << *it << " ";
	return os;
}