#include <stdio.h>
#define SZ 7
int que[SZ];
int rear = 0, front = 0;

void enque(int _d);
void sumQue() {
	int sum = 0;
	for (int i = 0; i < SZ; i++) {
		sum += que[i];
		que[i] = 0;
	}
	rear = front = 0;
	enque(sum);
}
void enque(int _d) {
	if ((rear + 1) % SZ == front) {
		return;
	}
	if (_d == 100) {
		sumQue();
		return;
	}
	que[rear] = _d;
	rear = (rear + 1) % SZ;
}
void deque() {
	if (rear == front) {
		return;
	}
	printf("%d ", que[front]);
	front = (front + 1) % SZ;
}

int main() {
	int n, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		enque(d);
	}
	for (int i = 0; i < n; i++){
		deque();
	}
}