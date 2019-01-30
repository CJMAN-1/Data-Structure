#include "calculator.h"
int CALCULATOR::Stoi(string str, int* index) {
	int result = 0;
	int cipher = 0;
	int weight = 1;
	int start = 0;

	while (str[*index] >= 48 && str[*index] <= 57) {
		cipher++;
		(*index)++;
	}
	start =--(*index);
	while (cipher > 0) {
		result += (str[start] - 48) * weight;
		
		weight *= 10;
		start--;
		cipher--;
	}

	return  result;
}

void CALCULATOR::Insert_innerstack() {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 48 && str[i] <= 57) {//숫자를 스택에 추가
			num = Stoi(str, &i);
			cal_inner.insert_top(num);
			
		}
		else if (str[i] == 42 || str[i] == 43 || str[i] == 45 || str[i] == 47) {//*+-/순서연산 기호 스택에 추가
			symbol = str[i];
			cal_inner.insert_top(symbol);
		}

	}

	return;
}

void CALCULATOR::Show_stack(mStack* stack) {

	T_node = stack->peek();

	while (T_node != nullptr) {
		if (T_node->data_type == INT)
			cout << T_node->data_int << ' ';

		else if (T_node->data_type == CHAR)
			cout << T_node->data << ' ';
		
		T_node = T_node->P_node;
	}

	return;
}