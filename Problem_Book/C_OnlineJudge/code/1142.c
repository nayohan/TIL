#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char* name;
	int age;
	struct node* next;
}node;
node* head = 0;

void addNameAge(char* _name, int _age) {
	node* n_node = (node*)malloc(sizeof(node));
	n_node->name = (char*)malloc(sizeof(strlen(_name) + 1));
	strcpy(n_node->name, _name);
	n_node->age = _age;
	n_node->next = 0;

	if (head == 0) {
		head = n_node;
	}
	else {
		node* cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = n_node;
	}
}
void showOldest() {
	node* cur = head;
	node* ans = 0;
	int oldest = 0;

	while (cur != 0) {
		if (oldest < cur->age) {
			oldest = cur->age;
			ans = cur;
		}
		cur = cur->next;
	}
	printf("%s", ans->name);
}

int main() {
	int n, age;
	char name[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", name, &age);
		addNameAge(name, age);
	}
	showOldest();
}