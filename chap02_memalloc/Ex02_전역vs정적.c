#include <stdio.h>
#include <stdlib.h> // for malloc,free

#pragma warning (disable : 4996)

//int a = 3; // 전역변수

void fun() {
	static int a = 3;
	++a;
	printf("%d\n", a);
}

int main() {
	fun();
	fun();
	fun();
	return 0;
}