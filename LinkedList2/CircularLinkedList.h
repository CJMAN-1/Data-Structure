#ifndef __CIRCULARLINKEDLIST_H__
#define __CIRCULARLINKEDLIST_H__
#include "Common_Decl.h"
#include "Node.h"

class Circular_Linked_List {
	List_Node* tail;
	int listNum;
public:
	Circular_Linked_List() :tail(nullptr),listNum(0){}

	void push_tail(DATA data);
	void push_head(DATA data);
	void insert_next(DATA search_data, DATA insert_data);
	void insert_before(DATA search_data, DATA insert_data);

	void pop_head();
	void pop_tail();


	bool is_empty();
	void show_all();
};
#endif