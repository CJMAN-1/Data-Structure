#include <iostream>

#define DATA int
using namespace std;


class TreeNode {
public:
	DATA data;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;

	TreeNode();
	TreeNode(DATA data);

	friend class BST;
};

class BST {
	TreeNode* parent;
	TreeNode* temp;
public:
	void Insert (DATA data);
	void ShowInorder(TreeNode* temp);

	BST();
};