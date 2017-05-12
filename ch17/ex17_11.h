#pragma once
#include <bitset>
#include <string>


template <size_t N> class Quiz;
template <size_t M>
size_t grade(const Quiz<M> &answer1, const Quiz<M> &answer2);

template <size_t N>
class Quiz {
	template <size_t M>
	friend size_t grade(const Quiz<M> &answer1, const Quiz<M> &answer2);
public:
	Quiz() = default;
	Quiz(std::string s) : bit(s) {}
	void set_solusion(size_t i, bool b) { bit.set(i, b); }
	std::bitset<N> get_solusion() { return bit; }
	
private:
	std::bitset<N> bit;
	unsigned long quize = 0;
};

template<size_t M>
inline size_t grade(const Quiz<M>& answer1, const Quiz<M>& answer2){
	auto result = answer1.bit & answer2.bit;
	return result.count();
}
