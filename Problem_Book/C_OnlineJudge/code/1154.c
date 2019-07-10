#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 10
char* que[SZ];
int front = 0, rear = 0;

int findSoldier(char* _name) {
	int find = 0;
	for (int i = 0; i < rear; i++) {
		if (*(que[i]) == *(_name)) {
			find = i;
			break;
		}
	}
	return find;
} 
void enque(char* _name) {
	if ((rear + 1) % SZ == front) {
		return;
	}
	que[rear] = (char*)malloc(sizeof(char) * 10);
	strcpy(que[rear], _name);
	rear = (rear + 1) % SZ;
}
void deque(int _find) {
	if (_find == 0);
	else if (_find == 1) {
		printf("%s ", que[_find - 1]);
	}
	else {
		printf("%s %s ", que[_find - 2], que[_find - 1]);
	}

	if (_find == rear - 1);
	else if (_find == rear - 2) {
		printf("%s", que[_find + 1]);
	}
	else {
		printf("%s %s", que[_find + 1], que[_find + 2]);
	}
}

int main() {
	int n;
	char name[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &name);
		enque(name);
	}
	scanf("%s", &name);
	int find = findSoldier(name);
	deque(find);
}