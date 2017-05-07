#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <ostream>
#include <algorithm>


void read_write(std::fstream &ifile, std::ofstream &ofile1, std::ofstream &ofile2){
	std::istream_iterator<int> in(ifile), eof;
	std::ostream_iterator<int> of1(ofile1, " ");
	std::ostream_iterator<int> of2(ofile2, "\n");
	/*
	while (in != eof){
		if (*in % 2)
			of1 = *in++;
		else
			of2 = *in++;
	}
	*/
	
	std::for_each(in, eof, [&of1, &of2](const int i){
		//note: *of1++ = i  <=> of1 = i  p361
		(i & 0x1 ? of1 : of2) = i;
	});
}


int main18(){
	std::fstream ifile("integrate.txt");
	std::ofstream ofile1("odd.txt");
	std::ofstream ofile2("even.txt");
	read_write(ifile, ofile1, ofile2);

	system("pause");
	return 0;
}