#pragma once
#include <iostream>


class Base {
public:
	void pub_mem();
	void memfcn(Base &b) { b = *this; }
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
	//char g() { return priv_mem; }
};

struct Priv_Derv : private Base {
	int f1() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
	//error!
	//void memfcn(Base &b) { b = *this; }
	
	//int use_base() { return prot_mem; }
};