#include <iostream>
#define DATA Position
using namespace std;

class Position {
public:
	int x;
	int y;
	Position() :x(0),y(0) { };
	Position(int x, int y) :x(x), y(y) {};

};

class StackNode {
public:
	DATA data;

	StackNode* P_node;
};

class mStack {

	StackNode* m_top;
	StackNode* T_node;
	int node_count;

public:
	mStack();
	~mStack();

	void insert_top(DATA data);
	DATA pop_top();
	bool isEmpty();
	int mStack::length();
	StackNode* peek();
};

