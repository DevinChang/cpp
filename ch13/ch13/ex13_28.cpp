#include "ex13_28.h"

TreeNode& TreeNode::operator= (const TreeNode &rhs) {
	++*rhs.count;
	if (--*count == 0) {
		delete count;
		delete left;
		delete right;
	}
	count = rhs.count;
	return *this;
}

TreeNode::~TreeNode(){
	if (--*count == 0) {
		delete count;
		delete left;
		delete right;
	}
}

BinStrTree& BinStrTree::operator= (const BinStrTree &bst) {
	auto nbst = new TreeNode(*bst.root);
	delete root;
	root = nbst;
	return *this;
}

BinStrTree::~BinStrTree() {
	delete root;
}