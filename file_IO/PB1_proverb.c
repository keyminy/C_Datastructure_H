#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int a_count = 0;
	FILE* fp = NULL;
	fp = fopen("proverb.txt", "r");
	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == 'a' || ch == 'A') {
			a_count += 1;
		}
		if (ch == '\n') {
			puts("");
			printf("A(a)ÀÇ °¹¼ö : %d\n",a_count);
			a_count = 0;
		}
		else {
			printf("%c", ch);
		}
	}
	fclose(fp);
	return 0;
}