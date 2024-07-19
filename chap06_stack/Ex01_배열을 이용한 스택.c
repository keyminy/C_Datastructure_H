#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

#define MAX_SIZE 5

typedef struct stack {
	int arr[MAX_SIZE]; // stack���� ����� �迭
	int top;//����� �ε���
} stack;

void push(stack* ptr, int data);
void pop(stack* ptr);
void printStack(const stack* ptr); // call by value�� ����ü 24byte�������� �ʱ� ����.
// ��¸� ���־���ϹǷ�, constŰ���带 �տ� ����

int main() {
	stack stk; // ����ü ���� ����
	int choice,data;
	stk.top = -1; //top�� -1���� �����Ѵ�
	while (1) {
		system("cls");
		printf("\n\n\t\t * �迭�� �̿��� ����(Stack) *\n\n");
		printf("1. push	2.pop	3.print    4.clear    0.terminate\n");
		printf("choice: ");
		scanf("%d", &choice);
		bufferClear();

		switch (choice) {
		case 1:
			printf("\n\nEnter the integer : ");
			scanf("%d", &data);
			bufferClear();
			push(&stk,data);
			break;
		case 2:
			pop(&stk);
			break;
		case 3:
			printStack(&stk);
			break;
		case 4:
			// �� clear�� �������� �����ƴ�(���� �����Ǵ� ���� �ƴ�)
			// ������ �����̴�(������ ��ó�� �ڵ带 ������ ����)
			stk.top = -1;
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

void push(stack* ptr, int data)
{
	if (ptr->top >= MAX_SIZE-1) {
		printf("\n\n\t\tstack overflow!\n");
		return;
	}
	ptr->top++;
	ptr->arr[ptr->top] = data;

}

void pop(stack* ptr)
{
	if (ptr->top <= -1) {
		printf("\n\n\t\tstack underflow!!\n");
		return;
	}
	ptr->top--;
}

void printStack(const stack* ptr)
{
	printf("\n\nStack display(LIFO, Last In First Out): ");
	for (int i = ptr->top; i >= 0; i--) {
		printf("%d ", ptr->arr[i]);
	}
	puts("");
}
