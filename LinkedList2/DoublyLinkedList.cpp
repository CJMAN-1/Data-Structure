#include "DoublyLinkedList.h"

void Doubly_Linked_List::show_all() {
	List_Node* ptr = head;
	
	if (is_empty()) {
		cout << "리스트가 비어있습니다." << endl << endl;
		return;
	}
	
	while (ptr != nullptr) {
		cout << ptr->data << "  ";
		ptr = ptr->n_Node;
	}
	cout << endl << endl;

	return;
}

bool Doubly_Linked_List::is_empty() {
	if (head == nullptr & tail == nullptr) {
		return true;
	}
	
	return false;
}

void Doubly_Linked_List::push_front(DATA data) {
	List_Node* node = new List_Node(data);

	if (is_empty()) {
		head = node;
		tail = node;
		return;
	}

	node->n_Node = head;
	head->p_Node = node;
	head = node;
	return;
}
void Doubly_Linked_List::push_rear(DATA data) {
	List_Node* node = new List_Node(data);

	if (is_empty()) {
		head = node;
		tail = node;
		return;
	}
	
	node->p_Node = tail;
	tail->n_Node = node; 
	tail = node;
	return;
}
void Doubly_Linked_List::insert_next(DATA search_data, DATA insert_data) {
	List_Node* ptr = head;

	while (ptr != nullptr) {
		if (ptr->data == search_data) {
			List_Node* node = new List_Node;
			node->data = insert_data;

			if (ptr == tail) {
				ptr->n_Node = node;
				node->p_Node = ptr;
				tail = node;
			}

			else {
				node->n_Node = ptr->n_Node;
				node->p_Node = ptr;
				ptr->n_Node = node;
				node->n_Node->p_Node = node;
			}
			return;
		}
		ptr = ptr->n_Node;
	}
	cout << "입력하신 데이터가 존재하지 않습니다." << endl << endl;
	return;
}

void Doubly_Linked_List::insert_before(DATA search_data, DATA insert_data) {
	List_Node* ptr = head;

	while (ptr != nullptr) {
		if (ptr->data == search_data) {
			List_Node* node = new List_Node;
			node->data = insert_data;

			if (ptr == head) {
				ptr->p_Node = node;
				node->n_Node = ptr;
				head = node;
			}

			else {
				node->p_Node = ptr->p_Node;
				node->n_Node = ptr;
				ptr->p_Node = node;
				node->p_Node->n_Node = node;
			}
		return;
	}
	ptr = ptr->n_Node;
}
cout << "입력하신 데이터가 존재하지 않습니다." << endl << endl;
return;
}

void Doubly_Linked_List::pop_front() {
	if (is_empty()) {
		cout << "리스트가 비어있습니다." << endl << endl;
		return;
	}

	else if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		
		return;
	}

	head = head->n_Node;
	delete head->n_Node;
	head->p_Node = nullptr;

	return;
}
void Doubly_Linked_List::pop_rear() {
	if (is_empty()) {
		cout << "리스트가 비어있습니다." << endl << endl;
		return;
	}

	else if (head == tail) {
		delete tail;
		head = nullptr;
		tail = nullptr;
		
		return;
	}
	tail = tail->p_Node;
	delete tail->n_Node;
	tail->n_Node = nullptr;
	
	return;
}