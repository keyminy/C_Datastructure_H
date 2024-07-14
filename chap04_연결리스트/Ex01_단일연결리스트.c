#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

typedef struct node {
	int value;
	struct node* next;
} node;

node* head = NULL; // 첫번째 노드의 주소를 저장하는 포인터 변수

void insertFrontNode(int data);

int main() {
	int choice,data;
	while (1) {
		system("cls");
		printf("\n\n\n\t * 단일 연결 리스트 *\n\n");
		printf("1. 첫 노드로 삽입\n");
		printf("2. 마지막 노드로 삽입\n");
		printf("3. N번째 노드로 삽입\n");
		printf("---------------------\n");
		printf("4. 첫 노드 제거\n");
		printf("5. 마지막 노드 제거\n");
		printf("6. 전체 노드 제거\n");
		printf("7. 특정 값 노드 노드 제거\n");
		printf("8. N번째 노드 노드 제거\n");
		printf("---------------------\n");
		printf("9. 단일 연결리스트 출력(순회)\n");
		printf("10. 노드의 개수 구하기\n");
		printf("11. 노드 검색\n");
		printf("0. 프로그램 종료\n");

		printf("\n메뉴 선택 : [  ]\b\b\b");
		scanf("%d", &choice);
		bufferClear();

		switch (choice) {
		case 1:
			printf("\n\n삽입할 정수 입력: ");
			scanf("%d", &data);
			bufferClear();
			insertFrontNode(data);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

void insertFrontNode(int data)
{
	node* newNode;
	// 새로운 노드 생성
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;
	if (head == NULL) {
		// 연결리스트에 노드를 연결
		head = newNode;
		return; //호출한 곳으로 돌아간다(함수 종료)
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}
