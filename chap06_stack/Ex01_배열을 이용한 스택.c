#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

#define MAX_SIZE 5

typedef struct stack {
	int arr[MAX_SIZE]; // stack으로 사용할 배열
	int top;//꼭대기 인덱스
} stack;

void push(stack* ptr, int data);
void pop(stack* ptr);
void printStack(const stack* ptr); // call by value로 구조체 24byte복사하지 않기 위함.
// 출력만 해주어야하므로, const키워드를 앞에 붙임

int main() {
	stack stk; // 구조체 변수 선언
	int choice,data;
	stk.top = -1; //top은 -1에서 시작한다
	while (1) {
		system("cls");
		printf("\n\n\t\t * 배열을 이용한 스택(Stack) *\n\n");
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
			// 이 clear는 물리적인 삭제아님(실제 삭제되는 것이 아님)
			// 논리적인 삭제이다(삭제된 것처럼 코드를 구현한 것임)
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
