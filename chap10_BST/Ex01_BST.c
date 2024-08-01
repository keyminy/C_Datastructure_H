#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct treeNode {
	int value;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* addTreeNode(treeNode* t,int data);
void inOrderDisplay(treeNode* t);
int getNodeCount(treeNode* t);
int getNodeSum(treeNode* t);
void memoryAllFree(treeNode* t);
treeNode* getMaxNode(treeNode* t);
treeNode* getMinNode(treeNode* t);
treeNode* searchTreeNode(treeNode* t,int target);
treeNode* removeNode(treeNode* t, int target);

int main() {
	treeNode* root = NULL;
	treeNode* findNode = NULL;
	int choice, data;

	while (1) {
		system("cls");
		printf("\n\n\t\t* Binary Search Tree(BST, 이진 검색 트리) * \n");
		printf("\t\t1. 노드 삽입\n");
		printf("\t\t2. 노드 삭제\n");
		printf("\t\t3. 노드 검색\n");
		printf("\t\t4. 최댓값 찾기\n");
		printf("\t\t5. 최솟값 찾기\n");
		printf("\t\t6. 노드의 개수 구하기\n");
		printf("\t\t7. 노드의 합 구하기\n");
		printf("\t\t8. BST 출력(중위순회)\n");
		printf("\t\t9. Tree Node 제거(clear)\n");
		printf("\t\t0. 프로그램 종료\n");

		printf("\n\t\t메뉴 선택 : ");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n\t\t삽입할 정수 입력 : ");
			scanf("%d", &data);
			while (getchar() != '\n');
			// addTreeNode함수 : 노드를 생성한 후, root의 주소를 return
			root = addTreeNode(root,data);
			break;
		case 2:
			printf("\n\n\t\t삭제할 정수 입력: ");
			scanf("%d", &data);
			while (getchar() != '\n');
			// removeNode함수 : 삭제할 노드의 주소값 리턴
			root = removeNode(root, data);
			break;
		case 3:
			printf("\n\n\t\t검색할 정수 입력: ");
			scanf("%d", &data);
			while (getchar() != '\n');
			// searchTreeNode : target이 존재하면, target의 주소를 return
			// 존재하지 않으면 NULL
			findNode = searchTreeNode(root,data); // root부터 search한다.
			if (findNode == NULL)
				printf("\n\n\t\t찾는 값은 존재하지 않습니다.\n");
			else
				printf("\n\n\t\t검색한 노드는 %p번지에 저장되어 있습니다.\n",findNode);
			break;
		case 4:
			// getMaxNode함수 : 최댓값 노드의 주소를 리턴
			findNode = getMaxNode(root);
			printf("\n\n\t\t생성된 노드의 최댓값은 %d입니다.\n", findNode->value);
			break;
		case 5:
			// getMinNode함수 : 최솟값 노드의 주소를 리턴
			findNode = getMinNode(root);
			printf("\n\n\t\t생성된 노드의 최솟값은 %d입니다.\n", findNode->value);
			break;
		case 6:
			printf("\n\n\t\t생성된 트리 노드의 개수는 %d개 입니다.\n", getNodeCount(root));
			break;
		case 7:
			printf("\n\n\t\t생성된 트리 노드의 합은 %d 입니다.\n", getNodeSum(root));
			break;
		case 8:
			printf("\n\n\t\tBST 중위순회(오름차순) : ");
			inOrderDisplay(root);
	 		break;
		case 9:
			memoryAllFree(root);
			root = NULL; // root를 NULL로 초기화
	 		break;
		case 0:
			memoryAllFree(root); //메모리 누수를 막기 위해 생성된 노드 모두 제거
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

treeNode* addTreeNode(treeNode* t, int data)
{
	if (t == NULL) {
		// t = NULL일때, tree의 leaf로 이동했다는 뜻
		// 새로운 Node생성해줘야지
		t = (treeNode*)malloc(sizeof(treeNode)); //노드 생성
		t->value = data;
		t->left = t->right = NULL;
	}
	else if (t->value > data) {
		t->left = addTreeNode(t->left, data); //왼쪽 주소를 가지고 재귀호출
	}
	else {
		// if(t->value < data)
		t->right = addTreeNode(t->right, data); //오른쪽 주소를 가지고 재귀호출
	}
	return t;
}

void inOrderDisplay(treeNode* t) {
	// 중위순회 : 왼쪽 - 부모 - 오른쪽
	if (t != NULL) {
		// 재귀의 종료 조건
		inOrderDisplay(t->left); // 왼쪽 재귀호출
		printf("%d ", t->value); //root출력
		inOrderDisplay(t->right); // 오른쪽 재귀호출
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

void memoryAllFree(treeNode* t)
{
	if (t != NULL) {
		memoryAllFree(t->left);
		memoryAllFree(t->right);
		printf("\t\t%d메모리 제거\n", t->value);
		free(t); // 메모리 제거
	}
}

treeNode* getMaxNode(treeNode* t)
{
	// M2.반복문 방법
	if (t != NULL) {
		while (t->right != NULL) {
			//오른쪽 노드의 주소로 t값을 변경
			t = t->right;
		}
	}
	return t;
}

treeNode* getMinNode(treeNode* t)
{
	// M1.재귀함수 방법
	if (t != NULL) {
		if (t->left != NULL) {
			// 왼쪽 자식 노드가 존재한다면, 왼쪽 자식노드로 재귀호출
			return getMinNode(t->left);
		}
	}
	return t;
}
// (M1)재귀
/*
treeNode* searchTreeNode(treeNode* t,int target)
{
	if (t != NULL) {
		if (t->value == target)
			return t; // 찾은 값의 주소 리턴
		else if (t->value < target)
			return searchTreeNode(t->right, target); //오른쪽으로 탐색
		else
			return searchTreeNode(t->left, target);
	}
	return t; // t가 NULL일 수도 있으니
}
*/
// (M2)반복문 이용
treeNode* searchTreeNode(treeNode* t,int target)
{
	while (t != NULL && t->value != target) {
		if (t->value < target)
			t = t->right;
		else
			t = t->left;
	}
	// t가 NULL인경우 return됨 or t가 value를 찾을때
	return t; 
}

treeNode* removeNode(treeNode* t, int target)
{
	treeNode* temp;
	if (t != NULL) {
		if (t->value == target) {
			/* 제거하러 가기 */
			/*제거할 노드의 자식 노드가 없는 경우*/
			if (t->left == NULL && t->right == NULL) {
				free(t); // 바로 제거
				return NULL;//부모에게 NULL을 돌려줘야함
			}
			/* 제거할 노드의 자식 노드가 한 개인 경우 */
			else if (t->right == NULL) { // 왼쪽 자식 노드만 존재하는 경우
				temp = t->left;// 임시 저장
				free(t); // 맡겨놨으니 부모 해제가능
				return temp;
			}
			else if (t->left == NULL) { // 오른쪽 자식 노드만 존재하는 경우
				temp = t->right;// 임시 저장
				free(t); // 맡겨놨으니 부모 해제가능
				return temp;
			}
			/*제거할 노드의 자식 노드가 두 개인 경우*/
			else {
				//1.왼쪽 자식 노드 중, 최댓값을 삭제할 노드로 대입한다.
				temp = getMaxNode(t->left);
				//2.삭제할 위치로 최댓값을 대입
				t->value = temp->value;
				// 3.그 최대값을 제거하러 다시 출발(재귀호출)
				t->left = removeNode(t->left,temp->value);
			}
		}
		else if (t->value < target) {
			t-> right = removeNode(t->right, target); //오른쪽으로 재귀호출
		}
		else {
			t-> left = removeNode(t->left, target); //왼쪽으로 재귀 호출
		}
	}
	return t;
}
