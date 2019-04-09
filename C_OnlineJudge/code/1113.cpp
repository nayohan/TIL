#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node* next;
};

struct node* head = 0;

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
	while (cur != 0) {
		printf("%d ", cur->i);
		cur = cur ->next;
	}
}

void delWhereFromSLL(int _n, int _del) {
	struct node* cur = head;
	if (_n < _del) {
		return;
	}

	for (int i = 1; i < _del; i++){
		cur = cur->next;
	}

	if (cur == head) {
		head = head->next;
		free(cur);
	}
	else {
		struct node* beforeCur = head;
		while (beforeCur->next != cur) {
			beforeCur = beforeCur->next;
		}
		beforeCur->next = cur->next;
		free(cur);
	}


}

int main() {
	int n, data, del;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		addToSLL(data);
	}
	scanf("%d", &del);
	delWhereFromSLL(n, del);
	showSLL();
}