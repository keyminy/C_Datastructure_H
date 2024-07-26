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
void inOrderDisplay(treeNode* t);
void preOrderDisplay(treeNode* t);
void postOrderDisplay(treeNode* t);
int getNodeCount(treeNode* t);
int getNodeSum(treeNode* t);
int findKthNode(treeNode* t, int idx,int* pKthVal);


int main() {
	treeNode* root = NULL;
	int a[MAX_SIZE] = {6,4,8,2,5,7,9,1,3,10};

	// createBinTree함수 : 배열을 트리 구조로 만들어서, 루트의 주소를 리턴한다.
	 // param : 1.array, 2.루트로 만들 배열의 인덱스,3.배열의 크기
	root = createBinTree(a,0,MAX_SIZE);
	printf("\n중위 순회로 출력\n"); 
	inOrderDisplay(root);

	printf("\n전위 순회로 출력\n"); 
	preOrderDisplay(root);

	printf("\n후위 순회로 출력\n"); 
	postOrderDisplay(root);

	printf("\n생성된 노드의 개수는 %d개 입니다.\n", getNodeCount(root));
	printf("\n생성된 노드의 합계는 %d 입니다.\n", getNodeSum(root));

	int idx;
	int kthVal;
	printf("\n===========================\n");
	printf("찾을 노드의 인덱스 입력 : ");
	scanf("%d", &idx);
	while (getchar() != '\n');
	if (findKthNode(root, idx,&kthVal) == 1) {
		printf("[%d]번째 index [%d]를 찾았습니다!\n", idx, kthVal);
	}
	else{
		printf("값을 찾지 못했습니다.\n");
	}
	return 0;
}

treeNode* createBinTree(int* arr, int parentIdx, int maxSize)
{
	treeNode* newNode;
	newNode = (treeNode*)malloc(sizeof(treeNode)); // treeNode생성
	//newNode->value = arr[0];
	newNode->value = arr[parentIdx];
	newNode->left = newNode->right = NULL;

	int leftIdx = 2 * parentIdx + 1;
	int rightIdx = leftIdx + 1;

	//왼쪽 자식 노드를 만들기 위해 재귀 호출
	if(leftIdx < maxSize) // 왼쪽 노드 재귀호출의 종료 조건 
		newNode->left = createBinTree(arr,leftIdx,maxSize);
	//오른쪽 자식 노드를 만들기 위해 재귀 호출
	if(rightIdx < maxSize) // 오른쪽 노드 재귀호출의 종료 조건 
		newNode-> right = createBinTree(arr ,rightIdx,maxSize);
	return newNode; // 지금 생성된 노드의 주소를 리턴한다
}

void inOrderDisplay(treeNode* t)
{
	//중위순회 : 왼쪽 - 부모 - 오른쪽
	if (t != NULL) {
		// 재귀의 종료 조건
		inOrderDisplay(t->left); //왼쪽 재귀호출
		printf("%d ", t->value); // root출력
		inOrderDisplay(t->right); // 오른쪽 재귀호출
	}
}

void preOrderDisplay(treeNode* t)
{
	// 전위순회 : 부모 - 왼쪽 - 오른쪽
	if (t != NULL) {
		// 재귀의 종료 조건
		printf("%d ", t->value); // root출력
		preOrderDisplay(t->left); //왼쪽 재귀호출
		preOrderDisplay(t->right); // 오른쪽 재귀호출
	}
}

void postOrderDisplay(treeNode* t)
{
	// 후외순회 : 왼 - 오 - 부모
	if (t != NULL) {
		// 재귀의 종료 조건
		postOrderDisplay(t->left); //왼쪽 재귀호출
		postOrderDisplay(t->right); // 오른쪽 재귀호출
		printf("%d ", t->value); // root출력
	}
}

int getNodeCount(treeNode* t)
{
	if (t != NULL) {
		//getNodeCount(t->left)가 끝날때까지 getNodeCount(t->right);로 가지 못한다.
		return 1 + getNodeCount(t->left) + getNodeCount(t->right);
	}
	return 0; // (basecase) t가 NULL이면 0개 리턴
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
		printf("초과 범위입니다!!\n");
		return -1;
	}
	// 중위 순회로 인덱스를 찾는다
	if (findKthNode(t->left, idx, pKthVal) == 1) { return 1; }
	cnt++;
	if (cnt == idx) {
		*pKthVal = t->value;
		return 1; // 찾았음
	}
	return findKthNode(t->right,idx, pKthVal);
}