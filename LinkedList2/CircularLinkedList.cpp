#include "CircularLinkedList.h"


void Circular_Linked_List::show_all() {
	if (is_empty()) {
		cout << "리스트가 비어있습니다." << endl << endl;
		return;
	}

	List_Node* ptr = tail->n_Node;
	do{
		cout << ptr->data << "  ";
		ptr = ptr->n_Node;
	}while (ptr != tail->n_Node);
	cout << endl << endl;

	return;
}
bool Circular_Linked_List::is_empty() {
	if (tail == nullptr) {
		return true;
	}

	return false;
}


void Circular_Linked_List::push_tail(DATA data){
	List_Node* node= new List_Node(data);
	
	if (is_empty()) {
		tail = node;
		node->n_Node = node;
		listNum++;
		return;
	}
	node->n_Node = tail->n_Node;
	tail->n_Node = node;
	tail = node;
	listNum++;
	return;
}
void Circular_Linked_List::push_head(DATA data) {
	List_Node* node = new List_Node(data);

	if (is_empty()) {
		tail = node;
		node->n_Node = node;
		listNum++;
		return;
	}
	node->n_Node = tail->n_Node;
	tail->n_Node = node;
	listNum++;
	return;
}
void Circular_Linked_List::insert_next(DATA search_data, DATA insert_data){
	if (is_empty()) {
		cout << "리스트가 비어있습니다." << endl << endl;
		return;
	}

	List_Node* ptr = tail->n_Node;
	do {
		if (ptr->data == search_data) {
			List_Node* node = new List_Node;
			node->data = insert_data;

			node->n_Node = ptr->n_Node;
			ptr->n_Node = node;
			
			if (ptr == tail)
				tail = node;
			return;
		}
		ptr = ptr->n_Node;
	} while (ptr != tail->n_Node);

	cout << "입력하신 데이터가 존재하지 않습니다." << endl << endl;
	return;
}
void Circular_Linked_List::insert_before(DATA search_data, DATA insert_data){
	if (is_empty()) {
		cout << "리스트가 비어있습니다." << endl << endl;
		return;
	}

	List_Node* ptr = tail->n_Node;
	do {
		if (ptr->n_Node->data == search_data) {
			List_Node* node = new List_Node;
			node->data = insert_data;

			node->n_Node = ptr->n_Node;
			ptr->n_Node = node;

			return;
		}
		ptr = ptr->n_Node;
	} while (ptr != tail->n_Node);

	cout << "입력하신 데이터가 존재하지 않습니다." << endl << endl;
	return;
}


void Circular_Linked_List::pop_head(){
	if (is_empty()) {
		cout << "리스트가 비어있습니다." << endl << endl;
		return;
	}

	else if (tail == tail->n_Node) {
		delete tail;
		tail = nullptr;
		listNum--;
		return;
	}
	List_Node* ptr;
	ptr = tail->n_Node;
	tail->n_Node = ptr->n_Node;
	listNum--;
	delete ptr;
	
	return;
}
void Circular_Linked_List::pop_tail(){
	if (is_empty()) {
		cout << "리스트가 비어있습니다." << endl << endl;
		return;
	}

	else if (tail == tail->n_Node) {
		delete tail;
		tail = nullptr;
		listNum--;
		return;
	}

	List_Node* ptr = tail;
	for (int i = 0; i < listNum-1; i++) {
		ptr = ptr->n_Node;
	}
	ptr->n_Node = tail->n_Node;
	listNum--;
	delete tail;
	tail = ptr;

	return;
}