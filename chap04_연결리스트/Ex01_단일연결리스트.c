#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

typedef struct node {
	int value;
	struct node* next;
} node;

node* head = NULL; // ù��° ����� �ּҸ� �����ϴ� ������ ����

void insertFrontNode(int data);

int main() {
	int choice,data;
	while (1) {
		system("cls");
		printf("\n\n\n\t * ���� ���� ����Ʈ *\n\n");
		printf("1. ù ���� ����\n");
		printf("2. ������ ���� ����\n");
		printf("3. N��° ���� ����\n");
		printf("---------------------\n");
		printf("4. ù ��� ����\n");
		printf("5. ������ ��� ����\n");
		printf("6. ��ü ��� ����\n");
		printf("7. Ư�� �� ��� ��� ����\n");
		printf("8. N��° ��� ��� ����\n");
		printf("---------------------\n");
		printf("9. ���� ���Ḯ��Ʈ ���(��ȸ)\n");
		printf("10. ����� ���� ���ϱ�\n");
		printf("11. ��� �˻�\n");
		printf("0. ���α׷� ����\n");

		printf("\n�޴� ���� : [  ]\b\b\b");
		scanf("%d", &choice);
		bufferClear();

		switch (choice) {
		case 1:
			printf("\n\n������ ���� �Է�: ");
			scanf("%d", &data);
			bufferClear();
			insertFrontNode(data);
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
			break;
		case 10:
			break;
		case 11:
			break;
		case 0:
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
	// ���ο� ��� ����
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;
	if (head == NULL) {
		// ���Ḯ��Ʈ�� ��带 ����
		head = newNode;
		return; //ȣ���� ������ ���ư���(�Լ� ����)
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}
