#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node* next;
};

struct node* head[3];

void addToSLL(int _i,int _data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = _data;
	new_node->next = 0;
	if (head[_i] == 0) {
		head[_i] = new_node;
	}
	else {
		struct node* cur = head[_i];
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = new_node;
	}
}

void showSLL(int _i) {
	struct node* cur = head[_i];
	while (cur != 0) {
		printf("%d ", cur->i);
		cur = cur->next;
	}
}

void compareSLL() {
	struct node* cur_a = head[0];
	struct node* cur_b = head[1];
	struct node* cur_c = head[2];
	int cnt = 0;
	while (cur_a != 0) {
		while (cur_b != 0) {
			if (cur_a->i == cur_b->i) {
				cnt++;
			}
			cur_b = cur_b->next;
		}
		cur_b = head[1];
		cur_a = cur_a->next;
	}
	printf("%d", cnt);
}
int main() {
	int a,b, data;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &data);
		addToSLL(0, data);
	}
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		scanf("%d", &data);
		addToSLL(1, data);
	}
	compareSLL();
}