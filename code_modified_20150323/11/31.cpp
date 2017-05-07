#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void remove_author(multimap<string, string> &books, const string &author)
{
    auto pos = books.equal_range(author); // ���Ҹ������߷�Χ
    if (pos.first == pos.second)  // �շ�Χ��û�и�����
    {
        cout << "û��" << author << "�������" << endl << endl;
    }
    else
    {
        books.erase(pos.first, pos.second); // ɾ����������������
    }
}

void print_books(multimap<string, string> &books)
{
    cout << "��ǰ��Ŀ������" << endl;
    for (auto &book : books)  // ���������鼮����ӡ֮
    {
        cout << book.first << ", ��" << book.second << "��" << endl;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
  	multimap<string, string> books;
  	books.insert({"Barth, John", "Sot-Weed Factor"});
  	books.insert({"Barth, John", "Lost in the Funhouse"});
  	books.insert({"��ӹ", "���Ӣ�۴�"});
  	books.insert({"��ӹ", "�����˲�"});

  	print_books(books);
  	remove_author(books, "����");
    remove_author(books, "Barth, John");
    print_books(books);
    return 0;
}
