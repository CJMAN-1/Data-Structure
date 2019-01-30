#include "Que_jb.h"

bool Que::isempty() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void Que::push(DATA data) {
	Node* ptr = new Node();
	ptr->data = data;

	if (isempty()) {
		head = ptr;
		tail = ptr;
	}
	else {
		tail->n_node = ptr;
		tail = ptr;
	}

	return;
}

DATA Que::pop() {
	if (isempty()) {
		cout << "큐가 비었습니다." << endl;
		return ' ';
	}

	temp = head;
	head = head->n_node;
	delete temp;
	
}