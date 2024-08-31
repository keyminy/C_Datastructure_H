#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node {
	int value;
	struct node* next;
} node;

node* head = NULL;
node* tail = NULL;

void buildCircularQueue(int n);
int josephus(int n,int k);


int main() {
	int n, k;
	printf("*** 요세푸스 문제(Josephus problem) *** \n\n");
	printf("처형을 기다리는 사람은 몇 명 입니까? ");
	scanf("%d", &n);
	while (getchar() != '\n');

	printf("\n\t     * 1번 ~ %d번의 처형 대기자가 있습니다.*\n\n",n);
	printf("몇 번째 사람을 처형 하시겠습니까? ");
	scanf("%d", &k);
	while (getchar() != '\n');

	printf("\n\n\t\t 생존자는 %d번 입니다.\n", josephus(n, k));
}

node* createNode(int value)
{
	node* newNode = (node*)malloc(sizeof(node)); // 구조체 변수(노드) 생성한다.
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void buildCircularQueue(int n)
{
	node* tail;
	head = createNode(1);
	tail = head; //tail은 head부터 시작 

	// 1번 노드는 이미 만들어 졌으므로 2부터 시작
	for (int i = 2; i <= n; i++) {
		tail->next = createNode(i);
		tail = tail->next;
	}
	/* 원형큐를 만들기 위한 코드 */
	tail->next = head;
}

int josephus(int n, int k) {
	node* curNode, *delNode;
	// 원형 큐 만들기
	buildCircularQueue(n);
	curNode = head;

	while (n>1) {
		// n == 1 일때까지 제거작업 수행
		//삭제할 노드 이전에서 멈춰야한다
		for (int i = 0; i < k - 2; i++) {
			curNode = curNode->next;
		}
		// 현재 curNode는 삭제할 delNode의 바로 앞 노드이다.
		delNode = curNode->next;
		// 재연결 필요
		curNode->next = delNode->next;
		//delNode를 제거하기전, 지워질 노드가 head면?
		if (delNode == head)
			head = head->next;
		free(delNode);
		n--;
		// 삭제한 곳의 다음으로 curNode이동
		curNode = curNode->next;
	}
	return curNode->value;
}