#include <stdio.h>
int heap[1000];

void swap(int i, int j) {
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}
void findLocation(int cur_idx, int last_idx) {
	int left_idx = cur_idx * 2;
	int right_idx = left_idx + 1;
	int big = cur_idx;
	if (left_idx <= last_idx && heap[left_idx] > heap[cur_idx] && heap[left_idx] >heap[right_idx]) {
		big = left_idx;
	}
	if (right_idx <= last_idx && heap[right_idx] > heap[cur_idx] && heap[right_idx]> heap[left_idx]) {
		big = right_idx;
	}
	if (big == cur_idx) {
		return;
	}
	else {
		swap(big, cur_idx);
		findLocation(big, last_idx);
	}
}
void heapify(int last_idx) {
	int cur_idx = last_idx / 2;
	while (cur_idx != 0) {
		findLocation(cur_idx, last_idx);
		cur_idx--;
	}
}
void addToHeap(int _v, int last_idx) {
	int cur_idx = last_idx + 1;
	heap[cur_idx] = _v;
	int p_idx = cur_idx / 2;
	heapify(cur_idx);
}
int removeRoot(int last_idx) {
	int retVal = heap[1];
	heap[1] = heap[last_idx];
	heapify(last_idx);
	return retVal;
}
void printAll(int last_idx) {
	for (int i = 1; i <= last_idx; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");
}
int main() {
	int num, val;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) 	{
		scanf("%d", &val);
		addToHeap(val, i);
	}
	printAll(num);
	for (int i = num; i > 0; i--)
	{
		printf("%d ", removeRoot(i));
	}
}