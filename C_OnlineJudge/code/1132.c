#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int i;
	struct node* next;
	struct node* prev;
}node;
node* head;

void addToDLL(int _k) {
	node* n_node = (node*)malloc(sizeof(node));
	n_node->i = _k;
	n_node->next = n_node->prev = 0;
	if (head == 0) {
		head = n_node;
	}
	else {
		node* cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = n_node;
		n_node->prev = cur;
	}
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
void printNodeNum() {
	node* cur = head;

}
int main() {
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		addToDLL(k);
	}
	printNodeNum();
}
