#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	//const char* fruit1 = "apple";
	//const char* fruit2 = "banana";
	//const char* fruit3 = "watter melon";
	//const char* fruit4 = "pear";
	//const char* fruit5 = "strawberry";

	// ������ �迭�� ���ڿ��� �ּҸ� ���� ����
	const char* fruit[5] = {
		"apple",
		"banana",
		"water melon",
		"pear",
		"strawberry"
	};

	// apple�� ����ϱ� -> printf("%s\n", fruit[0]);
	//printf("%s\n", fruit[0]);
	//printf("%s\n", fruit[1]);
	//printf("%s\n", fruit[2]);
	//printf("%s\n", fruit[3]);
	//printf("%s\n", fruit[4]);

	// �ݺ������� ���
	for (int i = 0; i < 5; i++) {
		printf("%c\n", *(fruit[i] + 2));
	}
	puts("\n\n");
	for (int i = 0; i < 5; i++) {
		printf("%c\n", fruit[i][2]);
	}

	for (int i = 0; i < 5; i++) { //��
		for (int j = 0; fruit[i][j] != '\0'; j++) {	//��
			printf("%c", fruit[i][j]);
		}
		puts("");
	}

	return 0;
}