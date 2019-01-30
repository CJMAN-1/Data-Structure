#include"calculator.h"

//bool Check_bracket(string* str, mStack* stack);

int main()
{
	CALCULATOR cal;
	cin >> cal.str;

	cal.Insert_innerstack();
	cal.Show_stack(&cal.cal_inner);


 	return 0;
}
/*
bool Check_bracket(string* str, mStack* stack)
{
	DATA temp;

	for (int i = 0; i < str->length(); i++) {
		temp = str->at(i);
		if (temp == '[' || temp == '{' || temp == '(') {
			stack->insert_top(temp);
		}

		else if (temp == (stack->peek()->data + 1) || temp == (stack->peek()->data + 2)) {
			stack->pop_top();
		}
	}

	return stack->isEmpty();
}
*/