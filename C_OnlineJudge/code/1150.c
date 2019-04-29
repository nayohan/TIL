#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ 5
char* stack[SZ];
int top = -1;

void push(char* _place) {
	if (top == SZ - 1) {
		return;
	}
	top++;
	stack[top] = (char*)malloc(sizeof(strlen(_place) + 1));
	strcpy(stack[top], _place);
}
void pop() {
	if (top == -1) {
		return;
	}
	printf("%s\n", stack[top]);
	stack[top] = 0;
	top--;
}

int main() {
	int n;
	char place[100];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)	{
		scanf("%s", place);
		push(place);
	}
	for (int i = 0; i < n; i++)
	{
		pop();
	}
}