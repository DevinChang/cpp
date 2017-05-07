#include <string>

typedef std::string Type;
Type initVal(); //use 'string'

class Exercise{
public:
	typedef int Type; 
	Type setVal(Type); //use 'double'
	Type initVal(); //use 'double'
private:
	int val;
};


/*
//first Type is 'string', second is 'double' and initVal() use class Exercise
Type Exercise::setVal(Type parm){
	val = parm + initVal();
	return val;
}
*/

//modify: change Type to Exercise::Type and initVal() should be defined
Exercise::Type Exercise::initVal(){ return 0; }

Exercise::Type Exercise::setVal(Type parm){
	val = parm + initVal();
	return val;
}