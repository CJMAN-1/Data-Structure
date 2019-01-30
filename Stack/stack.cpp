#include"stack.h"
/*//���� �ִ� �Լ�, ���� ���� �Լ�, ���� ��� �Լ�, ����� Ȯ�θ� �ϴ� �Լ� ����ִ� �� Ȯ��
*/
mStack::mStack() {
	m_top=nullptr;
	T_node=nullptr;
	node_count = 0;
	cout << "���� ������ ���� �Ϸ�" << endl;
}

mStack::~mStack() {
	cout << "���� ������ �Ҹ� �Ϸ�" << endl;
}

void mStack::insert_top(DATA data) {
	StackNode* Pnew = new StackNode();
	Pnew->data = data;
	Pnew->data_type = CHAR;

	Pnew->P_node = m_top;
	m_top = Pnew;
	node_count++;

	return;
}
void mStack::insert_top(int data_int) {
	StackNode* Pnew = new StackNode();
	Pnew->data_int = data_int;
	Pnew->data_type = INT;

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
		return 0;
	}
}
int mStack::pop_topint() {
	if (!isEmpty()) {
		T_node = m_top;
		m_top = m_top->P_node;
		T_node->P_node = nullptr;

		node_count--;

		return T_node->data_int;
	}
	else {
		cout << "There isn't data" << endl;
		return 0;
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