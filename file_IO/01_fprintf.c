#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	FILE* fp = NULL; // 64bit�ý��ۿ��� 8byte
	//fopen("���ϸ�","���"); // return type : FILE*(������ file�� �ּҰ� ��ȯ��)
	fp = fopen("out.txt","a");

	if (fp == NULL) {
		printf("file open failed!\n");
		return 0;
	}
	// fprintf(file���ٰ� data���)
	fprintf(fp, "%s\n", "Hello World!");
	fprintf(fp, "%s\n", "Hello World!");
	fclose(fp); // flocse(file pointer);
	return 0;
}