#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node* next;
};

struct node* head;

void addToSLL(int _data) {
	struct node* new_one = (struct node*)malloc(sizeof(struct node*));
	new_one->i = _data;
	new_one->next = 0;

	if (head == 0) {
		head = new_one;
		return;
	}
	else {
		struct node* temp = head;
		while (temp->next != 0) {
			temp = temp->next;
		}
		temp->next = new_one;
	}
	
}

void showSLL() {
	struct node* temp = head;
	while (1) {
		if (head == 0) {
			return;
		}
		if (temp == 0) {
			break;
		}
		printf("%d\ ", temp->i);
		temp = temp->next;
	}
}

int main() {
	int num, data;
	scanf_s("%d", &num);
	for (int  i = 0; i < num; i++) {
		scanf_s("%d", &data);
		addToSLL(data);
	}
	showSLL();
}