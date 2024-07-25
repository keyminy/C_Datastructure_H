#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)


double factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	//return n * (n-1)!;
	return n * factorial(n-1);
}

int main() {
	printf("5! = %.0f\n", factorial(5));
	return 0;
}

