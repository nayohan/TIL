#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node* next;
};

struct node* head = 0;

void addToSLL(int _data) {
	struct node* new_one = (struct node*)malloc(sizeof(struct node));
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
		return;
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
		printf("%d ", temp->i);
		temp = temp->next;
	}
}

struct node* findToSLL(int _data) {
	struct node* temp = head;
	while (1) {
		if (temp == 0) {
			return 0;
		}
		if (temp->i == _data) {
			return temp;
		}
		else {
			temp = temp->next;
		}
	}
}	

void delToSLL(int _data) {
	struct node* who = findToSLL(_data);
	if (who == 0) {
		return;
	}
	if (who == head) {
		head = head->next;
	}
	else {
		struct node* cur = head;
		while (cur->next != who) {
			cur = cur->next;
		}
		cur->next = who->next;
		free(who);
	}
}

int main() { 
	int num, data, del;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &data);
		addToSLL(data);
	}
	scanf("%d", &del);
	delToSLL(del);
	showSLL();
}