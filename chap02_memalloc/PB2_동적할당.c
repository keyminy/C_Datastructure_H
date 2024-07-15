#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning (disable : 4996)

/*
1. �ڿ����� �Է� �޴´�.
2. �ڿ����� ũ�⸸ŭ int�� �����͸� ���� �Ҵ��Ѵ�.
3. ���ۼ��� ������ �Է� �޴´�.
4. ���� �Ҵ� �� �޸𸮿� ���ۼ��� ���� ������ �ڿ����� �����ϰ� �����Ѵ�.(rand�Լ� ���)
5. ������ �����͸� ����Ѵ�.
6. ������ �˻��ؼ� �˻��� ������ ���� ���θ� ����Ѵ�.(��, �˻��� ������ �����մϴ�. / �˻��� ������ �������� �ʽ��ϴ�.)
7. ���� �޸� �����Ѵ�.
*/

void randomize(int* pArr, int stNum, int endNum, int size);
void display(int* pArr,int size);
void search(int* pArr, int searchNum, int size);

int main() {
	int num = 0;
	printf("�ڿ��� �Է�(size ����) : ");
	scanf("%d", &num);
	while (getchar() != '\n');
	int* arr = (int*)malloc(sizeof(int) * num);
	int stNum = 0, endNum = 0;
	printf("���� ��, �� �� �Է� : ");
	scanf("%d %d", &stNum, &endNum);
	while (getchar() != '\n');

	randomize(arr, stNum, endNum, num);
	display(arr, num);

	int searchNum = 0;
	printf("\n\n�˻� ���� �Է� : ");
	scanf("%d", &searchNum);
	while (getchar() != '\n');
	search(arr,searchNum,num);

	free(arr);
	return 0;
}

void randomize(int* pArr, int stNum, int endNum,int size)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		pArr[i] = rand() % (endNum-stNum+1) + stNum;
	}
}

void display(int* pArr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", pArr[i]);
	}
}

void search(int* pArr, int searchNum, int size)
{
	int found = 0;
	for (int i = 0; i < size; i++) {
		if (pArr[i] == searchNum) {
			found = 1;
			printf("�˻��� ������ �����մϴ�.\n");
			break;
		}
	}
	if (!found) {
		printf("�˻��� ������ �������� �ʽ��ϴ�.\n");
	}
}
