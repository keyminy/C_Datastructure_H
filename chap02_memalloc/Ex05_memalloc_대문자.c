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

	printf("대문자 개수 입력 : ");
	scanf("%d", &alphaCnt);
	bufferClear();

	char* alpha = (char*)malloc(sizeof(char) * alphaCnt);
	// 대문자를 랜덤하게 저장
	randomizeUpper(alpha,alphaCnt);
	display(alpha,alphaCnt);

	char searchChar;
	printf("\n\n검색 문자 입력: ");
	searchChar = getchar();
	bufferClear();

	printf("\n\n검색한 문자 %c의 개수는 %d개 입니다.\n"
		,searchChar
		,getSearchChar(alpha,alphaCnt,searchChar)
	);

	free(alpha);
	return 0;
}

void randomizeUpper(char* ptr, int alphaCnt) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < alphaCnt; i++) {
		// 동적할당된 메모리 갯수만큼 반복
		ptr[i] = rand() % 26 + 65; // 65 ~90
	}
}
void display(char* ptr, int alphaCnt) {
	printf("\n\n * 랜덤하게 대문자 출력 * \n\n");
	for (int i = 0; i < alphaCnt; i++) {
		printf("%c ", ptr[i]);
	}
	puts("\n\n");
}

int getSearchChar(char* ptr,int count,char target) {
	int cnt = 0;
	//혹은 for(int i=0;i<count;i++)로 배열의 크기만큼 반복도 가능
	for (int i = 0; ptr[i] != '\0'; i++) {
		if (ptr[i] == target)
			cnt++;
	}
	return cnt;
}
