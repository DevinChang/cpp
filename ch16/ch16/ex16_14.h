#pragma once
#include <iostream>
#include <vector>
#include <string>


//class Window_mgr {
//public:
//	//typedef std::vector<Screen>::size_type ScreenIndex;
//	using ScreenIndex = std::vector<Screen>::size_type;
//	void clear(ScreenIndex);
//private:
//	std::vector<Screen> screens;
//};

template <unsigned, unsigned> class Screen;
template <unsigned H, unsigned W> 
std::ostream &operator<< (std::ostream &, const Screen<H, W> &);

template <unsigned H, unsigned W>
std::istream &operator >> (std::istream &, Screen<H, W> &);

template <unsigned H, unsigned W> class Screen {
	//friend void Window_mgr::clear(ScreenIndex);
	friend std::ostream & operator<< <H, W>(std::ostream &, const Screen<H, W>&);
	friend std::istream &operator >> <H, W>(std::istream &, Screen<H, W>&);
public:
	using pos = std::string::size_type;

	//typedef std::string::size_type pos;
	Screen() : contents(H * W, ' ') {}
	
	Screen(char c) : contents(H * W, c) {}
	char get() const {
		return contents[custor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char c) { contents[custor] = c; return *this; }
	Screen &set(pos, pos, char);
	//7_27
	Screen &display(std::ostream &os) {
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const {
		do_display(os);
		return *this;
	}
private:
	pos custor = 0;
	std::string contents;
	//7_27
	void do_display(std::ostream &os) const { os << contents; }
};



template<unsigned H, unsigned W>
inline char Screen<H, W>::get(pos ht, pos wd) const{
	auto row = ht * W;
	return contents[row + wd];
}

//2017/5/8 error: "Screen"使用类模板需要模板参数列表
//原因：因为类模板的名字不是一个类型名，只有实例化后才能成为类型
//fixed: Screen &Screen<H, W>::move(pos r, pos c)  --> Screen<H, W> &Screen<H, W>::move(pos r, pos c)
template<unsigned H, unsigned W>
inline Screen<H, W> & Screen<H, W>::move(pos r, pos c){
	auto row = r * W;
	custor = row + c;
	return *this;
}

template<unsigned H, unsigned W>
inline Screen<H, W> & Screen<H, W>::set(pos r, pos c, char ch){
	contents[r * W + c] = ch;
	return *this;
}

template<unsigned H, unsigned W>
std::ostream & operator<<(std::ostream &os, const Screen<H, W> &sc){
	os << sc.contents;
	return os;
}

//2017/5/8 error: 重载>>时，把第二个参数定义成const的引用!!!
//fixed：因为>>流会改变对象的状态，所以要注意不能将其加const
template<unsigned H, unsigned W>
std::istream & operator >> (std::istream &is, Screen<H, W> &sc){
	std::string str;
	is >> str;
	sc.contents = str.substr(0, H * W);
	
	
	/*char c;
	is >> c;
	std::string tmp(H * W, c);
	sc.contents = tmp;*/
	
	
	return is;
}
