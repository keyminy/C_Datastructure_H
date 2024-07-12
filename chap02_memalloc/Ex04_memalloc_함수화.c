#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)
double getTotal(double* ptr, int num);

int main() {
	int num;
	printf("학생 수 입력 : ");
	scanf("%d", &num);

	//double height[num];
	double* height = (double*)malloc(sizeof(double)*num);

	// getTotal함수 : 동적 메모리의 합계를 구해 return하는 함수
	double total = getTotal(height,num);
	//for (int i = 0; i < num; i++) {
	//	printf("%d번째 신장 입력 : ", i + 1);
	//	scanf("%lf", &height[i]);
	//	total += height[i];
	//}

	printf("\n\n%d명의 신장 평균은 %.2f입니다.\n"
		, num, total / num);

	free(height);
	printf("동적으로 할당 된 메모리를 제거 -> 메모리 누수를 막기 위해서\n");
	return 0;
}

// getTotal함수 : 동적 메모리의 합계를 구해 return하는 함수
double getTotal(double* ptr, int num) {
	double sum = 0;
	for (int i = 0; i < num; i++) {
		printf("%d번째 신장 입력 : ", i + 1);
		scanf("%lf", &ptr[i]);
		sum += ptr[i];
	}
	return sum;
}