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
	node* new_node = (node*)malloc(sizeof(node));
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
node* findFromDLL(int _find) {
	node* cur = head;
	while (cur != 0) {
		if (cur->i == _find) {
			return cur;
		}
		cur = cur->next;
	}
	return 0;
}
void printFindDLL(int _find) {
	node* cur = findFromDLL(_find);
	if (cur == 0) {
		printf("%d", -999);
	}
	else {
		if (cur->prev == 0) {
			printf("%d ", -999);
		}
		else {
			printf("%d ", cur->prev->i);
		}
		if (cur->next == 0) {
			printf("%d", -999);
		}
		else {
			printf("%d", cur->next->i);
		}
	}
}

int main() {
	int n, k, find;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		addToDLL(k);
	}
	scanf("%d", &find);
	printFindDLL(find);
}