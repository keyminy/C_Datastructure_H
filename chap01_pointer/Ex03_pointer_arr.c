#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	//int* p1, * p2, * p3, * p4, * p5;
	int* p[5] = {NULL};
	int a = 3, b = 5;
	
	p[2] = &a;
	p[4] = &b;

	printf("a의 값 : %d, %d\n", a, *p[2]);
	printf("b의 값 : %d, %d", b, *p[4]);
	return 0;
}