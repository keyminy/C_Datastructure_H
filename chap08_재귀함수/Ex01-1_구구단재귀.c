#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

//������(2��) ����Լ��� ����
void multitable(int num) {
	if (num == 0) {
		printf("�Լ�����\n");
		return;
	}
	//2*1 ~ 2*9���� ����
	multitable(num - 1);
	printf("2 * %d = %d\n", num, 2 * num);
}

int main() {
	multitable(9);
	printf("main����\n");
	return 0;
}