#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int num=0;
	int cnt = 0;
	int sum = 0;
	while (1) {
		printf("�ڿ����� �Է��ϼ��� : ");
		scanf("%d", &num);
		if (num == 0) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		if (num < 2) {
			printf("1���� ū ���� �Է��ϼ���.\n");
			continue;
		}
		int* aliquots = (int*)malloc(sizeof(int)*num);
		for (int i = 1; i <= num; i++) {
			if (num % i == 0) {
				aliquots[cnt++] = i;
				sum += i;
			}
		}
		printf("�� �� : ");
		for (int i = 0; i < cnt; i++) {
			printf("%d ", aliquots[i]);
		}
		puts("");
		printf("����� ���� : %d\n", cnt);
		printf("����� �� : %d\n", sum);
		cnt = 0;
		sum = 0;
		free(aliquots);
	}
	return 0;
}