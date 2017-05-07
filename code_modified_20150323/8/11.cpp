#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo
{
	string name;
  	vector<string> phones;
};

int main()
{
	string line, word; 				    // �ֱ𱣴����������һ�к͵���
	vector<PersonInfo> people; 		// ����������������м�¼
	istringstream record;

	while (getline(cin, line))
	{
		PersonInfo info; 			      // ����һ������˼�¼���ݵĶ���
		record.clear();             // �ظ�ʹ���ַ�����ʱ��ÿ�ζ�Ҫ����clear
		record.str(line);	          // ����¼�󶨵��ն������
		record >> info.name; 		    // ��ȡ����
		while (record >> word)   	  // ��ȡ�绰����
		{
			info.phones.push_back(word); // ��������
		}

		people.push_back(info); 		// ���˼�¼׷�ӵ�peopleĩβ
	}

  return 0;
}
