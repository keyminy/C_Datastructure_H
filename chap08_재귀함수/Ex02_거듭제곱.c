#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

double power(int x, int y);

int main() {
	printf("%.0f\n", power(2, 4));
	return 0;
}

double power(int x, int y) {
	if (y == 0) {
		return 1;
	}
	//return x * x ^ (y - 1);
	return x * power(x, y - 1);
}