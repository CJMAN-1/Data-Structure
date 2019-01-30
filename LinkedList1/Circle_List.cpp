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
		cout << "동작을 선택하세요" << endl;
		cout << "[1]노드 추가" << endl << "[2]노드 제거" << endl << "[9]종료" << endl;
		cin >> mode;

		switch (mode) {
		case INSERT: {
			char* pNew = new char();
			cout << "데이터 입력" << endl;
			cin >> *pNew;
			cout << "인덱스 입력" << endl;
			cin >> index;
			unit.insert(pNew, index);
			break;
		}
		case ERASE: {
			cout << "인덱스 입력" << endl;
			cin >> index;
			unit.erase(index);
			break;
		}
		case EXIT: {
			cout << endl << endl;
			return 0;
		}
		}
		node = unit.Head();//마지막 N_node에 헤드포인터 추가
		for (int i = 0; i < unit.count() - 1; i++) {
			node = node->N_node;
		}
		node->N_node = unit.Head();

		node = unit.Head();//출력부분
		for (int i = 0; i < unit.count(); i++) {
			cout << *(node->data);
			node = node->N_node;
		}
		cout << "[" << *(node->data) << "]";//마지막 노드의 다음 노드 데이터 출력
		cout << endl;
	}
	return 0;
}*/