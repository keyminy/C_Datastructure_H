#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int a = 4;
	int* p1 = &a;
	int** p2 = &p1;
	int*** p3 = &p2;

	printf("p2�� �ּ� : %p\n", p3);
	// p1�� �ּ�
	printf("p1�� �ּ� : %p\n", p2);

	printf("p1�� �ּ� : %p\n", *p3);
	printf("p1�� �ּ� : %p\n", &p1);
	//a�� �ּ�
	printf("\n%p\n", **p3);
	printf("%p\n", &a);
	printf("%p\n", p1);
	return 0;
}