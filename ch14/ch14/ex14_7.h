#pragma once
#include <iostream>
#include <memory>



class Str {
	friend std::ostream &operator<< (std::ostream &os,  Str &);
	friend bool operator== (const Str &, const Str &);
	friend bool operator!= (const Str &, const Str &);
	friend bool operator< (const Str &lhs, const Str &rhs);
	friend bool operator<= (const Str &lhs, const Str &rhs);
	friend bool operator> (const Str &lhs, const Str &rhs);
	friend bool operator>= (const Str &lhs, const Str &rhs);
public:
	Str() = default;
	Str(const char *);
	Str(const Str&);
	Str(Str &&);
	Str &operator= (const Str&);
	Str &operator= (Str &&);
	~Str();
	//��const�ں�����ǰ���ʱ�����ε��Ǻ�������ֵ��
	//�ں����������ʾ�ǳ���Ա�������ú��������޸Ķ����ڵ��κγ�Ա��ֻ�ܷ��������������ܷ���д������
	const char *begin() const { return p; }
	const char *begin() { return p; }
	const char *end() const { return p + n; }
	const char *end() { return p + n; }
	const size_t size() const { return n; }
	const size_t length() const { return n - 1; }
private:
	size_t n;
	char *p;
	std::allocator<char> alloc;
	void free();
};