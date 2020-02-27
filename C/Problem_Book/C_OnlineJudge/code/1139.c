#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 5
int stack[SZ];
int top = -1;

void push(int _d);
void stackSum() {
	int sum = 0;
	for (int i = 0; i < SZ; i++) {
		sum += stack[i];
		stack[i] = 0;
	}
	top = -1; //top을 초기화를 안해주면 시작위치가 달라짐.
	push(sum);
}
void push(int _d) {
	if (top == SZ - 1) {
		return;
	}
	if (_d == 100) {
		stackSum();
		return;
	}
	top++;
	stack[top] = _d;
}
void pop() {
	if (top == -1) {
		return;
	}
	int result = stack[top];
	stack[top] = 0;
	top--;
	printf("%d ", result);
}

int main() {
	int n, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		push(d);
	}
	for (int i = 0; i < SZ; i++) { //top으로 설정하면 top이 변동됨
		pop();
	}
}