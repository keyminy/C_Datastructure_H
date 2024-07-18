#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

typedef struct DNode {
	int value;
	struct DNode* next; // 다음 노드의 주소를 저장, 8byte
	struct DNode* prev; // 이전 노드의 주소를 저장, 8byte
} DNode;

// head와 tail은 모든 함수에서 접근할 수 있도록 전역 변수로 선언함
DNode* head = NULL; // 첫번째 노드 주소 저장, 8byte
DNode* tail = NULL; // 마지막 노드 주소 저장, 8byte

void insertFrontDnode(int data);
void traversalDNode();

int main()
{
	int choice,data;
	while (1)
	{
		system("cls");
		printf("\n\n  *** 이중 연결 리스트(Doubly Linked List) ***\n\n");
		printf("=====================================\n");
		printf("1. 첫 노드로 삽입\n");
		printf("2. 마지막 노드로 삽입\n");
		printf("3. k번째 노드로 삽입\n");
		printf("---------------------\n");
		printf("4. 첫 노드 제거\n");
		printf("5. 마지막 노드 제거\n");
		printf("6. 전체 노드 제거\n");
		printf("7. 특정 값 노드 노드 제거\n");
		printf("8. k번째 노드 노드 제거\n");
		printf("---------------------\n");
		printf("9. 이중 연결리스트 출력(순회)\n");
		printf("10. 노드의 개수 구하기\n");
		printf("11. 노드 검색\n");
		printf("0. 프로그램 종료\n");
		printf("=====================================\n");
		printf("\n메뉴 선택 : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n\n삽입할 정수를 입력 하세요 : ");
			scanf("%d", &data);
			bufferClear();
			insertFrontDnode(data);
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
			traversalDNode();
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 0:
			exit(0); //프로그램 강제 종료
		}//end switch

		//switch문을 빠져 나오면 일시 대기 시킨다.
		printf("\n\n\t\t");
		system("pause"); //일시 대기

	}//end while
	return 0;
}

void insertFrontDnode(int data)
{
	// 노드 생성
	DNode* newNode;
	newNode = (DNode*)malloc(sizeof(DNode)); // 구조체 변수(노드) 생성됨 (20byte)

	// 값 대입
	newNode->value = data;
	newNode->next = newNode->prev = NULL;

	// 이중 연결리스트에 노드를 연결한다.
	if (head == NULL) {
		// 새 노드가 첫노드, head와 tail에 값을 넣어줌
		head = newNode;
		tail = newNode;
		return;
	}
	// 기존에 생성된 노드가 있는 경우
	newNode->next = head;
	head->prev = newNode;
	// head변경
	head = newNode;
}

void traversalDNode()
{
	DNode* curNode; // 방문한 노드의 주소를 저장하는 포인터변수(8byte)
	if (head == NULL) {
		// Node가 1개도 생성되지 않음
		printf("\n\n\t\t 연결리스트가 구성 되지 않아 출력할 데이터가 없습니다.\n");
		return;
	}
	printf("\n\nDoubly Linked List : ");
	curNode = head;//방문할 노드 설정 : 첫번째 노드의 주소로.
	while (curNode != NULL) { // 방문한 노드가 존재한다면?
		printf("%d ", curNode->value);
		curNode = curNode->next; //다음 노드로 이동
	}
}
