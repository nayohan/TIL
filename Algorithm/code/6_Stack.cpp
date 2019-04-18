#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SZ 10
#define INVALID -999
int stack[SZ];
int top = -1;

void push(int _v) {
	if (top == SZ - 1) {
		printf("Stack is Full");
	}
	else {
		top++;
		stack[top] = _v;
	}
}

int pop() {
	if (top == -1) {
		return INVALID;
	}
	else {
		int temp = stack[top];
		top--;
		return temp;
	}
}

int main() {
	push(2);
	push(3);
	printf("%d \n", pop());
	printf("%d \n", pop());
}