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

int main() {
	treeNode* root = NULL;
	int a[MAX_SIZE] = {6,4,8,2,5,7,9,1,3,10};

	// createBinTree�Լ� : �迭�� Ʈ�� ������ ����, ��Ʈ�� �ּҸ� �����Ѵ�.
	 // param : 1.array, 2.��Ʈ�� ���� �迭�� �ε���,3.�迭�� ũ��
	root = createBinTree(a,0,MAX_SIZE);
	return 0;
}

treeNode* createBinTree(int* arr, int parentIdx, int maxSize)
{

	return NULL;
}
