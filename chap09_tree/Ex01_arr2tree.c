#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

#define MAX_SIZE 10

typedef struct treeNode {
	int value;
	struct treeNode* left; // ���� �ڽ� ����� �ּҸ� ����
	struct treeNode* right; // ������ �ڽ� ����� �ּҸ� ����
} treeNode;

treeNode* createBinTree(int* arr, int parentIdx, int maxSize);
void inOrderDisplay(treeNode* t);
void preOrderDisplay(treeNode* t);
void postOrderDisplay(treeNode* t);
int getNodeCount(treeNode* t);
int getNodeSum(treeNode* t);
int findKthNode(treeNode* t, int idx,int* pKthVal);


int main() {
	treeNode* root = NULL;
	int a[MAX_SIZE] = {6,4,8,2,5,7,9,1,3,10};

	// createBinTree�Լ� : �迭�� Ʈ�� ������ ����, ��Ʈ�� �ּҸ� �����Ѵ�.
	 // param : 1.array, 2.��Ʈ�� ���� �迭�� �ε���,3.�迭�� ũ��
	root = createBinTree(a,0,MAX_SIZE);
	printf("\n���� ��ȸ�� ���\n"); 
	inOrderDisplay(root);

	printf("\n���� ��ȸ�� ���\n"); 
	preOrderDisplay(root);

	printf("\n���� ��ȸ�� ���\n"); 
	postOrderDisplay(root);

	printf("\n������ ����� ������ %d�� �Դϴ�.\n", getNodeCount(root));
	printf("\n������ ����� �հ�� %d �Դϴ�.\n", getNodeSum(root));

	int idx;
	int kthVal;
	printf("\n===========================\n");
	printf("ã�� ����� �ε��� �Է� : ");
	scanf("%d", &idx);
	while (getchar() != '\n');
	if (findKthNode(root, idx,&kthVal) == 1) {
		printf("[%d]��° index [%d]�� ã�ҽ��ϴ�!\n", idx, kthVal);
	}
	else{
		printf("���� ã�� ���߽��ϴ�.\n");
	}
	return 0;
}

treeNode* createBinTree(int* arr, int parentIdx, int maxSize)
{
	treeNode* newNode;
	newNode = (treeNode*)malloc(sizeof(treeNode)); // treeNode����
	//newNode->value = arr[0];
	newNode->value = arr[parentIdx];
	newNode->left = newNode->right = NULL;

	int leftIdx = 2 * parentIdx + 1;
	int rightIdx = leftIdx + 1;

	//���� �ڽ� ��带 ����� ���� ��� ȣ��
	if(leftIdx < maxSize) // ���� ��� ���ȣ���� ���� ���� 
		newNode->left = createBinTree(arr,leftIdx,maxSize);
	//������ �ڽ� ��带 ����� ���� ��� ȣ��
	if(rightIdx < maxSize) // ������ ��� ���ȣ���� ���� ���� 
		newNode-> right = createBinTree(arr ,rightIdx,maxSize);
	return newNode; // ���� ������ ����� �ּҸ� �����Ѵ�
}

void inOrderDisplay(treeNode* t)
{
	//������ȸ : ���� - �θ� - ������
	if (t != NULL) {
		// ����� ���� ����
		inOrderDisplay(t->left); //���� ���ȣ��
		printf("%d ", t->value); // root���
		inOrderDisplay(t->right); // ������ ���ȣ��
	}
}

void preOrderDisplay(treeNode* t)
{
	// ������ȸ : �θ� - ���� - ������
	if (t != NULL) {
		// ����� ���� ����
		printf("%d ", t->value); // root���
		preOrderDisplay(t->left); //���� ���ȣ��
		preOrderDisplay(t->right); // ������ ���ȣ��
	}
}

void postOrderDisplay(treeNode* t)
{
	// �Ŀܼ�ȸ : �� - �� - �θ�
	if (t != NULL) {
		// ����� ���� ����
		postOrderDisplay(t->left); //���� ���ȣ��
		postOrderDisplay(t->right); // ������ ���ȣ��
		printf("%d ", t->value); // root���
	}
}

int getNodeCount(treeNode* t)
{
	if (t != NULL) {
		//getNodeCount(t->left)�� ���������� getNodeCount(t->right);�� ���� ���Ѵ�.
		return 1 + getNodeCount(t->left) + getNodeCount(t->right);
	}
	return 0; // (basecase) t�� NULL�̸� 0�� ����
}

int getNodeSum(treeNode* t)
{
	if (t != NULL) {
		return t->value + getNodeSum(t->left) + getNodeSum(t->right);
	}
	return 0;
}

int findKthNode(treeNode* t, int idx, int* pKthVal) {
	if (t == NULL) {
		return -1; // basecase
	}
	static int cnt = -1;
	if (idx < 0 || idx >= MAX_SIZE) {
		printf("�ʰ� �����Դϴ�!!\n");
		return -1;
	}
	// ���� ��ȸ�� �ε����� ã�´�
	if (findKthNode(t->left, idx, pKthVal) == 1) { return 1; }
	cnt++;
	if (cnt == idx) {
		*pKthVal = t->value;
		return 1; // ã����
	}
	return findKthNode(t->right,idx, pKthVal);
}