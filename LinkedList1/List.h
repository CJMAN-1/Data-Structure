#ifndef LIST_H
#define LIST_H
#include<iostream>
#define DATA char

class ListNode
{
public:
	DATA* data;
	ListNode* N_node;
	ListNode* P_node;

public:
	ListNode()
	{
		data = nullptr;
		N_node = nullptr;
		P_node = nullptr;
	}

	ListNode(DATA* data)
	{
		this -> data = data;
		N_node = nullptr;
		P_node = nullptr;
	}
};


class List
{
private:
	ListNode* m_Head;
	ListNode* m_Tail;
	int m_Nodecount;

public:
	List();
	~List();

	void push_front(DATA* data);
	void push_back(DATA* data);
	void pop_front();
	void pop_back();
	void insert(DATA* data, int index);
	void erase(int index);
	int count();
	ListNode* Head();
	ListNode* front();
	ListNode* back();

private:
	bool isEmpty();

};

#endif