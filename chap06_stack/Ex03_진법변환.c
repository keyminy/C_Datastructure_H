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

	printf("10������ �Է� �ϼ���: ");
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
		// insertFrontNode�Լ��� head�� �ּҰ� &head�Ѱ������
		insertFrontNode(pHead,mod);
		n /= 2;
	}
}

void traversalNode(node* head)
{
	node* curNode; // �湮�� ����� �ּҸ� �����ϴ� �����ͺ���(8byte)
	if (head == NULL) {
		// Node�� 1���� �������� ����
		printf("\n\n\t\t ���Ḯ��Ʈ�� ���� ���� �ʾ� ����� �����Ͱ� �����ϴ�.\n");
		return;
	}
	printf("\n\n2���� ��ȯ :  : ");
	curNode = head;//�湮�� ��� ���� : ù��° ����� �ּҷ�.
	while (curNode != NULL) { // �湮�� ��尡 �����Ѵٸ�?
		printf("%d ", curNode->value);
		curNode = curNode->next; //���� ���� �̵�
	}
	printf("(2)\n");
}


void insertFrontNode(node** pHead,int data)
{
	node* newNode;
	// ���ο� ��� ����
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;
	if (*pHead == NULL) {
		// ���Ḯ��Ʈ�� ��带 ����
		*pHead = newNode;
		return; //ȣ���� ������ ���ư���(�Լ� ����)
	}
	else {
		newNode->next = *pHead;
		*pHead = newNode;
	}
}
int removeAllNode(node* head)
{
	node* delNode;
	if (head == NULL) { // ������ ��尡 ���� ����?
		return 0; // ���� ����
	}
	while (head != NULL) {
		// 1. ù ��° ��带 ������ ���� �����ϱ�
		delNode = head;
		// 2. head�� ������ ����� �������� ����
		head = head->next;
		// 3.delNode�� ����Ű�� ��� ����
		free(delNode); // delNode�� �����ϴ� ����� ����(delNode�� ������°� �ƴ�)
	}
	return 1;
}