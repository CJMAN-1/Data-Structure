/*#include"List.h"
#define INSERT 1
#define ERASE 2
#define EXIT 9

using namespace std;
int main()
{
	List unit;
	int mode = 0;
	ListNode* node = nullptr;
	int index = 0;
	while (1)
	{
		cout << "������ �����ϼ���" << endl;
		cout << "[1]��� �߰�" << endl << "[2]��� ����" << endl << "[9]����" << endl;
		cin >> mode;

		switch (mode) {
		case INSERT: {
			char* pNew = new char();
			cout << "������ �Է�" << endl;
			cin >> *pNew;
			cout << "�ε��� �Է�" << endl;
			cin >> index;
			unit.insert(pNew, index);
			break;
		}
		case ERASE: {
			cout << "�ε��� �Է�" << endl;
			cin >> index;
			unit.erase(index);
			break;
		}
		case EXIT: {
			cout << endl << endl;
			return 0;
		}
		}
		node = unit.Head();//������ N_node�� ��������� �߰�
		for (int i = 0; i < unit.count() - 1; i++) {
			node = node->N_node;
		}
		node->N_node = unit.Head();

		node = unit.Head();//��ºκ�
		for (int i = 0; i < unit.count(); i++) {
			cout << *(node->data);
			node = node->N_node;
		}
		cout << "[" << *(node->data) << "]";//������ ����� ���� ��� ������ ���
		cout << endl;
	}
	return 0;
}*/