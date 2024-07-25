#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void hanoi(int n, char from, char temp, char to);

int cnt = 0;

int main() {
	hanoi(3,'A','B','C');
	printf("Ƚ�� : %d\n", cnt);
	return 0;
}

void hanoi(int n, char from, char temp, char to)
{
	cnt++;
	if (n == 1) {
		printf("%c => %c �̵�\n", from, to);
		return;
	}
	hanoi(n - 1, from, to, temp);
		printf("%c => %c �̵�\n", from, to);
	hanoi(n - 1, temp, from, to);
}
