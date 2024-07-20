#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

#define MAX_SIZE 5

typedef struct queue {
	int arr[MAX_SIZE]; // 큐로 사용될 배열
	int rear; // 삽입할 위치(index)
	int front; //삭제할 위치(index)
	int count; //저장된 원소의 개수
} queue;

void enqueue(queue* ptr, int data);
void dequeue(queue* ptr);
void displayQueue(const queue* ptr);

int main() {
	int choice, data;
	queue que; // 구조체 변수(32byte) 선언
	que.rear = que.front = que.count = 0;
	while (1) {
		system("cls");
		printf("\n\n\t\t * 배열을 이용한 원형 큐(Circular Queue) *\n\n");
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
		// queue가 full일 때
		printf("\n\n\t\tQueue Overflow!!\n");
		return; // 함수 종료
	}
	ptr->arr[ptr->rear] = data; // 저장위치 rear를 1증가
	ptr->rear = (ptr->rear + 1) % MAX_SIZE; // 0~4범위
	ptr->count++; //저장된 개수를 1증가 
}

void dequeue(queue* ptr)
{
	if (ptr->count <= 0) {
		// queue가 empty일때
		printf("\n\n\t\tQueue underflow\n");
		return;
	}

	// 논리적인 삭제(삭제된 것처럼 코드를 구현한 것임)
	// 물리적으로 삭제된 것이 아니다.
	ptr->front = (ptr->front + 1) % MAX_SIZE;
	ptr->count--; //저장 개수 1개 감소
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
