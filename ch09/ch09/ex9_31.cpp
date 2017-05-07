#include <iostream>
#include <list>
#include <forward_list>
#include <vector>

//list是非线性的容器，故不能加减。而forward_list添加元素需要找其前驱。
int main12(){
	std::list<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::forward_list<int> lst(vi.begin(), vi.end());	
	auto iter = vi.begin();
	while (iter != vi.end()){
		if (*iter % 2){
			
			iter = vi.insert(iter, *iter + 3);
			//list or forward_list error: iter += 2
			//因为list或者forward_list与其他顺序容器不同的是，迭代器不支持加减运算，因为链表中元素并非在内存中连续存储，无法通过
			//地址的加减在元素间远距离移动,可以用++代替。
			//iter++;
			//iter++;
			std::advance(iter, 2);
		}
		else
			iter = vi.erase(iter);
	}
	auto pre = lst.before_begin();
	auto cur = lst.begin();
	while (cur != lst.end()){
		if (*cur % 2){
			cur = lst.insert_after(pre, *cur);
			//move pointer
			std::advance(cur, 2);
			std::advance(pre, 2);
		}		
		else
			cur = lst.erase_after(pre);
			
	}
	for (auto p : lst)
		std::cout << p << std::endl;
	system("pause");
	return 0;
}