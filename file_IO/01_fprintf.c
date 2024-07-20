#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	FILE* fp = NULL; // 64bit시스템에서 8byte
	//fopen("파일명","모드"); // return type : FILE*(생성된 file의 주소값 반환함)
	fp = fopen("out.txt","a");

	if (fp == NULL) {
		printf("file open failed!\n");
		return 0;
	}
	// fprintf(file에다가 data출력)
	fprintf(fp, "%s\n", "Hello World!");
	fprintf(fp, "%s\n", "Hello World!");
	fclose(fp); // flocse(file pointer);
	return 0;
}