#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

typedef struct DNode {
	int value;
	struct DNode* next; // ���� ����� �ּҸ� ����, 8byte
	struct DNode* prev; // ���� ����� �ּҸ� ����, 8byte
} DNode;

// head�� tail�� ��� �Լ����� ������ �� �ֵ��� ���� ������ ������
DNode* head = NULL; // ù��° ��� �ּ� ����, 8byte
DNode* tail = NULL; // ������ ��� �ּ� ����, 8byte

void insertFrontDnode(int data);
void traversalDNode();

int main()
{
	int choice,data;
	while (1)
	{
		system("cls");
		printf("\n\n  *** ���� ���� ����Ʈ(Doubly Linked List) ***\n\n");
		printf("=====================================\n");
		printf("1. ù ���� ����\n");
		printf("2. ������ ���� ����\n");
		printf("3. k��° ���� ����\n");
		printf("---------------------\n");
		printf("4. ù ��� ����\n");
		printf("5. ������ ��� ����\n");
		printf("6. ��ü ��� ����\n");
		printf("7. Ư�� �� ��� ��� ����\n");
		printf("8. k��° ��� ��� ����\n");
		printf("---------------------\n");
		printf("9. ���� ���Ḯ��Ʈ ���(��ȸ)\n");
		printf("10. ����� ���� ���ϱ�\n");
		printf("11. ��� �˻�\n");
		printf("0. ���α׷� ����\n");
		printf("=====================================\n");
		printf("\n�޴� ���� : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n\n������ ������ �Է� �ϼ��� : ");
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
			exit(0); //���α׷� ���� ����
		}//end switch

		//switch���� ���� ������ �Ͻ� ��� ��Ų��.
		printf("\n\n\t\t");
		system("pause"); //�Ͻ� ���

	}//end while
	return 0;
}

void insertFrontDnode(int data)
{
	// ��� ����
	DNode* newNode;
	newNode = (DNode*)malloc(sizeof(DNode)); // ����ü ����(���) ������ (20byte)

	// �� ����
	newNode->value = data;
	newNode->next = newNode->prev = NULL;

	// ���� ���Ḯ��Ʈ�� ��带 �����Ѵ�.
	if (head == NULL) {
		// �� ��尡 ù���, head�� tail�� ���� �־���
		head = newNode;
		tail = newNode;
		return;
	}
	// ������ ������ ��尡 �ִ� ���
	newNode->next = head;
	head->prev = newNode;
	// head����
	head = newNode;
}

void traversalDNode()
{
	DNode* curNode; // �湮�� ����� �ּҸ� �����ϴ� �����ͺ���(8byte)
	if (head == NULL) {
		// Node�� 1���� �������� ����
		printf("\n\n\t\t ���Ḯ��Ʈ�� ���� ���� �ʾ� ����� �����Ͱ� �����ϴ�.\n");
		return;
	}
	printf("\n\nDoubly Linked List : ");
	curNode = head;//�湮�� ��� ���� : ù��° ����� �ּҷ�.
	while (curNode != NULL) { // �湮�� ��尡 �����Ѵٸ�?
		printf("%d ", curNode->value);
		curNode = curNode->next; //���� ���� �̵�
	}
}
