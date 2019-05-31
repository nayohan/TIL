#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int i;
	struct node* next;
}node;
struct node* head;

void addToSLL(int _k) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->i = _k;
	new_node->next = 0;

	if (head == 0) {
		head = new_node;
	}
	else {
		node* cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = new_node;
	}
}

void showSLL() {
	node* cur = head;
	while (cur->next != 0) {
		printf("%d ", cur->i);
		cur = cur->next;
	}
	printf("%d", cur->i);
}

struct node* findFromSLL(int _v) {
	node* cur = head;
	while (cur != 0) {
		if (cur->i == _k) {
			return cur;
		}
		cur = cur->next;
	}
	return 0;
}

void delFromSLL(int _k) {
	struct node* cur = findFromSLL(_k);
	struct node* beforeCur = head;

	if (cur == 0) {
		return;
	}
	if (cur == head) {
		head = head->next;
		free(cur);
	}
	while (beforeCur->next != cur) {
		beforeCur = beforeCur->next;
	}
	beforeCur->next = cur->next;
	free(cur);
}

void insertIntoSLL(int _v, int _k) {
	struct node* who = findFromSLL(_v);
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	if (who == 0) {
		return;
	}
	new_node->i = _k;
	new_node->next = who->next;
	who->next = new_node;
}

void destroySLL() {
	while (head != 0) {
		struct node* cur = head;
		head = head->next;
		free(cur);
	}
}

int main() {
	int n, k, del;
	scanf_s("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &k);
		addToSLL(k);
	}
	insertIntoSLL(2, 4);
	delFromSLL(5);
	showSLL();
}