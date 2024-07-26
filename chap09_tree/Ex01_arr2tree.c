#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

#define MAX_SIZE 10

typedef struct treeNode {
	int value;
	struct treeNode* left; // 왼쪽 자식 노드의 주소를 저장
	struct treeNode* right; // 오른쪽 자식 노드의 주소를 저장
} treeNode;

treeNode* createBinTree(int* arr, int parentIdx, int maxSize);

int main() {
	treeNode* root = NULL;
	int a[MAX_SIZE] = {6,4,8,2,5,7,9,1,3,10};

	// createBinTree함수 : 배열을 트리 구조로 만들어서, 루트의 주소를 리턴한다.
	 // param : 1.array, 2.루트로 만들 배열의 인덱스,3.배열의 크기
	root = createBinTree(a,0,MAX_SIZE);
	return 0;
}

treeNode* createBinTree(int* arr, int parentIdx, int maxSize)
{

	return NULL;
}
