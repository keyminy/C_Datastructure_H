#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int count;
	char ch; //���� �о�� ����
	FILE* fp = NULL;
	fp = fopen("pigs.txt", "r");
	if (fp == NULL) {
		printf("file open fail!");
		return 0;
	}
	count = 0;
	while (1) {
		ch = fgetc(fp);
		if (ch >= 'A' && ch <= 'Z') {
			++count;
		}else if (ch == EOF) {
			break;
		}
		printf("%c", ch);
	}
	printf("\n\n�빮���� ������ %d�� �Դϴ�.\n", count);
	fclose(fp);
	return 0;
}