#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)
double getTotal(double* ptr, int num);

int main() {
	int num;
	printf("�л� �� �Է� : ");
	scanf("%d", &num);

	//double height[num];
	double* height = (double*)malloc(sizeof(double)*num);

	// getTotal�Լ� : ���� �޸��� �հ踦 ���� return�ϴ� �Լ�
	double total = getTotal(height,num);
	//for (int i = 0; i < num; i++) {
	//	printf("%d��° ���� �Է� : ", i + 1);
	//	scanf("%lf", &height[i]);
	//	total += height[i];
	//}

	printf("\n\n%d���� ���� ����� %.2f�Դϴ�.\n"
		, num, total / num);

	free(height);
	printf("�������� �Ҵ� �� �޸𸮸� ���� -> �޸� ������ ���� ���ؼ�\n");
	return 0;
}

// getTotal�Լ� : ���� �޸��� �հ踦 ���� return�ϴ� �Լ�
double getTotal(double* ptr, int num) {
	double sum = 0;
	for (int i = 0; i < num; i++) {
		printf("%d��° ���� �Է� : ", i + 1);
		scanf("%lf", &ptr[i]);
		sum += ptr[i];
	}
	return sum;
}