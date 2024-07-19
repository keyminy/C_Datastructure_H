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
	node* head = NULL; // head�� main�Լ��� ����������
	int choice, data;
	while (1) {
		system("cls");
		printf("\n\n\t\t * ���Ḯ��Ʈ�� �̿��� ����(Stack) *\n\n");
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
			// �������� ������ �̷������.
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
	// ���ο� ��� ����
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;
	if (*ptr == NULL) {
		// ���Ḯ��Ʈ�� ��带 ����
		*ptr = newNode;
		return; //ȣ���� ������ ���ư���(�Լ� ����)
	}
	newNode->next = *ptr;
	*ptr = newNode; // head�� newNode�� ����
}
int removeFrontNode(node** ptr)
{
	node* delNode;
	if (*ptr == NULL) { // ������ ��尡 ���� ����?
		return 0; // ���� ����
	}
	// 1. ù ��° ��带 ������ ���� �����ϱ�
	delNode = *ptr;
	// 2. head�� ������ ����� �������� ����
	*ptr = (*ptr)->next;
	// 3.delNode�� ����Ű�� ��� ����
	free(delNode); // delNode�� �����ϴ� ����� ����(delNode�� ������°� �ƴ�)
	return 1;
}

int removeAllNode(node** ptr)
{
	node* delNode;
	if (*ptr == NULL) { // ������ ��尡 ���� ����?
		return 0; // ���� ����
	}
	while (*ptr != NULL) {
		// 1. ù ��° ��带 ������ ���� �����ϱ�
		delNode = *ptr;
		// 2. head�� ������ ����� �������� ����
		*ptr = (*ptr)->next;
		// 3.delNode�� ����Ű�� ��� ����
		free(delNode); // delNode�� �����ϴ� ����� ����(delNode�� ������°� �ƴ�)
	}
	return 1;
}

void traversalNode(node* head)
{
	node* curNode; // �湮�� ����� �ּҸ� �����ϴ� �����ͺ���(8byte)
	if (head == NULL) {
		// Node�� 1���� �������� ����
		printf("\n\n\t\t Stack is empty!!\n");
		return;
	}
	printf("\n\nStack display(LIFO, Last In First Out): ");
	curNode = head;//�湮�� ��� ���� : ù��° ����� �ּҷ�.
	while (curNode != NULL) { // �湮�� ��尡 �����Ѵٸ�?
		printf("%d ", curNode->value);
		curNode = curNode->next; //���� ���� �̵�
	}
}
