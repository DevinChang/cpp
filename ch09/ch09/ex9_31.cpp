#include <iostream>
#include <list>
#include <forward_list>
#include <vector>

//list�Ƿ����Ե��������ʲ��ܼӼ�����forward_list���Ԫ����Ҫ����ǰ����
int main12(){
	std::list<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::forward_list<int> lst(vi.begin(), vi.end());	
	auto iter = vi.begin();
	while (iter != vi.end()){
		if (*iter % 2){
			
			iter = vi.insert(iter, *iter + 3);
			//list or forward_list error: iter += 2
			//��Ϊlist����forward_list������˳��������ͬ���ǣ���������֧�ּӼ����㣬��Ϊ������Ԫ�ز������ڴ��������洢���޷�ͨ��
			//��ַ�ļӼ���Ԫ�ؼ�Զ�����ƶ�,������++���档
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