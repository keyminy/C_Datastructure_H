#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int a = 5;
	int* p = &a;
	printf("%p\n", p);//a�� �ּ�
	printf("%d\n", *p);//p�� ����Ű�� ���� ��.
	return 0;
}