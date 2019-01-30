#include <iostream>
#define DATA char
#define CHAR 0
#define INT 1
using namespace std;
class StackNode {
public:
	DATA data;
	int data_int;
	int data_type;

	StackNode* P_node=nullptr;
};

class mStack {

	StackNode* m_top;
	StackNode* T_node;
	int node_count;

public:
	mStack();
	~mStack();

	void insert_top(DATA data);
	void insert_top(int data);
	DATA pop_top();
	int pop_topint();
	bool isEmpty();
	int mStack::length();
	StackNode* peek();
};

