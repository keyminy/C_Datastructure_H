#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int num;
	printf("학생 수 입력 : ");
	scanf("%d", &num);

	int* score = (int*)malloc(sizeof(int) * num);
	
	int total = 0;
	for (int i = 0; i < num; i++) {
		printf("%d번째 점수 입력 : ", i + 1);
		scanf("%d", &score[i]);
		total += score[i];
	}

	printf("\n\n%d명의 점수 평균은 %.2f입니다.\n"
		, num,(double)total/num);

	free(score);
	printf("동적으로 할당 된 메모리를 제거 -> 메모리 누수를 막기 위해서\n");
	return 0;
}