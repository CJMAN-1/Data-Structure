#pragma once
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class CALCULATOR {
	
public:
	string str;
	int num = 0;
	char  symbol = 0;

	mStack cal_inner;
	mStack cal_out;
	StackNode* T_node;

public:
	int Stoi(string str, int* index);
	string Getstr() { return str; }
	void Insert_innerstack();
	void Show_stack(mStack* stack);
};
