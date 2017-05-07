#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo {
  string name;
  vector<string> phones;
};

string format(const string &s) { return s; }

bool valid(const string &s)
{
	// �����֤�绰���뽫�ڵ�17�½��ܣ����ڼ򵥷���trure
	return true;
}

int main(int argc, char *argv[])
{
	string line, word; 				    // �ֱ𱣴����������һ�к͵���
	vector<PersonInfo> people; 		// ����������������м�¼
	istringstream record;

  if (argc != 2) {
    cerr << "������ļ���" << endl;
    return -1;
  }
  ifstream in(argv[1]);
  if (!in) {
    cerr << "�޷��������ļ�" << endl;
    return -1;
  }

	while (getline(in, line)) {
		PersonInfo info; 			      // ����һ������˼�¼���ݵĶ���
		record.clear();           // �ظ�ʹ���ַ�����ʱ��ÿ�ζ�Ҫ����clear
		record.str(line);	          // ����¼�󶨵��ն������
		record >> info.name; 		    // ��ȡ����
		while (record >> word)  	  // ��ȡ�绰����
			info.phones.push_back(word); // ��������

		people.push_back(info); 		// ���˼�¼׷�ӵ�peopleĩβ
	}

  ostringstream os;
	for (const auto &entry : people) { // ��people��ÿһ��
	  ostringstream formatted, badNums; // ÿ��ѭ���������Ķ���
    for (const auto &nums : entry.phones) { // ��ÿ����
      if (!valid(nums)) {
        badNums << " " << nums; // �������ַ�����ʽ����badNums
      } else
        // ����ʽ�����ַ�����д�롱formatted
        formatted << " " << format(nums);
      }
      if (badNums.str().empty()) // û�д������
        os << entry.name << " " // ��ӡ����
          << formatted.str() << endl; // �͸�ʽ������
      else // ���򣬴�ӡ���ֺʹ������
        cerr << "input error: " << entry.name
          << " invalid number(s) " << badNums.str() << endl;
  }
  cout << os.str() << endl;

  return 0;
}
