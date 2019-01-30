#ifndef __SORT_H__
#define __SORT_H__
#include<iostream>

#define DATA int
#define LEN 100000

using namespace std;

class Sort {
private:
	void inline Swap(DATA* data1, DATA* data2);
	DATA array_cp[LEN] = { 0, };
	int partition(DATA* data, int low, int high);

public:
	//1번 삽입정렬: 뒤에서 부터 비교해서 작으면 continue, 크면 break 삽입, 0까지가면 break 삽입/10만개 역방향 22,27초/ 순방향 1미리
	void InsertSort1(DATA* data);
	//2번 삽입정렬: 0번째 부터 비교해서 작으면 break, 크면 continue,/10만개 역방향 9.4초,순방향 12초
	void InsertSort2(DATA* data);
	//선택정렬: 최솟값을 찾아서 순서대로 대입 / 역방향 12초,순방향 11초 별차이 없음.
	void SelectionSort(DATA* data);
	//퀵정렬: 큰건 오른쪽 작은건 왼쪽으로 나눠서 정렬, 삽입하고 시간차이 엄청남.
	void QuickSort(DATA* data, int low, int high);
	void MergeSort(DATA* data, int low, int high);
	void conquer(DATA* data, int low, int high, int half);
};
#endif // !__SORT_H__
