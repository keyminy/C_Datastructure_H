#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	//const char* fruit1 = "apple";
	//const char* fruit2 = "banana";
	//const char* fruit3 = "watter melon";
	//const char* fruit4 = "pear";
	//const char* fruit5 = "strawberry";

	// 포인터 배열로 문자열의 주소를 각각 저장
	const char* fruit[5] = {
		"apple",
		"banana",
		"water melon",
		"pear",
		"strawberry"
	};

	// apple을 출력하기 -> printf("%s\n", fruit[0]);
	//printf("%s\n", fruit[0]);
	//printf("%s\n", fruit[1]);
	//printf("%s\n", fruit[2]);
	//printf("%s\n", fruit[3]);
	//printf("%s\n", fruit[4]);

	// 반복문으로 출력
	for (int i = 0; i < 5; i++) {
		printf("%c\n", *(fruit[i] + 2));
	}
	puts("\n\n");
	for (int i = 0; i < 5; i++) {
		printf("%c\n", fruit[i][2]);
	}

	for (int i = 0; i < 5; i++) { //행
		for (int j = 0; fruit[i][j] != '\0'; j++) {	//열
			printf("%c", fruit[i][j]);
		}
		puts("");
	}

	return 0;
}