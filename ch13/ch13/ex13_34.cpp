#include "ex13_34.h"




Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}

Message::Message(Message &&m) : contents(std::move(m.contents)){
	move_folders(&m);
}

Message & Message::operator=(const Message &rhs){
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message & Message::operator=(Message &&rhs)
{
	if (this != &rhs) {
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_folders(&rhs);
	}
	return *this;
}

Message::~Message(){
	remove_from_Folders();
}

void Message::save(Folder &f){
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f){
	folders.erase(&f);
	f.remMsg(this);
}

void swap(Message &lhs, Message &rhs){
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);

}

void swap(Folder &lhs, Folder &rhs){
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();
	swap(lhs.message, rhs.message);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

void Message::add_to_Folders(const Message &m){
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders(){
	for (auto f : folders)
		f->remMsg(this);
}

void Message::addFdlr(Folder *f){
	folders.insert(f);
}

void Message::remFdlr(Folder *f){
	folders.erase(f);
}

void Message::move_folders(Message *m){
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Folder::Folder(const Folder &f) : message(f.message){
	add_to_Message(f);
}

Folder & Folder::operator=(const Folder &f){
	remove_from_Message();
	message = f.message;
	add_to_Message(f);
	return *this;
}

Folder::~Folder(){
	remove_from_Message();
}

void Folder::addMsg(Message *m){
	message.insert(m);
}

void Folder::remMsg(Message *m){
	message.erase(m);
}

void Folder::add_to_Message(const Folder &f){
	for (auto m : f.message)
		m->addFdlr(this);
}

void Folder::remove_from_Message(){
	for (auto m : message)
		m->remFdlr(this);
}
