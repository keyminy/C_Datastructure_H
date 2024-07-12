#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int a = 5;
	double d = 3.54;
	void* ptr;

	ptr = &a;
	printf("%d\n", *(int*)ptr);
	ptr = &d;
	printf("%f\n", *(double*)ptr);

	return 0;
}