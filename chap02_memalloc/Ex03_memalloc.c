#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int num;
	printf("�л� �� �Է� : ");
	scanf("%d", &num);

	int* score = (int*)malloc(sizeof(int) * num);
	
	int total = 0;
	for (int i = 0; i < num; i++) {
		printf("%d��° ���� �Է� : ", i + 1);
		scanf("%d", &score[i]);
		total += score[i];
	}

	printf("\n\n%d���� ���� ����� %.2f�Դϴ�.\n"
		, num,(double)total/num);

	free(score);
	printf("�������� �Ҵ� �� �޸𸮸� ���� -> �޸� ������ ���� ���ؼ�\n");
	return 0;
}