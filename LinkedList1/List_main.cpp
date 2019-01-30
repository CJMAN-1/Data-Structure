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
		cout << "동작을 선택하세요" << endl;
		cout << "[1]삽입" << endl <<"[2]앞에 추가"<<endl << "[3]뒤에 추가" << endl << "[4]노드 제거" << endl 
			 << "[5]앞에 노드 제거" << endl << "[6]뒤에 노드 제거" << endl <<"[9]종료"<<endl;
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
			case PUSHFRONT: {
				char* pNew = new char;
				cout << "데이터 입력" << endl;
				cin >> *pNew;
				unit.push_front(pNew);
				break;
			}
			case PUSHBACK: {
				char* pNew = new char;
				cout << "데이터 입력" << endl;
				cin >> *pNew;
				unit.push_back(pNew);
				break;
			}
			case ERASE: {
				cout << "인덱스 입력" << endl;
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


		node = unit.front();//출력부분
		cout << "헤드부터 출력 :";
		for (int i = 0; i < unit.count(); i++) {		
			cout << *(node->data);
			node = node->N_node;
		}

		cout << endl << "꼬리부터 출력 :";//출력부분
		node = unit.back();
		for (int i = 0; i < unit.count(); i++) {
			cout << *(node->data);
			node = node->P_node;
		}
		cout << endl;

	}
	return 0;
}