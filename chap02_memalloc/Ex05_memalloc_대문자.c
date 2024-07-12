#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myHeader.h"

#pragma warning (disable : 4996)
void randomizeUpper(char* ptr, int alphaCnt);
void display(char* ptr, int alphaCnt);
int getSearchChar(char* ptr, int count, char target);

int main() {
	int alphaCnt;

	printf("�빮�� ���� �Է� : ");
	scanf("%d", &alphaCnt);
	bufferClear();

	char* alpha = (char*)malloc(sizeof(char) * alphaCnt);
	// �빮�ڸ� �����ϰ� ����
	randomizeUpper(alpha,alphaCnt);
	display(alpha,alphaCnt);

	char searchChar;
	printf("\n\n�˻� ���� �Է�: ");
	searchChar = getchar();
	bufferClear();

	printf("\n\n�˻��� ���� %c�� ������ %d�� �Դϴ�.\n"
		,searchChar
		,getSearchChar(alpha,alphaCnt,searchChar)
	);

	free(alpha);
	return 0;
}

void randomizeUpper(char* ptr, int alphaCnt) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < alphaCnt; i++) {
		// �����Ҵ�� �޸� ������ŭ �ݺ�
		ptr[i] = rand() % 26 + 65; // 65 ~90
	}
}
void display(char* ptr, int alphaCnt) {
	printf("\n\n * �����ϰ� �빮�� ��� * \n\n");
	for (int i = 0; i < alphaCnt; i++) {
		printf("%c ", ptr[i]);
	}
	puts("\n\n");
}

int getSearchChar(char* ptr,int count,char target) {
	int cnt = 0;
	//Ȥ�� for(int i=0;i<count;i++)�� �迭�� ũ�⸸ŭ �ݺ��� ����
	for (int i = 0; ptr[i] != '\0'; i++) {
		if (ptr[i] == target)
			cnt++;
	}
	return cnt;
}
