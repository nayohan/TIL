
#include <stdio.h>
#include <stdlib.h>
#define DATA_SZ 10

void swap(int* data, int a, int b) {
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

//거품정렬(Bubble Sort)
void PerformBubbleSort(int* toBeSorted, int sz) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz - 1 - i; j++) {
			if (toBeSorted[j] > toBeSorted[j + 1]) {
				swap(toBeSorted, j, j + 1);
			}
		}
	}
}

//선택정렬(Selection Sort)
int findSmallest(int* toBeSorted, int start_idx, int sz) {
	int smallest = toBeSorted[start_idx];
	int idx = start_idx;
	for (int i = start_idx; i < sz; i++) {
		if (toBeSorted[i] < smallest) {
			smallest = toBeSorted[i];
			idx = i;
		}
	}
	return idx;
}
void PerformSelectionSort(int* toBeSorted, int sz) {
	for (int i = 0; i < sz; i++) {
		int idx = findSmallest(toBeSorted, i, sz);
		swap(toBeSorted, i, idx);
	}
}

//삽입정렬(Insertion Sort)
void PerformInsertionSort(int* toBeSorted, int sz) {
	for (int i = 0; i < sz; i++) {
		for (int j = i; j < sz; j++)
		{
			if (toBeSorted[i] > toBeSorted[j]) {
				swap(toBeSorted, i, j);
			}
		}
	}
}

void printAll(int* toBeSorted, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", toBeSorted[i]);
	}
	printf("\n");
}

int main() {
	int data[DATA_SZ] = { 3, 1, 2, 10, 9, 6, 8, 4, 7, 5 };
	printAll(data, DATA_SZ);
	//PerformBubbleSort(data, DATA_SZ);
	//PerformSelectionSort(data, DATA_SZ);
	PerformInsertionSort(data, DATA_SZ);
	printAll(data, DATA_SZ);
}