#ifndef __NODE_H__
#define __NODE_H__

#include "Common_Decl.h"
#define DATA int


class List_Node {
public:
	DATA data;
	List_Node* n_Node;
	List_Node* p_Node;
public:
	List_Node() :data(0), n_Node(nullptr), p_Node(nullptr) {}
	List_Node(DATA data) : data(data), n_Node(nullptr), p_Node(nullptr) {}
	List_Node(DATA data, List_Node* n_Node, List_Node* p_Node) :data(data), n_Node(n_Node), p_Node(p_Node) {}
};

#endif