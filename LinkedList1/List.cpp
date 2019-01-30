#include "List.h"
using namespace std;

List::List()
{
	m_Head = nullptr;
	m_Nodecount = 0;
	cout << "리스트 생성 완료" << endl;
	
}
List::~List()
{
	cout << "리스트 소멸 완료" << endl;
}
void List::push_front(DATA* data)
{
	ListNode* pNew = new ListNode();
	pNew->data = data;
	pNew->N_node = nullptr;

	if (isEmpty())//처음 넣을때
	{
		m_Head = pNew;
		m_Tail = pNew;
	}
	else//처음이 아닐때
	{
		pNew->N_node = m_Head;
		pNew->N_node->P_node = pNew;
		m_Head = pNew;
	}
	m_Nodecount++;//노드 갯수 카운트
}

void List::push_back(DATA* data)
{
	ListNode* pNew = new ListNode();
	ListNode* pNode = nullptr;

	pNew->data = data;
	pNew->N_node = nullptr;

	if (isEmpty()) {
		m_Head = pNew;
		m_Tail = pNew;
	}
		
	else
	{
		pNode = m_Head;
		while (pNode->N_node != nullptr)
			pNode = pNode->N_node;

		pNode->N_node = pNew;
		pNew->P_node = pNode;
		m_Tail = pNew;
	}
	m_Nodecount++;
}

ListNode* List::front()
{
	ListNode* pReturn = nullptr;

	if (!isEmpty())
		pReturn = m_Head;

	return pReturn;
}

ListNode* List::back()
{
	ListNode* pReturn = nullptr;
	ListNode* pNode = nullptr;

	if (!isEmpty())
	{
		pNode = m_Head;
		while (pNode->N_node != nullptr)
			pNode = pNode->N_node;
		pReturn = pNode;
	}
	return pReturn;
}

void List::pop_front()
{
	ListNode* pDel = nullptr;

	if (!isEmpty())
	{
		pDel = m_Head;
		m_Head = m_Head->N_node;
		pDel->N_node->P_node = nullptr;
		pDel->N_node = nullptr;
		m_Nodecount--;
	}
	else
		cout << "데이터가 없습니다";
	return;
}

void List::pop_back()
{
	ListNode* pPredel = nullptr;

	if (!isEmpty())
	{
		pPredel = m_Head;

		for (int i = 0; i < m_Nodecount - 2; ++i)
			pPredel = pPredel->N_node;

		m_Tail = pPredel->N_node->P_node;
		pPredel->N_node->P_node = nullptr;
		pPredel->N_node = nullptr;
		m_Nodecount--;
	}
	return;
}

void List::insert(DATA* data, int index)//받은 인덱스의 하나 앞 리스트를 가리키게하고 삽입
{
	if (index > m_Nodecount || index < 0) {
		cout << "시작인덱스는 0이고 현재 마지막 인덱스는" << m_Nodecount << "입니다" << endl;
		return;
	}

	ListNode* pNew = new ListNode();
	ListNode* pNode = nullptr;
	
	pNew->data = data;

	if (index == 0) {//인덱스 0번일 경우
		pNew->N_node = m_Head;
		m_Head = pNew;
	}
	else {//인덱스가 0이 아닐경우
		pNode = m_Head;
		for (int i = 0; i < index - 1; i++) {
			pNode = pNode->N_node;

		}
		pNew->N_node = pNode->N_node;
		pNode->N_node = pNew;
	}

	m_Nodecount++;

	return;
}

void List::erase(int index)//맨뒤에인덱스와 그앞에 인덱스는 삭제하면 오류
{
	
	if (index > m_Nodecount || index < 0) {
		cout << "시작인덱스는 0이고 현재 마지막 인덱스는" << m_Nodecount << "입니다" << endl;
		return;
	}

	ListNode* pNode = nullptr;
	ListNode* temp = m_Head;

	if (index > 1) {
		pNode = m_Head;
		for (int i = 0; i < index - 2; i++) {
			pNode = pNode->N_node;
		}
		pNode->N_node = pNode->N_node->N_node;
		pNode->N_node->N_node=nullptr;
	}

	else if (index == 0) {
		m_Head = m_Head->N_node;
		temp->N_node=nullptr;
	}

	else if (index == 1) {
		m_Head->N_node = m_Head->N_node->N_node;
		m_Head->N_node->N_node = nullptr;
	}
	m_Nodecount--;
}

int List::count()
{
	return m_Nodecount;
}

ListNode* List::Head()
{
	return m_Head;
}
bool List::isEmpty()//처음 만들었는가?
{
	if (m_Head == nullptr)
		return true;
	else
		return false;
}
