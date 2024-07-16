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
		printf("\n\n\n\t * ���� ���� ����Ʈ *\n\n");
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
			printf("\n\n������ ���� �Է�: ");
			scanf("%d", &data);
			bufferClear();
			insertRearNode(data);
			break;
		case 3:
			break;
		case 4:
			if (removeFrontNode()) {
				printf("\n\n\t\tù ��� ���Ÿ� �����߽��ϴ�.\n");
			}
			else {
				printf("\n\n\t\tù ��� ���Ÿ� �����߽��ϴ�.\n");
			}
			break;
		case 5: // ������ ��� ����
			// removeRearNode
			if (removeRearNode()) {
				printf("\n\n\t\t������ ��� ���Ÿ� �����߽��ϴ�.\n");
			}
			else {
				printf("\n\n\t\t������ ��� ���Ÿ� �����߽��ϴ�.\n");
			}
			break;
		case 6:
			if (removeAllNode()) {
				printf("\n\n\t\t��ü ��� ���Ÿ� �����߽��ϴ�.\n");
			}
			else {
				printf("\n\n\t\t��ü ��� ���Ÿ� �����߽��ϴ�.\n");
			}
			break;
		case 7:
			break;
		case 8:
			printf("\n\n�� ��° ��带 �����Ͻðڽ��ϱ�? ");
			scanf("%d", &k);
			bufferClear();
			// removeKthNode : k��° ��� ���� �����ϸ� 1,�����ϸ� 0
			if (removeKthNode(k)) {
				printf("\n\n\t\t%d��° ��� ���Ÿ� �����߽��ϴ�.\n",k);
			}
			else {
				printf("\n\n\t\t%d��° ��� ���Ÿ� �����߽��ϴ�.\n",k);
			}
			break;
		case 9:
			traversalNode();
			break;
		case 10:
			// getNodeCount�Լ�:����� ������ ���� �����ϴ� �Լ�
			printf("\n\n\t\t������ ����� ������ %d�� �Դϴ�.\n", getNodeCount());
			break;
		case 11:
			printf("\n\n�˻��� ���� �Է� : ");
			scanf("%d", &data);
			bufferClear();
			// searchNode�Լ� : �˻��� ������ �ִ� ���� ����� �ּҸ� ����,
			//					�˻��� ������ ���� ���� NULL�� �����Ѵ�.
			if (searchNode(data) == NULL) {
				printf("\n\n\t\t�˻��� ������ �������� �ʽ��ϴ�.\n");
			}
			else {
				printf("\n\n\t\t�˻��� ������ �����մϴ�.\n");
			}
			break;
		case 0:
			removeAllNode(); // ���α׷� ���� ��, �޸� ������ ���� ���� ������� ��� ������ ����
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

void insertRearNode(int data)
{
	node* newNode, *curNode;
	// ���ο� ��� ����
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;

	if (head == NULL) {
		// ���Ḯ��Ʈ�� ��带 ����
		head = newNode;
		return; //ȣ���� ������ ���ư���(�Լ� ����)
	}
	// �� ������ ���� �̵�
	curNode = head;
	while (curNode->next != NULL) {
		// �湮�� ����� ���� ��尡 �����Ѵٸ�?
		// curNode�� ����
		curNode = curNode->next;
	}
	// �̷����ϸ� curNode�� ������ Node�� Stop!!
	// ������ Node�� newNode�� ����
	curNode->next = newNode;
}

void traversalNode()
{
	node* curNode; // �湮�� ����� �ּҸ� �����ϴ� �����ͺ���(8byte)
	if (head == NULL) {
		// Node�� 1���� �������� ����
		printf("\n\n\t\t ���Ḯ��Ʈ�� ���� ���� �ʾ� ����� �����Ͱ� �����ϴ�.\n");
		return;
	}
	printf("Singly Linked List : ");
	curNode = head;//�湮�� ��� ���� : ù��° ����� �ּҷ�.
	while (curNode != NULL) { // �湮�� ��尡 �����Ѵٸ�?
		printf("%d ", curNode->value);
		curNode = curNode->next; //���� ���� �̵�
	}
}

int getNodeCount()
{
	if (head == NULL) {
		return 0;
	}
	// ��带 �湮�ϸ鼭 ������ 1�� ����
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

int removeRearNode(int k)
{
	node* prevNode; // ������ ��� ������ �ּҸ� �����ϴ� ������ ����
	// ��尡 �� ���� ���� ���
	if (head == NULL) {
		return 0;
	}
	// ��尡 1���� ���
	if (head->next==NULL) {
		free(head);// ��� ���� ��
		head = NULL;
		return 1;
	}

	// ��尡 2�� �̻��� ���
	prevNode = head;
	// ������ ��� �������� prevNode�� ���߰� ����
	while (prevNode->next->next != NULL) {
		prevNode = prevNode->next;
	}

	// ������ ��� ���� ��
	free(prevNode->next);
	// ������ ��� ���� ����� next�� NULL�� ��ȯ�Ѵ�.
	prevNode->next = NULL;
	return 1;//���� ����
}

int removeKthNode(int k)
{
	node* delNode, *prevNode;
	if (head == NULL) {
		return 0;
	}
	int nodeCount = getNodeCount(); // ����� ������ ���� �����ϴ� �Լ� ȣ��
	if (k < 1 || k > nodeCount) {
		printf("\n\n\t\t�߸��� k������ ������ ��带 ã�� ���߽��ϴ�.\n");
		printf("\t\t1 ~ %d������ ���� �������ּ���.\n", nodeCount);
		return 0;//���� ����
	}

	// head�� �����ϴ� ��� -> head�� ����Ǿ�� �Ǳ⶧���� ���� �ʿ�
	if (k == 1) {
		//delNode = head;// ù ��带 ������ ���� �����Ѵ�.
		//head = head->next;
		//free(delNode);
		//return 1;
		return removeFrontNode();
	}
	// �߰� ��� ������ ���
	// ������ ��ġ �������� ���߱� ����
	prevNode = head;
	for (int i = 0; i < k - 2; i++) {
		prevNode = prevNode->next;
	}
	delNode = prevNode->next;
	prevNode->next = delNode->next;
	free(delNode); //�߰���� ����
	return 1;
} 

node* searchNode(int target)
{
	node* curNode; //for traversal
	if (head == NULL) {
		return NULL;
	}
	curNode = head;
	//��ȸ�ϸ鼭 target�� ã���� �� ����� �ּҸ� return�Ѵ�.
	while (curNode != NULL) {
		// ��� ��带 ��ȸ�ؾ� �ϹǷ� curNode != NULL
		if (curNode->value == target) {
			return curNode;
		}
		curNode=curNode->next;
	}
	return NULL;
}
