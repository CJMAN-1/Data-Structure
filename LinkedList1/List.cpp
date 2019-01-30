#include "List.h"
using namespace std;

List::List()
{
	m_Head = nullptr;
	m_Nodecount = 0;
	cout << "����Ʈ ���� �Ϸ�" << endl;
	
}
List::~List()
{
	cout << "����Ʈ �Ҹ� �Ϸ�" << endl;
}
void List::push_front(DATA* data)
{
	ListNode* pNew = new ListNode();
	pNew->data = data;
	pNew->N_node = nullptr;

	if (isEmpty())//ó�� ������
	{
		m_Head = pNew;
		m_Tail = pNew;
	}
	else//ó���� �ƴҶ�
	{
		pNew->N_node = m_Head;
		pNew->N_node->P_node = pNew;
		m_Head = pNew;
	}
	m_Nodecount++;//��� ���� ī��Ʈ
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
		cout << "�����Ͱ� �����ϴ�";
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

void List::insert(DATA* data, int index)//���� �ε����� �ϳ� �� ����Ʈ�� ����Ű���ϰ� ����
{
	if (index > m_Nodecount || index < 0) {
		cout << "�����ε����� 0�̰� ���� ������ �ε�����" << m_Nodecount << "�Դϴ�" << endl;
		return;
	}

	ListNode* pNew = new ListNode();
	ListNode* pNode = nullptr;
	
	pNew->data = data;

	if (index == 0) {//�ε��� 0���� ���
		pNew->N_node = m_Head;
		m_Head = pNew;
	}
	else {//�ε����� 0�� �ƴҰ��
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

void List::erase(int index)//�ǵڿ��ε����� �׾տ� �ε����� �����ϸ� ����
{
	
	if (index > m_Nodecount || index < 0) {
		cout << "�����ε����� 0�̰� ���� ������ �ε�����" << m_Nodecount << "�Դϴ�" << endl;
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
bool List::isEmpty()//ó�� ������°�?
{
	if (m_Head == nullptr)
		return true;
	else
		return false;
}
