#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5
int queue[QUEUE_SIZE];
int front = 0, rear = 0;

void enqueue(int _v) {
	if ((rear + 1) % QUEUE_SIZE == front) {
		printf("Queue is Full\n");
	}
	else {
		rear++;
		rear = rear % QUEUE_SIZE;
		queue[rear] = _v;
		printf("Enqueue : %d\n", _v);
	}
}

int dequeue() {
	if (front == rear) {
		return -999;
	}
	else {
		front = front + 1;
		front = front % QUEUE_SIZE;
		return queue[front];
	}
}

int main() {
	for (int i = 1; i <= 5; i++) {
		enqueue(i);
	}
	for (int i = 0; i < 5; i++)	{
		printf("%d\n", dequeue());
	}
	return 0;
}