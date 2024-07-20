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
		printf("\n\n\t\t * ���Ḯ��Ʈ�� �̿��� ���� ť(Queue) *\n\n");
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
			//�� �� ����
			removeFrontNode();
			break;
		case 3:
			// ��ȸ �Լ�
			traversalNode();
			break;
		case 4:
			// ��� ��� ���� �Լ� ȣ��
			removeAllNode();
			break;
		case 0:
			// ��� ��� ���� �Լ� ȣ��
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
	// ���ο� ��� ����
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;

	if (head == NULL) {
		// ���Ḯ��Ʈ�� ��带 ����
		head = newNode;
		tail = newNode;
		return; //ȣ���� ������ ���ư���(�Լ� ����)
	}
	// O(1)
	tail->next = newNode;
	tail = newNode;
}

int removeFrontNode()
{
	node* delNode;
	if (head == NULL) { // ������ ��尡 ���� ����?
		return 0; // ���� ����
	}
	// 1. ù ��° ��带 ������ ���� �����ϱ�
	delNode = head;
	// 2. head�� ������ ����� �������� ����
	head = head->next;
	// 3.delNode�� ����Ű�� ��� ����
	free(delNode); // delNode�� �����ϴ� ����� ����(delNode�� ������°� �ƴ�)
	return 1;
}
int removeAllNode()
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
void traversalNode()
{
	node* curNode; // �湮�� ����� �ּҸ� �����ϴ� �����ͺ���(8byte)
	if (head == NULL) {
		// Node�� 1���� �������� ����
		printf("\n\n\t\t ť�� ���� ���� �ʾ� ����� �����Ͱ� �����ϴ�.\n");
		return;
	}
	printf("Queue : ");
	curNode = head;//�湮�� ��� ���� : ù��° ����� �ּҷ�.
	while (curNode != NULL) { // �湮�� ��尡 �����Ѵٸ�?
		printf("%d ", curNode->value);
		curNode = curNode->next; //���� ���� �̵�
	}
}
