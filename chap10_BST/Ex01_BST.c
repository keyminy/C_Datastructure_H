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
		printf("\n\n\t\t* Binary Search Tree(BST, ���� �˻� Ʈ��) * \n");
		printf("\t\t1. ��� ����\n");
		printf("\t\t2. ��� ����\n");
		printf("\t\t3. ��� �˻�\n");
		printf("\t\t4. �ִ� ã��\n");
		printf("\t\t5. �ּڰ� ã��\n");
		printf("\t\t6. ����� ���� ���ϱ�\n");
		printf("\t\t7. ����� �� ���ϱ�\n");
		printf("\t\t8. BST ���(������ȸ)\n");
		printf("\t\t9. Tree Node ����(clear)\n");
		printf("\t\t0. ���α׷� ����\n");

		printf("\n\t\t�޴� ���� : ");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n\t\t������ ���� �Է� : ");
			scanf("%d", &data);
			while (getchar() != '\n');
			// addTreeNode�Լ� : ��带 ������ ��, root�� �ּҸ� return
			root = addTreeNode(root,data);
			break;
		case 2:
			printf("\n\n\t\t������ ���� �Է�: ");
			scanf("%d", &data);
			while (getchar() != '\n');
			// removeNode�Լ� : ������ ����� �ּҰ� ����
			root = removeNode(root, data);
			break;
		case 3:
			printf("\n\n\t\t�˻��� ���� �Է�: ");
			scanf("%d", &data);
			while (getchar() != '\n');
			// searchTreeNode : target�� �����ϸ�, target�� �ּҸ� return
			// �������� ������ NULL
			findNode = searchTreeNode(root,data); // root���� search�Ѵ�.
			if (findNode == NULL)
				printf("\n\n\t\tã�� ���� �������� �ʽ��ϴ�.\n");
			else
				printf("\n\n\t\t�˻��� ���� %p������ ����Ǿ� �ֽ��ϴ�.\n",findNode);
			break;
		case 4:
			// getMaxNode�Լ� : �ִ� ����� �ּҸ� ����
			findNode = getMaxNode(root);
			printf("\n\n\t\t������ ����� �ִ��� %d�Դϴ�.\n", findNode->value);
			break;
		case 5:
			// getMinNode�Լ� : �ּڰ� ����� �ּҸ� ����
			findNode = getMinNode(root);
			printf("\n\n\t\t������ ����� �ּڰ��� %d�Դϴ�.\n", findNode->value);
			break;
		case 6:
			printf("\n\n\t\t������ Ʈ�� ����� ������ %d�� �Դϴ�.\n", getNodeCount(root));
			break;
		case 7:
			printf("\n\n\t\t������ Ʈ�� ����� ���� %d �Դϴ�.\n", getNodeSum(root));
			break;
		case 8:
			printf("\n\n\t\tBST ������ȸ(��������) : ");
			inOrderDisplay(root);
	 		break;
		case 9:
			memoryAllFree(root);
			root = NULL; // root�� NULL�� �ʱ�ȭ
	 		break;
		case 0:
			memoryAllFree(root); //�޸� ������ ���� ���� ������ ��� ��� ����
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
		// t = NULL�϶�, tree�� leaf�� �̵��ߴٴ� ��
		// ���ο� Node�����������
		t = (treeNode*)malloc(sizeof(treeNode)); //��� ����
		t->value = data;
		t->left = t->right = NULL;
	}
	else if (t->value > data) {
		t->left = addTreeNode(t->left, data); //���� �ּҸ� ������ ���ȣ��
	}
	else {
		// if(t->value < data)
		t->right = addTreeNode(t->right, data); //������ �ּҸ� ������ ���ȣ��
	}
	return t;
}

void inOrderDisplay(treeNode* t) {
	// ������ȸ : ���� - �θ� - ������
	if (t != NULL) {
		// ����� ���� ����
		inOrderDisplay(t->left); // ���� ���ȣ��
		printf("%d ", t->value); //root���
		inOrderDisplay(t->right); // ������ ���ȣ��
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

void memoryAllFree(treeNode* t)
{
	if (t != NULL) {
		memoryAllFree(t->left);
		memoryAllFree(t->right);
		printf("\t\t%d�޸� ����\n", t->value);
		free(t); // �޸� ����
	}
}

treeNode* getMaxNode(treeNode* t)
{
	// M2.�ݺ��� ���
	if (t != NULL) {
		while (t->right != NULL) {
			//������ ����� �ּҷ� t���� ����
			t = t->right;
		}
	}
	return t;
}

treeNode* getMinNode(treeNode* t)
{
	// M1.����Լ� ���
	if (t != NULL) {
		if (t->left != NULL) {
			// ���� �ڽ� ��尡 �����Ѵٸ�, ���� �ڽĳ��� ���ȣ��
			return getMinNode(t->left);
		}
	}
	return t;
}
// (M1)���
/*
treeNode* searchTreeNode(treeNode* t,int target)
{
	if (t != NULL) {
		if (t->value == target)
			return t; // ã�� ���� �ּ� ����
		else if (t->value < target)
			return searchTreeNode(t->right, target); //���������� Ž��
		else
			return searchTreeNode(t->left, target);
	}
	return t; // t�� NULL�� ���� ������
}
*/
// (M2)�ݺ��� �̿�
treeNode* searchTreeNode(treeNode* t,int target)
{
	while (t != NULL && t->value != target) {
		if (t->value < target)
			t = t->right;
		else
			t = t->left;
	}
	// t�� NULL�ΰ�� return�� or t�� value�� ã����
	return t; 
}

treeNode* removeNode(treeNode* t, int target)
{
	treeNode* temp;
	if (t != NULL) {
		if (t->value == target) {
			/* �����Ϸ� ���� */
			/*������ ����� �ڽ� ��尡 ���� ���*/
			if (t->left == NULL && t->right == NULL) {
				free(t); // �ٷ� ����
				return NULL;//�θ𿡰� NULL�� ���������
			}
			/* ������ ����� �ڽ� ��尡 �� ���� ��� */
			else if (t->right == NULL) { // ���� �ڽ� ��常 �����ϴ� ���
				temp = t->left;// �ӽ� ����
				free(t); // �ðܳ����� �θ� ��������
				return temp;
			}
			else if (t->left == NULL) { // ������ �ڽ� ��常 �����ϴ� ���
				temp = t->right;// �ӽ� ����
				free(t); // �ðܳ����� �θ� ��������
				return temp;
			}
			/*������ ����� �ڽ� ��尡 �� ���� ���*/
			else {
				//1.���� �ڽ� ��� ��, �ִ��� ������ ���� �����Ѵ�.
				temp = getMaxNode(t->left);
				//2.������ ��ġ�� �ִ��� ����
				t->value = temp->value;
				// 3.�� �ִ밪�� �����Ϸ� �ٽ� ���(���ȣ��)
				t->left = removeNode(t->left,temp->value);
			}
		}
		else if (t->value < target) {
			t-> right = removeNode(t->right, target); //���������� ���ȣ��
		}
		else {
			t-> left = removeNode(t->left, target); //�������� ��� ȣ��
		}
	}
	return t;
}
