#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node* next;
};
struct node* head;

struct node* findFromSLL(int _data) {
	struct node* cur = head;
	while (cur != 0) {
		if (cur->i == _data) {
			return cur;
		}
		cur = cur->next;
	}
	return 0;
}

void delFromSLL(int _data) {
	struct node* cur = findFromSLL(_data);
	struct node* beforeCur = head;
	if (beforeCur->next == 0) {
		return;
	}
	while (beforeCur->next != cur) {
		beforeCur = beforeCur->next;
	}
	beforeCur->next = cur->next;
	free(cur);
}

void addToSLL(int _data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = _data;
	new_node->next = 0;
	
	if (head == 0 || head->i == _data) {
		head = new_node;
	}
	else {
		if (findFromSLL(_data) == 0);
		else {
			delFromSLL(_data);
		}
		struct node* cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = new_node;
	}
}

void reverseSLL() {
	struct node* p = 0, * q = 0, * r = head;
	while (r != 0) {
		p = q;
		q = r;
		r = r->next;
		q->next = p;
	}
	head = q;
}

void showSLL() {
	struct node* cur = head;
	while (cur != 0) {
		printf("%d ", cur->i);
		cur = cur->next;
	}
}

int main() {
	int data = 1;
	scanf("%d", &data);
	while (data >= 0) {
		addToSLL(data);
		scanf("%d", &data);
	}
	reverseSLL();
	showSLL();
}