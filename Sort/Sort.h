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
	//1�� ��������: �ڿ��� ���� ���ؼ� ������ continue, ũ�� break ����, 0�������� break ����/10���� ������ 22,27��/ ������ 1�̸�
	void InsertSort1(DATA* data);
	//2�� ��������: 0��° ���� ���ؼ� ������ break, ũ�� continue,/10���� ������ 9.4��,������ 12��
	void InsertSort2(DATA* data);
	//��������: �ּڰ��� ã�Ƽ� ������� ���� / ������ 12��,������ 11�� ������ ����.
	void SelectionSort(DATA* data);
	//������: ū�� ������ ������ �������� ������ ����, �����ϰ� �ð����� ��û��.
	void QuickSort(DATA* data, int low, int high);
	void MergeSort(DATA* data, int low, int high);
	void conquer(DATA* data, int low, int high, int half);
};
#endif // !__SORT_H__
