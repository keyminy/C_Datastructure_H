#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int gcd(int x, int y) {
	if (y == 0) {
		return x;//최대 공약수 리턴
	}
	int a = gcd(y,x%y);
	printf("$$$$$\n");
	printf("$$$$$\n");
	printf("$$$$$\n");
	return a;
}

int main() {
	printf("최대 공약수 : %d\n", gcd(72, 30));
	return 0;
}