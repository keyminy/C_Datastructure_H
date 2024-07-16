#include <stdio.h>
#include <ctype.h>

#pragma warning (disable : 4996)

int main() {
	char input[20] = { 0 };
	//660510-1321611 , 총 14개 중 13개까지만
	int sum = 0;
	printf("주민등록번호 입력 : ");
	scanf("%s", input);
	int pattern[12] = { 2,3,4,5,6,7,8,9,2,3,4,5 };
	int temp_i = 0;
	for (int i = 0; i < 13; i++) {
		char ch = input[i];
		if (isdigit(ch)) {
			int n = ch - '0';
			sum += (n * pattern[temp_i++]);
		}
	}
	int remainder = sum % 11;
	int a = 11 - remainder;
	if (a >= 10) {
		a -= 10;
	}
	if (a == (input[13] - '0')) {
		printf("유효합니다.\n");
	}
	else {
		printf("유효하지 않습니다.\n");
	}

	return 0;
}
