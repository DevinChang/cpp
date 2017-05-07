#include <iostream>
#include <memory>


void process(std::shared_ptr<int> ptr){
	std::cout << "inside the process function: " << ptr.use_count() << std::endl;
}


int main4(){
	
	//ex12_10
	/*
	std::shared_ptr<int> p(new int(42));
	process(std::shared_ptr<int>(p));
	std::cout << p.use_count() << std::endl;
	auto q = p;
	std::cout << p.use_count() << std::endl;
	std::cout << "the int p points to is: " << *p << std::endl;
	*/

	//ex12_11 an error was generated at run time : double free corruption.
	/**
	* @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr and copy it
	*          to the parameter.However it is not a copy of p. As a result, at end of this
	*          main function p will free the memory that has been freed inside process ().
	*          That's why "double freed or corruption" was generated.
	*/
	//process(std::shared_ptr<int>(p.get()));

	//ex12_12
	auto p = new int();
	auto sp = std::make_shared<int>();
	//process(sp); //OK
	//process(new int());  //error! 无法将参数从"int*转换尾"std:shared_ptr<int>"
	//process(p);  //error! 无法将参数从"int*转换尾"std:shared_ptr<int>"
	process(std::shared_ptr<int> (p)); //OK

	system("pause");
	return 0;
}