#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

void get_reverse_num(char* input,char* reverseStr);

int main() {
	char input[20];
	char reverseStr[20];
	int num;
	int reverseNum;

	while (1) {
		printf("정수 입력 (최대 7자리) : ");
		scanf("%s",input);

		if (strlen(input) > 7) {
			printf("최대 7자리까지의 정수만 입력 가능합니다.\n");
			continue;
		}
		memset(reverseStr, 0, sizeof(reverseStr));

		get_reverse_num(input,reverseStr);
		num = atoi(input);
		reverseNum = atoi(reverseStr);
		
		printf("입력한 수 : %d\n", num);
		printf("역순 저장한 수 : %d\n", reverseNum);
		printf("두 수의 합 : %d\n", num+ reverseNum);
		printf("========================\n");
	}
	return 0;
}

void get_reverse_num(char* input, char* reverseStr)
{
	int len = strlen(input);
	for (int i=0; i < len; i++) {
		reverseStr[i] = input[len-i-1];
	}
	reverseStr[len] = '\0';
	
	while (strlen(reverseStr) < 7) {
		int reverse_len = strlen(reverseStr);
		reverseStr[reverse_len++] = '0';
		if (reverse_len > 7) {
			reverseStr[reverse_len] = '\0';
			break;
		}
	}
}
