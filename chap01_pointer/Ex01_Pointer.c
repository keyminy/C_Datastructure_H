#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int a = 5;
	int* p = &a;
	printf("%p\n", p);//a의 주소
	printf("%d\n", *p);//p가 가리키는 곳의 값.
	return 0;
}