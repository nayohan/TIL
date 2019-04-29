#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 5
int stack[SZ];
int top = -1;

void push(int _d) {
	if (top == SZ - 1) {
		return;
	}
	top++;
	stack[top] = _d;
}
void pop() {
	if (top == -1) {
		return;
	}
	printf("%d ", stack[top]);
	top--;
}

int main() {
	int n, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	{
		scanf("%d", &d);
		push(d);
	}
	for (int i = 0; i < n; i++)
	{
		pop();
	}
}