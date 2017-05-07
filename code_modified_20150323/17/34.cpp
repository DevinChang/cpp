/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool get_status()
{
  return false;
}

int main()
{
  bool b;
  cout << "default bool values: " << true << " " << false
      << "\nalpha bool values: " << boolalpha
      << true << " " << false << endl;

  bool bool_val = get_status();
  cout << boolalpha    // sets the internal state of cout
      << bool_val
      << noboolalpha; // resets the internal state to default formatting
      cout << endl;

  const int ival = 15, jval = 1024;  // const, so values never change

  cout << "default: " << 20 << " " << 1024 << endl;
  cout << "octal: " << oct << 20 << " " << 1024 << endl;
  cout << "hex: " << hex << 20 << " " << 1024 << endl;
  cout << "decimal: " << dec << 20 << " " << 1024 << endl;


  cout << showbase;    // show the base when printing integral values
  cout << "default: " << 20 << " " << 1024 << endl;
  cout << "in octal: " << oct  << 20 << " " << 1024 << endl;
  cout << "in hex: " << hex  << 20 << " " << 1024 << endl;
  cout << "in decimal: " << dec << 20 << " " << 1024 << endl;
  cout << noshowbase;  // reset the state of the stream

  cout << 10.0 << endl; 		// ��ӡ10
  cout << showpoint << 10.0 	// ��ӡ10.0000
      << noshowpoint << endl; 	// �ָ�С�����Ĭ�ϸ�ʽ

  cout << showpos << 10.0 << endl;  // �Ǹ�����ӡ+
  cout << noshowpos << 10.0 << endl; // �Ǹ�������ӡ+


  cout << uppercase << showbase << hex
      << "printed in hexadecimal: " << 20 << " " << 1024
      << nouppercase << noshowbase << dec << endl;

  int i = -16;
  double d = 3.14159;
  // ���׵�һ�У�ʹ���������С12��λ��
  cout << "i: " << setw(12) << i << "next col" << '\n'
      << "d: " << setw(12) << d << "next col" << '\n';
  // ���׵�һ�У������������
  cout << left
      << "i: " << setw(12) << i << "next col" << '\n'
      << "d: " << setw(12) << d << "next col" << '\n'
      << right; // �ָ���������
  // ���׵�һ�У��Ҷ���������
  cout << right
      << "i: " << setw(12) << i << "next col" << '\n'
      << "d: " << setw(12) << d << "next col" << '\n';
  // ���׵�һ�У�����������ڲ�
  cout << internal
      << "i: " << setw(12) << i << "next col" << '\n'
      << "d: " << setw(12) << d << "next col" << '\n';
  // ���׵�һ�У���#��Ϊ�����ַ�
  cout << setfill('#')
      << "i: " << setw(12) << i << "next col" << '\n'
      << "d: " << setw(12) << d << "next col" << '\n'
      << setfill(' '); // �ָ������Ĳ����ַ�

  cout << unitbuf; 		// ������������󶼻�����ˢ�»�����
  cout << "default format: " << 100 * sqrt(2.0) << '\n'
      << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
      << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
      //<< "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
      //<< "use defaults: " << defaultfloat << 100 * sqrt(2.0)
      << "\n\n";
  cout << nounitbuf; 		// �ص������Ļ��巽ʽ

  cout << "hi!" << endl;   	// ���hi��һ�����У�Ȼ��ˢ�»�����
  cout << "hi!" << flush; 	// ���hi��Ȼ��ˢ�»��������������κζ����ַ�
  cout << "hi!" << ends;   	// ���hi��һ�����ַ���Ȼ��ˢ�»�����

  char ch;
  cin >> noskipws; // ����cin��ȡ�հ׷�
  while (cin >> ch)
    cout << ch;
  cin >> skipws; // ��cin�ָ���Ĭ��״̬���Ӷ������հ׷�


  return 0;
}
