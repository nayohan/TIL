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

node* findFromDLL(int _k) {
	node* cur = head;
	while (cur != 0) {
		if (cur->i == _k) {
			return cur;
		}
		cur = cur->next;
	}
	return 0;
}
void delFromDLL(int _k) {
	node* cur = findFromDLL(_k);
	if (cur == 0) {
		return;
	}
	if (cur == head) {
		head = head->next;
		free(cur);
	}
	else {
		cur->prev->next = cur->next;
		if (cur->next != 0) {
			cur->next->prev = cur->prev;
		}
		free(cur);
	}
}
void delAllFromDLL(int _n, int _k) {
	for (int i = 0; i < _n; i++) {
		delFromDLL(_k);
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
	int n, k, del;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		addToDLL(k);
	}
	showDLL();
}
void addToSLL() {

}