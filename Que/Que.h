#include "iostream"
#define DATA char

using namespace std;
class Node {
public:
	DATA data;
	Node* n_node;

	Node() :data(0), n_node (nullptr) {	}
};

class Que {
public:
	Node* head;
	Node* tail;
	Node* temp;
	
	Que() : head(nullptr), tail(nullptr) {}

	bool isempty();
	void push(DATA data);
	DATA pop();
};