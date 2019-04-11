#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node* next;
};
struct node* head;

void addToSLL(int _data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = _data;
	new_node->next = 0;

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
	while (cur->next != 0) {
		printf("%d ", cur->i);
		cur = cur->next;
	}
	printf("%d", cur->i);
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

int main() {
	int n, data;
	scanf("%d", &n); 
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		addToSLL(data);
	}
	reverseSLL();
	showSLL();
}