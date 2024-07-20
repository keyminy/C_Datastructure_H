#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

typedef struct node {
	int value;
	struct node* next;
} node;

void binaryConversion(node** pHead, int n);
void insertFrontNode(node** pHead, int data);
void traversalNode(const node* head);
int removeAllNode(node* head);

int main() {
	node* head = NULL;
	int n;

	printf("10진수를 입력 하세요: ");
	scanf("%d", &n);
	while (getchar() != '\n');

	binaryConversion(&head,n);
	traversalNode(head);
	removeAllNode(head);
}

void binaryConversion(node** pHead, int n)
{
	while (n > 0) {
		int mod = n % 2;
		// insertFrontNode함수에 head의 주소값 &head넘겨줘야함
		insertFrontNode(pHead,mod);
		n /= 2;
	}
}

void traversalNode(node* head)
{
	node* curNode; // 방문한 노드의 주소를 저장하는 포인터변수(8byte)
	if (head == NULL) {
		// Node가 1개도 생성되지 않음
		printf("\n\n\t\t 연결리스트가 구성 되지 않아 출력할 데이터가 없습니다.\n");
		return;
	}
	printf("\n\n2진수 변환 :  : ");
	curNode = head;//방문할 노드 설정 : 첫번째 노드의 주소로.
	while (curNode != NULL) { // 방문한 노드가 존재한다면?
		printf("%d ", curNode->value);
		curNode = curNode->next; //다음 노드로 이동
	}
	printf("(2)\n");
}


void insertFrontNode(node** pHead,int data)
{
	node* newNode;
	// 새로운 노드 생성
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;
	if (*pHead == NULL) {
		// 연결리스트에 노드를 연결
		*pHead = newNode;
		return; //호출한 곳으로 돌아간다(함수 종료)
	}
	else {
		newNode->next = *pHead;
		*pHead = newNode;
	}
}
int removeAllNode(node* head)
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