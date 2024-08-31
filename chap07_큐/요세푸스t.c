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
	printf("*** �似Ǫ�� ����(Josephus problem) *** \n\n");
	printf("ó���� ��ٸ��� ����� �� �� �Դϱ�? ");
	scanf("%d", &n);
	while (getchar() != '\n');

	printf("\n\t     * 1�� ~ %d���� ó�� ����ڰ� �ֽ��ϴ�.*\n\n",n);
	printf("�� ��° ����� ó�� �Ͻðڽ��ϱ�? ");
	scanf("%d", &k);
	while (getchar() != '\n');

	printf("\n\n\t\t �����ڴ� %d�� �Դϴ�.\n", josephus(n, k));
}

node* createNode(int value)
{
	node* newNode = (node*)malloc(sizeof(node)); // ����ü ����(���) �����Ѵ�.
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void buildCircularQueue(int n)
{
	node* tail;
	head = createNode(1);
	tail = head; //tail�� head���� ���� 

	// 1�� ���� �̹� ����� �����Ƿ� 2���� ����
	for (int i = 2; i <= n; i++) {
		tail->next = createNode(i);
		tail = tail->next;
	}
	/* ����ť�� ����� ���� �ڵ� */
	tail->next = head;
}

int josephus(int n, int k) {
	node* curNode, *delNode;
	// ���� ť �����
	buildCircularQueue(n);
	curNode = head;

	while (n>1) {
		// n == 1 �϶����� �����۾� ����
		//������ ��� �������� ������Ѵ�
		for (int i = 0; i < k - 2; i++) {
			curNode = curNode->next;
		}
		// ���� curNode�� ������ delNode�� �ٷ� �� ����̴�.
		delNode = curNode->next;
		// �翬�� �ʿ�
		curNode->next = delNode->next;
		//delNode�� �����ϱ���, ������ ��尡 head��?
		if (delNode == head)
			head = head->next;
		free(delNode);
		n--;
		// ������ ���� �������� curNode�̵�
		curNode = curNode->next;
	}
	return curNode->value;
}