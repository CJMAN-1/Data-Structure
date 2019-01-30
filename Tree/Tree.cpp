#include "Tree.h"

TreeNode::TreeNode() :data(NULL), parent(nullptr), left(nullptr), right(nullptr){

}

TreeNode::TreeNode(DATA data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {

}
BST::BST() : parent(nullptr) {

}

void BST::Insert (DATA data) {
	if (parent == nullptr) {
		parent = new TreeNode(data);

		return;
	}

	TreeNode* new_node = new TreeNode(data);
	temp = parent;
	
	while (1) {
		if (data < temp->data) {
			if (temp->left != nullptr) {
				temp = temp->left;
			}
			else {
				new_node->parent = temp;
				temp->left = new_node;
				break;
			}
		}
		else {
			if (temp->right != nullptr) {

				temp = temp->right;
			}
			else {
				new_node->parent = temp;
				temp->right = new_node;
				break;
			}
		}
	}
	


	return;
}

void BST::ShowInorder(TreeNode* temp) {

	
}