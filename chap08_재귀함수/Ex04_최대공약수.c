#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int gcd(int x, int y) {
	if (y == 0) {
		return x;//�ִ� ����� ����
	}
	int a = gcd(y,x%y);
	printf("$$$$$\n");
	printf("$$$$$\n");
	printf("$$$$$\n");
	return a;
}

int main() {
	printf("�ִ� ����� : %d\n", gcd(72, 30));
	return 0;
}