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
		printf("���� �Է� (�ִ� 7�ڸ�) : ");
		scanf("%s",input);

		if (strlen(input) > 7) {
			printf("�ִ� 7�ڸ������� ������ �Է� �����մϴ�.\n");
			continue;
		}
		memset(reverseStr, 0, sizeof(reverseStr));

		get_reverse_num(input,reverseStr);
		num = atoi(input);
		reverseNum = atoi(reverseStr);
		
		printf("�Է��� �� : %d\n", num);
		printf("���� ������ �� : %d\n", reverseNum);
		printf("�� ���� �� : %d\n", num+ reverseNum);
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
