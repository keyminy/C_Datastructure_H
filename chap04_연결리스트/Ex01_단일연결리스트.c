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
void insertRearNode(int data);
void traversalNode();
int getNodeCount();
int removeFrontNode();
int removeAllNode();
int removeRearNode();
int removeKthNode(int k);
node* searchNode(int target);

int main() {
	int choice,data,k;
	while (1) {
		system("cls");
		printf("\n\n\n\t * 단일 연결 리스트 *\n\n");
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
			printf("\n\n삽입할 정수 입력: ");
			scanf("%d", &data);
			bufferClear();
			insertRearNode(data);
			break;
		case 3:
			break;
		case 4:
			if (removeFrontNode()) {
				printf("\n\n\t\t첫 노드 제거를 성공했습니다.\n");
			}
			else {
				printf("\n\n\t\t첫 노드 제거를 실패했습니다.\n");
			}
			break;
		case 5: // 마지막 노드 제거
			// removeRearNode
			if (removeRearNode()) {
				printf("\n\n\t\t마지막 노드 제거를 성공했습니다.\n");
			}
			else {
				printf("\n\n\t\t마지막 노드 제거를 실패했습니다.\n");
			}
			break;
		case 6:
			if (removeAllNode()) {
				printf("\n\n\t\t전체 노드 제거를 성공했습니다.\n");
			}
			else {
				printf("\n\n\t\t전체 노드 제거를 실패했습니다.\n");
			}
			break;
		case 7:
			break;
		case 8:
			printf("\n\n몇 번째 노드를 삭제하시겠습니까? ");
			scanf("%d", &k);
			bufferClear();
			// removeKthNode : k번째 노드 제거 성공하면 1,실패하면 0
			if (removeKthNode(k)) {
				printf("\n\n\t\t%d번째 노드 제거를 성공했습니다.\n",k);
			}
			else {
				printf("\n\n\t\t%d번째 노드 제거를 실패했습니다.\n",k);
			}
			break;
		case 9:
			traversalNode();
			break;
		case 10:
			// getNodeCount함수:노드의 개수를 구해 리턴하는 함수
			printf("\n\n\t\t생성된 노드의 개수는 %d개 입니다.\n", getNodeCount());
			break;
		case 11:
			printf("\n\n검색할 정수 입력 : ");
			scanf("%d", &data);
			bufferClear();
			// searchNode함수 : 검색한 정수가 있는 경우는 노드의 주소를 리턴,
			//					검색한 정수가 없는 경우는 NULL을 리턴한다.
			if (searchNode(data) == NULL) {
				printf("\n\n\t\t검색한 정수는 존재하지 않습니다.\n");
			}
			else {
				printf("\n\n\t\t검색한 정수는 존재합니다.\n");
			}
			break;
		case 0:
			removeAllNode(); // 프로그램 종료 시, 메모리 누수를 막기 위해 생성됬던 모든 노드들을 제거
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

void insertRearNode(int data)
{
	node* newNode, *curNode;
	// 새로운 노드 생성
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;

	if (head == NULL) {
		// 연결리스트에 노드를 연결
		head = newNode;
		return; //호출한 곳으로 돌아간다(함수 종료)
	}
	// 맨 마지막 노드로 이동
	curNode = head;
	while (curNode->next != NULL) {
		// 방문한 노드의 다음 노드가 존재한다면?
		// curNode를 변경
		curNode = curNode->next;
	}
	// 이렇게하면 curNode는 마지막 Node에 Stop!!
	// 마지막 Node에 newNode를 연결
	curNode->next = newNode;
}

void traversalNode()
{
	node* curNode; // 방문한 노드의 주소를 저장하는 포인터변수(8byte)
	if (head == NULL) {
		// Node가 1개도 생성되지 않음
		printf("\n\n\t\t 연결리스트가 구성 되지 않아 출력할 데이터가 없습니다.\n");
		return;
	}
	printf("Singly Linked List : ");
	curNode = head;//방문할 노드 설정 : 첫번째 노드의 주소로.
	while (curNode != NULL) { // 방문한 노드가 존재한다면?
		printf("%d ", curNode->value);
		curNode = curNode->next; //다음 노드로 이동
	}
}

int getNodeCount()
{
	if (head == NULL) {
		return 0;
	}
	// 노드를 방문하면서 개수를 1씩 증가
	node* curNode;
	int cnt = 0;
	curNode = head;
	while (curNode != NULL) {
		cnt++;
		curNode = curNode->next;
	}
	return cnt;
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

int removeRearNode(int k)
{
	node* prevNode; // 마지막 노드 이전의 주소를 저장하는 포인터 변수
	// 노드가 한 개도 없는 경우
	if (head == NULL) {
		return 0;
	}
	// 노드가 1개인 경우
	if (head->next==NULL) {
		free(head);// 노드 삭제 후
		head = NULL;
		return 1;
	}

	// 노드가 2개 이상인 경우
	prevNode = head;
	// 마지막 노드 이전에서 prevNode를 멈추게 해줌
	while (prevNode->next->next != NULL) {
		prevNode = prevNode->next;
	}

	// 마지막 노드 제거 후
	free(prevNode->next);
	// 마지막 노드 이전 노드의 next를 NULL로 변환한다.
	prevNode->next = NULL;
	return 1;//제거 성공
}

int removeKthNode(int k)
{
	node* delNode, *prevNode;
	if (head == NULL) {
		return 0;
	}
	int nodeCount = getNodeCount(); // 노드의 개수를 구해 리턴하는 함수 호출
	if (k < 1 || k > nodeCount) {
		printf("\n\n\t\t잘못된 k값으로 삭제할 노드를 찾지 못했습니다.\n");
		printf("\t\t1 ~ %d사이의 값을 선택해주세요.\n", nodeCount);
		return 0;//삭제 실패
	}

	// head를 제거하는 경우 -> head가 변경되어야 되기때문에 구분 필요
	if (k == 1) {
		//delNode = head;// 첫 노드를 삭제할 노드로 설정한다.
		//head = head->next;
		//free(delNode);
		//return 1;
		return removeFrontNode();
	}
	// 중간 노드 제거인 경우
	// 삭제할 위치 이전에서 멈추기 위함
	prevNode = head;
	for (int i = 0; i < k - 2; i++) {
		prevNode = prevNode->next;
	}
	delNode = prevNode->next;
	prevNode->next = delNode->next;
	free(delNode); //중간노드 삭제
	return 1;
} 

node* searchNode(int target)
{
	node* curNode; //for traversal
	if (head == NULL) {
		return NULL;
	}
	curNode = head;
	//순회하면서 target을 찾으면 그 노드의 주소를 return한다.
	while (curNode != NULL) {
		// 모든 노드를 순회해야 하므로 curNode != NULL
		if (curNode->value == target) {
			return curNode;
		}
		curNode=curNode->next;
	}
	return NULL;
}
