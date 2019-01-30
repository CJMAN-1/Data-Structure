#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include "Common_Decl.h"
#include "Node.h"

class Doubly_Linked_List {
private:
	List_Node* head;
	List_Node* tail;
public:
	Doubly_Linked_List() :head(nullptr),tail(nullptr){}

	void push_front(DATA data);
	void push_rear(DATA data);
	void insert_next(DATA search_data ,DATA insert_data);
	void insert_before(DATA search_data, DATA insert_data);
	void pop_front();
	void pop_rear();
	
	
	bool is_empty();
	void show_all();
};
#endif