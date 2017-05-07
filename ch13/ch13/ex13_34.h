#pragma once
#include <iostream>
#include <string>
#include <set>

class Message{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	Message(const std::string &str = "") : contents(str){}
	Message(const Message&);
	Message(Message &&);
	Message& operator= (const Message &);
	Message &operator= (Message &&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFdlr(Folder *);
	void remFdlr(Folder *);
	void move_folders(Message *);
};


class Folder {
	friend void swap(Folder &, Folder &);
public:
	Folder() = default;
	Folder(const Folder&);
	Folder &operator= (const Folder&);
	~Folder();
	void addMsg(Message *);
	void remMsg(Message *);
private:
	std::set<Message*> message;
	void add_to_Message(const Folder&);
	void remove_from_Message();
};

