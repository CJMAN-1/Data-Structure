#include <iostream>
#include "Sort.h"
#include <random>
#include <time.h>




int main()
{
	DATA data[LEN] = {};
	Sort sd;
	clock_t begin,end;

	srand((unsigned int)time(NULL));
	
	for (int i = LEN-1; i >= 0; i--) {
		data[LEN-1 - i] = rand()%100;
	}
	
//	for (int i = 0; i < LEN; i++) {
//		data[i] = i;
//	}

	/*
	begin = clock();
	sd.InsertSort1(data);
	end = clock();
	cout << "삽입 정렬:"<< 1000.0*(end - begin) / CLOCKS_PER_SEC << endl;


	for (int i = LEN - 1; i >= 0; i--) {
		data[LEN - 1 - i] = rand() % 100;

	}
	begin = clock();
	sd.SelectionSort(data);
	end = clock();
	cout<<"선택 정렬:" << 1000.0*(end - begin) / CLOCKS_PER_SEC << endl;
	*/

	begin = clock();
	sd.QuickSort(data,0,LEN -1);
	end = clock();
	cout <<"시바 퀵정렬:" <<1000.0*(end - begin) / CLOCKS_PER_SEC << endl;
	/*
	for (int i = LEN - 1; i >= 0; i--) {
		data[LEN - 1 - i] = rand() % 100;
	}
	begin = clock();
	sd.MergeSort(data, 0, LEN - 1);
	end = clock();
	cout << "합병 정렬:" << 1000.0*(end - begin) / CLOCKS_PER_SEC << endl;
	*/
	return 0;
}