#pragma once
#include <iostream>
#include <string>



class TreeNode {
public:
	TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr){}
	TreeNode(const TreeNode&td) : value(td.value), count(td.count), left(td.left), right(td.right) { ++count; }
	TreeNode& operator= (const TreeNode &);
	~TreeNode();
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};


class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()){}
	BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)){}
	BinStrTree& operator= (const BinStrTree &);
	~BinStrTree();
private:
	TreeNode *root;
};