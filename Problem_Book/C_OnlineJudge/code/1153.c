#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 10
char* que[SZ];
int front = 0, rear = 0;

void enque(char* _name) {
	if ((rear + 1) % SZ == front) {
		return;
	}
	que[rear] = (char*)malloc(sizeof(strlen(_name) + 1));
	strcpy(que[rear], _name);
	rear = (rear + 1) % SZ;
}
void deque() {
	if (rear == front) {
		return;
	}
	printf("%s\n", que[front]);
	front = (front + 1) % SZ;
}

int main() {
	int n;
	char name[10];
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) {
		scanf("%s", name);
		enque(name);
	}
	for (int i = 3; i < n; i++) {
		scanf("%s", name);
		if (que[front][0] <= name[0]) {
			enque(name);
			deque();
		}
	}
}
