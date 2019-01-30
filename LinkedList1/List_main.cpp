#include"List.h"
#define INSERT 1
#define PUSHFRONT 2
#define PUSHBACK 3
#define ERASE 4
#define POPFRONT 5
#define POPBACK 6
#define EXIT 9

using namespace std;
int main()
{
	List unit;
	int mode = 0;
	ListNode* node = nullptr;
	int index = 0;

	for (char i = 0; i < 5; i++) {
		char* pNew = new char();
		*pNew = i+49;
		unit.push_back(pNew);
	}

	while (1)
	{
		cout << "������ �����ϼ���" << endl;
		cout << "[1]����" << endl <<"[2]�տ� �߰�"<<endl << "[3]�ڿ� �߰�" << endl << "[4]��� ����" << endl 
			 << "[5]�տ� ��� ����" << endl << "[6]�ڿ� ��� ����" << endl <<"[9]����"<<endl;
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
			case PUSHFRONT: {
				char* pNew = new char;
				cout << "������ �Է�" << endl;
				cin >> *pNew;
				unit.push_front(pNew);
				break;
			}
			case PUSHBACK: {
				char* pNew = new char;
				cout << "������ �Է�" << endl;
				cin >> *pNew;
				unit.push_back(pNew);
				break;
			}
			case ERASE: {
				cout << "�ε��� �Է�" << endl;
				cin >> index;
				unit.erase(index);
				break;
			}
			case POPFRONT: {
				unit.pop_front();
				break;
			}
			case POPBACK: {
				unit.pop_back();
				break;
			}
			case EXIT: {
				cout << endl << endl;
				return 0;
			}
		}


		node = unit.front();//��ºκ�
		cout << "������ ��� :";
		for (int i = 0; i < unit.count(); i++) {		
			cout << *(node->data);
			node = node->N_node;
		}

		cout << endl << "�������� ��� :";//��ºκ�
		node = unit.back();
		for (int i = 0; i < unit.count(); i++) {
			cout << *(node->data);
			node = node->P_node;
		}
		cout << endl;

	}
	return 0;
}