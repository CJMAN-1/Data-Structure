#include "Sort.h"
inline void Sort::Swap(DATA* data1, DATA* data2) {
	DATA temp = *data1;
	*data1 = *data2;
	*data2 = temp;

	return;
}


void Sort::InsertSort1(DATA* data) {
	DATA temp = 0;
	for (int i = 1; i < LEN; i++) {
		temp = data[i];
		for (int j = i - 1; j >= 0; j--) {
			if (data[i] > data[j]) {
				for (int k = i; k > j + 1; k--) {
					data[k] = data[k - 1];
				}
				data[j + 1] = temp;
				break;
			}
			else if (j == 0) {
				for (int k = i; k > j; k--) {
					data[k] = data[k - 1];
				}
				data[0] = temp;
			}
			else {
				continue;
			}
		}
	}
	return;
}


void Sort::InsertSort2(DATA* data) {
	DATA temp = 0;

	for (int i = 0; i < LEN; i++) {
		temp = data[i];
		for (int j = 0; j < i; j++) {
			if (data[i] < data[j]) {
				for (int k = i; k > j; k--) {
					data[k] = data[k - 1];
				}
				data[j] = temp;
				break;
			}

			else {
				continue;
			}
		}
	}

	return;
}


void Sort::SelectionSort(DATA* data) {
	int min = LEN-1;
	for (int i = 0; i < LEN-1; i++) {
		for (int j = i; j < LEN; j++) {
			if (data[j] < data[min]) {
				min = j;
			}
		}

		Swap(&data[i], &data[min]);
	}

	return;
}


int Sort::partition(DATA* data, int low, int high) {
	int newpivot = low;
	
	while (low < high) {
		while (data[newpivot] >= data[low]) {
			low++;
		}

		while (data[newpivot] < data[high]) {
			high--;
		}
		if(low < high)
			Swap(&data[low], &data[high]);
	}
	Swap(&data[newpivot], &data[high]);

	return high;
}


void Sort::QuickSort(DATA* data, int low, int high) {
	if (low >= high) {
		return;
	}

	int pivot = partition(data,low,high);

	QuickSort(data, low, pivot - 1);
	QuickSort(data, pivot + 1, high);
}

void Sort::MergeSort(DATA* data, int low, int high) {
	int half = (high - low + 1) / 2;

	if (high - low > 1) {
		MergeSort(data, low, low + half - 1);
		MergeSort(data, low + half, high);
	}

	conquer(data, low, high, half);

	return;
}

void Sort::conquer(DATA* data, int low, int high, int half) {
	int lowvalue = low;
	int highvalue = high;
	int index = half + low;
	int i = low;
	while (low < lowvalue + half && index <= high) {
		if (data[low] <= data[index]) {
			array_cp[i] = data[low];
			i++;
			low++;
		}

		else {
			array_cp[i] = data[index];
			i++;
			index++;
		}
	}

	while (index <= high) {
		array_cp[i] = data[index];
		i++;
		index++;
	}
	while (low < lowvalue + half) {
		array_cp[i] = data[low];
		i++;
		low++;
	}
	for (int i = lowvalue; i <= highvalue; i++) {
		data[i] = array_cp[i];
	}

	return;
}