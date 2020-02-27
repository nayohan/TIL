#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int i;
	struct node* next;
	struct node* prev;
}node;

node* head = 0;
void addToDLL(int _k) {
	node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = _k;
	new_node->next = new_node->prev = 0;

	if (head == 0) {
		head = new_node;
	}
	else {
		node* cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = new_node;
		new_node->prev = cur;
	}
}
void showDLL() {
	node* cur = head;
	while (cur->next != 0) {
		printf("%d ", cur->i);
		cur = cur->next;
	}
	printf("%d", cur->i);
}

int main() {
	int n, k, del;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		addToDLL(k);
	}
	showDLL();
}