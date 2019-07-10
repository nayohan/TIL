#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char* name;
	int age;
	struct node* next;
}node;
node* head = 0;

void addToSLL(char* _name, int _age) {
	node* n_node = (node*)malloc(sizeof(node));
	n_node->name = (char*)malloc(sizeof(strlen(_name) + 1));
	n_node->age = _age;

	if (head == 0) {
		head = n_node;
	}
	else {
		node* cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = n_node;
	}
}
void showSLL() {
	node* cur = head;
	while (cur->next != 0) {
		prinft("%d", )
		cur = cur->next;
	}
}

int main() {

}