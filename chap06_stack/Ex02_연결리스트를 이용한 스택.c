#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

typedef struct node {
	int value;
	struct node* next;
} node;


void insertFrontNode(node** ptr, int data);
int removeFrontNode(node** ptr);
int removeAllNode(node** ptr);
void traversalNode(node* head);

int main() {
	node* head = NULL; // head를 main함수의 지역변수로
	int choice, data;
	while (1) {
		system("cls");
		printf("\n\n\t\t * 연결리스트를 이용한 스택(Stack) *\n\n");
		printf("1. push	2.pop	3.print    4.clear    0.terminate\n");
		printf("choice: ");
		scanf("%d", &choice);
		bufferClear();

		switch (choice) {
		case 1:
			printf("\n\nEnter the integer : ");
			scanf("%d", &data);
			bufferClear();
			insertFrontNode(&head,data); //push
			break;
		case 2:
			removeFrontNode(&head); //pop
			break;
		case 3:
			traversalNode(head);
			break;
		case 4:
			// 물리적인 삭제가 이루어진다.
			removeAllNode(&head); //clear
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

void insertFrontNode(node** ptr, int data)
{
	node* newNode;
	// 새로운 노드 생성
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;
	if (*ptr == NULL) {
		// 연결리스트에 노드를 연결
		*ptr = newNode;
		return; //호출한 곳으로 돌아간다(함수 종료)
	}
	newNode->next = *ptr;
	*ptr = newNode; // head를 newNode로 변경
}
int removeFrontNode(node** ptr)
{
	node* delNode;
	if (*ptr == NULL) { // 생성된 노드가 없는 경우는?
		return 0; // 제거 실패
	}
	// 1. 첫 번째 노드를 삭제할 노드로 설정하기
	delNode = *ptr;
	// 2. head를 삭제할 노드의 다음으로 변경
	*ptr = (*ptr)->next;
	// 3.delNode가 가리키는 대상 제거
	free(delNode); // delNode가 참조하는 대상이 제거(delNode가 사라지는게 아님)
	return 1;
}

int removeAllNode(node** ptr)
{
	node* delNode;
	if (*ptr == NULL) { // 생성된 노드가 없는 경우는?
		return 0; // 제거 실패
	}
	while (*ptr != NULL) {
		// 1. 첫 번째 노드를 삭제할 노드로 설정하기
		delNode = *ptr;
		// 2. head를 삭제할 노드의 다음으로 변경
		*ptr = (*ptr)->next;
		// 3.delNode가 가리키는 대상 제거
		free(delNode); // delNode가 참조하는 대상이 제거(delNode가 사라지는게 아님)
	}
	return 1;
}

void traversalNode(node* head)
{
	node* curNode; // 방문한 노드의 주소를 저장하는 포인터변수(8byte)
	if (head == NULL) {
		// Node가 1개도 생성되지 않음
		printf("\n\n\t\t Stack is empty!!\n");
		return;
	}
	printf("\n\nStack display(LIFO, Last In First Out): ");
	curNode = head;//방문할 노드 설정 : 첫번째 노드의 주소로.
	while (curNode != NULL) { // 방문한 노드가 존재한다면?
		printf("%d ", curNode->value);
		curNode = curNode->next; //다음 노드로 이동
	}
}
