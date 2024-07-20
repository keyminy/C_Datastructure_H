#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

#define MAX_SIZE 5

typedef struct queue {
	int arr[MAX_SIZE]; // ť�� ���� �迭
	int rear; // ������ ��ġ(index)
	int front; //������ ��ġ(index)
	int count; //����� ������ ����
} queue;

void enqueue(queue* ptr, int data);
void dequeue(queue* ptr);
void displayQueue(const queue* ptr);

int main() {
	int choice, data;
	queue que; // ����ü ����(32byte) ����
	que.rear = que.front = que.count = 0;
	while (1) {
		system("cls");
		printf("\n\n\t\t * �迭�� �̿��� ���� ť(Circular Queue) *\n\n");
		printf("1. enqueue	2.dequeue	3.print    4.clear    0.terminate\n");
		printf("choice: ");
		scanf("%d", &choice);
		bufferClear();

		switch (choice) {
		case 1:
			printf("\n\nEnter the integer : ");
			scanf("%d", &data);
			bufferClear();
			enqueue(&que, data);

			break;
		case 2:
			dequeue(&que);
			break;
		case 3:
			displayQueue(&que);
			break;
		case 4:
			que.rear = que.front = que.count = 0;
			break;
		case 0:
			exit(0);
			break;
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void enqueue(queue* ptr, int data) {
	if (ptr->count == MAX_SIZE) {
		// queue�� full�� ��
		printf("\n\n\t\tQueue Overflow!!\n");
		return; // �Լ� ����
	}
	ptr->arr[ptr->rear] = data; // ������ġ rear�� 1����
	ptr->rear = (ptr->rear + 1) % MAX_SIZE; // 0~4����
	ptr->count++; //����� ������ 1���� 
}

void dequeue(queue* ptr)
{
	if (ptr->count <= 0) {
		// queue�� empty�϶�
		printf("\n\n\t\tQueue underflow\n");
		return;
	}

	// ������ ����(������ ��ó�� �ڵ带 ������ ����)
	// ���������� ������ ���� �ƴϴ�.
	ptr->front = (ptr->front + 1) % MAX_SIZE;
	ptr->count--; //���� ���� 1�� ����
}

void displayQueue(const queue* ptr)
{
	if (ptr->count <= 0) {
		printf("\n\n\t\tNothing to print...\n");
		return;
	}
	printf("\n\nQueue disply(FIFO) : ");
	for (int i = ptr->front; i < ptr->front + ptr->count; i++) {
		printf("%d ", ptr->arr[i % MAX_SIZE]);
	}
	puts("");
}
