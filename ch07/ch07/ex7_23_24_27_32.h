#pragma once
#include <string>
#include <vector>

//7_32 add class Window_mgr
class Screen;

class Window_mgr{
public:
	//typedef std::vector<Screen>::size_type ScreenIndex;
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

class Screen{
	friend void Window_mgr::clear(ScreenIndex);
public:
	using pos = std::string::size_type;
	
	//typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	char get() const {
		return contents[custor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char c) { contents[custor] = c; return *this; }
	Screen &set(pos, pos, char);
	//7_27
	Screen &display(std::ostream &os){
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const {
		do_display(os);
		return *this;
	}
private:
	pos custor = 0;
	pos height = 0, width = 0;
	std::string contents;
	//7_27
	void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c){
	pos row = r * width;
	custor = row + c;
	return *this;
}

char Screen::get(pos ht, pos wd) const {
	pos row = ht * width;
	return contents[row + wd];
}

inline Screen &Screen::set(pos r, pos col, char ch){
	contents[r * width + col] = ch;
	return *this;
}

void Window_mgr::clear(ScreenIndex i){
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}