#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 5
int que[SZ];
int front = 0, rear = 0;

void enque(int _d) {
	if ((rear + 1) % SZ == front) {
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
	for (int i = 0; i < n; i++) {
		deque();
	}
}