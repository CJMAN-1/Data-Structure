#include"stack.h"
/*//위에 넣는 함수, 위에 빼는 함수, 길이 재는 함수, 꼭대기 확인만 하는 함수 비어있는 지 확인
*/
mStack::mStack() {
	m_top=nullptr;
	T_node=nullptr;
	node_count = 0;
}

mStack::~mStack() {
}

void mStack::insert_top(DATA data) {
	StackNode* Pnew = new StackNode();
	Pnew->data = data;

	Pnew->P_node = m_top;
	m_top = Pnew;
	node_count++;

	return;
}


DATA mStack::pop_top() {
	if (!isEmpty()) {
		T_node = m_top;
		m_top = m_top->P_node;
		T_node->P_node = nullptr;

		node_count--;

		return T_node->data;
	}
	else {
		cout << "There isn't data" << endl;
		Position s;
		return s;
	}
}

bool mStack::isEmpty() {
	if (m_top == nullptr)
		return true;

	else  
		return false;
}

int mStack::length() {
	int length = 0;

	if (!isEmpty()) {
		T_node = m_top;

		while (T_node->P_node != nullptr) {
			T_node = T_node->P_node;
			length++;
		}

		return length;
	}
		
	return length;
}

StackNode* mStack::peek() {
	return m_top;
}