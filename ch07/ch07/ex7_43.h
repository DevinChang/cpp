

class NoDefault{
public:
	NoDefault(int){}
};

class C{
public:
	C() : obj(0){}
private:
	NoDefault obj;
};