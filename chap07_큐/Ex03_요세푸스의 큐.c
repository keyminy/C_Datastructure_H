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
	printf("ó���� ��ٸ��� ����� �� �� �Դϱ�? ");
	scanf("%d", &n);
	while (getchar() != '\n');
	standby(n); // Creates the execution list..

	printf("\n\t     * ó�� ����Ʈ *\n\n");
	showList(n); //Prints the execution list

	printf("�� ��° ����� ó�� �Ͻðڽ��ϱ�? ");
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
		// ��尡 1�� ������ ���
		return;
	}
	tail->next = head; // Makes a circular list
}

void showList(int n) {
	node* curNode = head;
	if (head == NULL) {
		printf("\n����� ����Ʈ�� ��������� �ʾҽ��ϴ�.\n");
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
		printf("\n����Ʈ�� ��������� �ʾҽ��ϴ�.\n");
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
		delNode = curNode; // ������ ��ġ�� ����
		printf("Kill : %d\n", delNode->value);
		
		// find previous node
		node* prevNode = head;
		// ���� ���� ���� ����
		// Adjust the links to bypass the deleted node
		while (prevNode->next != delNode) {
			prevNode = prevNode->next;
		}
		// If the node to delete is the head, move the head
		if (delNode == head) {
			head = delNode->next;
		}
		if (delNode == tail) {
			tail = prevNode;// delNode�� ���� ��带 tail�� �����Ѵ�.
		}
		// Bypass the deleted node
		prevNode->next = delNode->next;
		//�湮 ��ġ ����
		curNode = delNode->next;

		free(delNode);
	}
	printf("\n\n������ : %d\n", head->value);
}

void ReleaseList(void) {
	if (head == NULL) {
		return;
	}
	node* pTmp = head;
	node* delNode;

	// *** Breaking the circular reference first ***
	tail->next = NULL;
	//1.������������, pNext���� ����ؾ��Ѵ�.
	while (pTmp != NULL) {
		delNode = pTmp;
		printf("Deleted!! %d \n", pTmp->value);
		pTmp = pTmp->next;
		free(delNode);
	}
	// ����� ������ ����� ��� Node free
	head = tail = NULL; //���� head,tail�� NULL�̹Ƿ�.
}