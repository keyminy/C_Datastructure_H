#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int num=0;
	int cnt = 0;
	int sum = 0;
	while (1) {
		printf("자연수를 입력하세요 : ");
		scanf("%d", &num);
		if (num == 0) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		if (num < 2) {
			printf("1보다 큰 값을 입력하세요.\n");
			continue;
		}
		int* aliquots = (int*)malloc(sizeof(int)*num);
		for (int i = 1; i <= num; i++) {
			if (num % i == 0) {
				aliquots[cnt++] = i;
				sum += i;
			}
		}
		printf("약 수 : ");
		for (int i = 0; i < cnt; i++) {
			printf("%d ", aliquots[i]);
		}
		puts("");
		printf("약수의 개수 : %d\n", cnt);
		printf("약수의 합 : %d\n", sum);
		cnt = 0;
		sum = 0;
		free(aliquots);
	}
	return 0;
}