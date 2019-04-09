#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i; 
	struct node* next;
};
struct node* head;
int compareSLL(int _data) {
	struct node* cur = head;
	while (cur != 0) {
		if (cur->i == _data) {
			return 0;
		}
		cur = cur->next;
	}
	return 1;
}

void addToSLL(int _data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = _data;
	new_node->next = 0;
	if (_data < 0) {
		return;
	}
	if (compareSLL(_data) == 0) {
		return;
	}
	if (head == 0) {
		head = new_node;
	}
	else {
		struct node* cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = new_node;
	}
}

void showSLL() {
	struct node* cur = head;
	while (cur != 0) {
		printf("%d ", cur->i);
		cur = cur->next;
	}
}

void reverseSLL() {
	struct node *p = 0, *q = 0, *r = head;
	while (r != 0) {
		p = q;
		q = r;
		r = r->next;
		q->next = p;
	}
	head = q;
}

int main() {
	int data = 1;

	while (data > 0) {
		scanf("%d", &data);
		addToSLL(data);
	}
	reverseSLL();
	showSLL();
}