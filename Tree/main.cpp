#include "Tree.h"

int main()
{
	DATA arr[7] = { 10,5,15,3,7,13,17 };

	BST ss;

	for (int i = 0; i < 7; i++) {
		ss.Insert(arr[i]);
	}

	return 0;
}