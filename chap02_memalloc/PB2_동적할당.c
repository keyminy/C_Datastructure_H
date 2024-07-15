#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning (disable : 4996)

/*
1. 자연수를 입력 받는다.
2. 자연수의 크기만큼 int형 데이터를 동적 할당한다.
3. 시작수와 끝수를 입력 받는다.
4. 동적 할당 된 메모리에 시작수와 끝수 사이의 자연수를 랜덤하게 저장한다.(rand함수 사용)
5. 저장한 데이터를 출력한다.
6. 정수를 검색해서 검색한 정수의 존재 여부를 출력한다.(예, 검색한 정수는 존재합니다. / 검색한 정수는 존재하지 않습니다.)
7. 동적 메모리 해제한다.
*/

void randomize(int* pArr, int stNum, int endNum, int size);
void display(int* pArr,int size);
void search(int* pArr, int searchNum, int size);

int main() {
	int num = 0;
	printf("자연수 입력(size 설정) : ");
	scanf("%d", &num);
	while (getchar() != '\n');
	int* arr = (int*)malloc(sizeof(int) * num);
	int stNum = 0, endNum = 0;
	printf("시작 수, 끝 수 입력 : ");
	scanf("%d %d", &stNum, &endNum);
	while (getchar() != '\n');

	randomize(arr, stNum, endNum, num);
	display(arr, num);

	int searchNum = 0;
	printf("\n\n검색 문자 입력 : ");
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
			printf("검색한 정수는 존재합니다.\n");
			break;
		}
	}
	if (!found) {
		printf("검색한 정수는 존재하지 않습니다.\n");
	}
}
