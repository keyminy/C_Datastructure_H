#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

//구구단(2단) 재귀함수로 구현
void multitable(int num) {
	if (num == 0) {
		printf("함수종료\n");
		return;
	}
	//2*1 ~ 2*9까지 찍힘
	multitable(num - 1);
	printf("2 * %d = %d\n", num, 2 * num);
}

int main() {
	multitable(9);
	printf("main종료\n");
	return 0;
}