#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node {
	int value;
	struct node* next;
} node;

node* head = NULL;
node* tail = NULL;

void standby(int n);
void showList(int n);
void josephus(int k);
void ReleaseList(void);


int main() {
	int n, k;
	printf("처형을 기다리는 사람은 몇 명 입니까? ");
	scanf("%d", &n);
	while (getchar() != '\n');
	standby(n); // Creates the execution list..

	printf("\n\t     * 처형 리스트 *\n\n");
	showList(n); //Prints the execution list

	printf("몇 번째 사람을 처형 하시겠습니까? ");
	scanf("%d", &k);
	while (getchar() != '\n');
	josephus(k);

	ReleaseList();
	return 0;
}

void standby(int n)
{
	for (int i = 1; i <= n; i++) {
		/* Create newNode */
		node* newNode = (node*)malloc(sizeof(node));
		newNode->value = i;
		newNode->next = NULL;

		if (head == NULL) {
			// Checks if the node is created
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	if (head == tail) {
		// 노드가 1개 생성된 경우
		return;
	}
	tail->next = head; // Makes a circular list
}

void showList(int n) {
	node* curNode = head;
	if (head == NULL) {
		printf("\n출력할 리스트가 만들어지지 않았습니다.\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ",curNode->value);
		curNode = curNode->next;
	}
	printf("\n");
}

////Deletes every kth node until one node has been left
// TODO...
void josephus(int k)
{
	if (head == NULL) {
		printf("\n리스트가 만들어지지 않았습니다.\n");
		return;
	}
	node* curNode = head;
	node* delNode;
	int count;

	while (head != tail) {
		// Loop until only one node remains
		// Move to the k-th node
		for (count = 1; count < k; count++) {
			curNode = curNode->next;
		}

		// Remove the k-th node
		delNode = curNode; // 움직인 위치가 삭제
		printf("Kill : %d\n", delNode->value);
		
		// find previous node
		node* prevNode = head;
		// 삭제 전에 연결 부터
		// Adjust the links to bypass the deleted node
		while (prevNode->next != delNode) {
			prevNode = prevNode->next;
		}
		// If the node to delete is the head, move the head
		if (delNode == head) {
			head = delNode->next;
		}
		if (delNode == tail) {
			tail = prevNode;// delNode의 이전 노드를 tail로 설정한다.
		}
		// Bypass the deleted node
		prevNode->next = delNode->next;
		//방문 위치 변경
		curNode = delNode->next;

		free(delNode);
	}
	printf("\n\n생존자 : %d\n", head->value);
}

void ReleaseList(void) {
	if (head == NULL) {
		return;
	}
	node* pTmp = head;
	node* delNode;

	// *** Breaking the circular reference first ***
	tail->next = NULL;
	//1.날려버리기전, pNext값을 백업해야한다.
	while (pTmp != NULL) {
		delNode = pTmp;
		printf("Deleted!! %d \n", pTmp->value);
		pTmp = pTmp->next;
		free(delNode);
	}
	// 백업을 했으면 백업한 대상 Node free
	head = tail = NULL; //최초 head,tail은 NULL이므로.
}