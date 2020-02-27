#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int i;
	struct node* next;
	struct node* prev;
}node;
node* head;

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
node* whichFromDLL(int _k1) {
	node* cur = head;
	for (int i = 1; i < _k1; i++) {
		cur = cur->next;
	}
	if (cur == 0) {
		return 0;
	}
	return cur;
}
void insertIntoDLL(int _k1, int _k2) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->i = _k2;
	new_node->next = new_node->prev = 0;

	node* cur = whichFromDLL(_k1);
	if (cur == 0) {
		return;
	}
	new_node->prev = cur;
	new_node->next = cur->next;
	cur->next = new_node;
	if (new_node->next != 0) {
	new_node->next->prev = new_node;
	}
}
void reverseShowDLL() {
	node* cur = head;
	while (cur->next != 0) {
		cur = cur->next;
	}
	while (cur->prev != 0) {
		printf("%d ", cur->i);
		cur = cur->prev;
	}
	printf("%d", cur->i);
}

int main() {
	int n, k, k1, k2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		addToDLL(k);
	}
	scanf("%d %d", &k1, &k2);
	insertIntoDLL(k1, k2);
	reverseShowDLL();
}