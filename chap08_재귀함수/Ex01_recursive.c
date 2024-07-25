#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void recursive(int n) {
	if (n == 0)
		return;
	printf("%d\n", n);
	printf("$$$$$$$\n");
	recursive(n - 1);
	printf("%d\n", n);
	printf("#######\n");
}

int main() {
	recursive(3);
	return 0;
}