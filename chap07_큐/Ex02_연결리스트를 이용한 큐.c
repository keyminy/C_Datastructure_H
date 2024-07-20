#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

#define MAX_SIZE 5

typedef struct node {
	int value;
	struct node* next;
} node;

node* head = NULL;
node* tail = NULL;

void insertRearNode(int data);
int removeFrontNode();
int removeAllNode();
void traversalNode();

int main() {
	int choice, data;
	while (1) {
		system("cls");
		printf("\n\n\t\t * 연결리스트를 이용한 원형 큐(Queue) *\n\n");
		printf("1. enqueue	2.dequeue	3.print    4.clear    0.terminate\n");
		printf("choice: ");
		scanf("%d", &choice);
		bufferClear();

		switch (choice) {
		case 1:
			printf("\n\nEnter the integer : ");
			scanf("%d", &data);
			bufferClear();
			insertRearNode(data);
			break;
		case 2:
			//맨 앞 삭제
			removeFrontNode();
			break;
		case 3:
			// 순회 함수
			traversalNode();
			break;
		case 4:
			// 모든 노드 제거 함수 호출
			removeAllNode();
			break;
		case 0:
			// 모든 노드 제거 함수 호출
			removeAllNode();
			exit(0);
			break;
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void insertRearNode(int data)
{
	node* newNode;
	// 새로운 노드 생성
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;

	if (head == NULL) {
		// 연결리스트에 노드를 연결
		head = newNode;
		tail = newNode;
		return; //호출한 곳으로 돌아간다(함수 종료)
	}
	// O(1)
	tail->next = newNode;
	tail = newNode;
}

int removeFrontNode()
{
	node* delNode;
	if (head == NULL) { // 생성된 노드가 없는 경우는?
		return 0; // 제거 실패
	}
	// 1. 첫 번째 노드를 삭제할 노드로 설정하기
	delNode = head;
	// 2. head를 삭제할 노드의 다음으로 변경
	head = head->next;
	// 3.delNode가 가리키는 대상 제거
	free(delNode); // delNode가 참조하는 대상이 제거(delNode가 사라지는게 아님)
	return 1;
}
int removeAllNode()
{
	node* delNode;
	if (head == NULL) { // 생성된 노드가 없는 경우는?
		return 0; // 제거 실패
	}
	while (head != NULL) {
		// 1. 첫 번째 노드를 삭제할 노드로 설정하기
		delNode = head;
		// 2. head를 삭제할 노드의 다음으로 변경
		head = head->next;
		// 3.delNode가 가리키는 대상 제거
		free(delNode); // delNode가 참조하는 대상이 제거(delNode가 사라지는게 아님)
	}
	return 1;
}
void traversalNode()
{
	node* curNode; // 방문한 노드의 주소를 저장하는 포인터변수(8byte)
	if (head == NULL) {
		// Node가 1개도 생성되지 않음
		printf("\n\n\t\t 큐가 구성 되지 않아 출력할 데이터가 없습니다.\n");
		return;
	}
	printf("Queue : ");
	curNode = head;//방문할 노드 설정 : 첫번째 노드의 주소로.
	while (curNode != NULL) { // 방문한 노드가 존재한다면?
		printf("%d ", curNode->value);
		curNode = curNode->next; //다음 노드로 이동
	}
}
