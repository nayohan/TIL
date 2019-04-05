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
	while (cur != 0) {
		printf("%d ", cur->i);
		cur = cur->next;
	}
}

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
	struct node* who = findFromSLL(_data);
	struct node* cur = head;
	//***********************
	if (who == 0) {
		return;
	}
	if (who == head) {
		head = head->next;
		free(who);
	}
	//***********************
	while (cur->next != who) {
		cur = cur->next;
	}
	cur->next = who->next;
	free(who);
}

void insertIntoSLL(int _whosnext, int _data) {
	struct node* who = findFromSLL(_whosnext);
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	//***********************
	if (who == 0) {
		return;
	}
	//***********************
	new_node->i = _data;
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
	int n, data, del;
	scanf_s("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data);
		addToSLL(data);
	}
	insertIntoSLL(2, 4);
	delFromSLL(5);
	showSLL();
}