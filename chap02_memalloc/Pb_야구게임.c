#include <stdio.h>
#include <stdlib.h> // rand,srand
#include <time.h> // time

#pragma warning (disable : 4996)

#define NUM_DIGITS 3
#define ATTEMPS 10 //기회
#define RESULT_NUM 3

void generateRandomNUmbers(int* computer);
void checkResult(int* computer,int* user,int* result);
void arrayClear(int* result);

int main() {
	int computer[NUM_DIGITS];
	int user[NUM_DIGITS];
	int result[RESULT_NUM] = { 0 };
	int i;
	char isExit;
	do {
		system("cls"); // 화면 지우기
		// 컴퓨터 번호 뽑기
		generateRandomNUmbers(computer);
		//user 입력 받음
		for (i = 1; i <= ATTEMPS; i++) {
			// clear result array
			arrayClear(result);
			printf("%2d번째 기회 : ", i);
			scanf("%d %d %d", &user[0], &user[1], &user[2]);
			while (getchar() != '\n');// clear enter
			checkResult(computer, user, result);
			printf("\n\n\t\t%d strike %d ball %d out\n",
				result[0], result[1], result[2]);
			// 3 strike완성하면 10번 모두 돌지 않는다
			if (result[0] == NUM_DIGITS) {
				printf("\n\n\t\t축하합니다! 정답입니다!\n");
				break;
			}
		}
		if (i > ATTEMPS) {
			printf("\n\n\t\t10번의 기회를 모두 마칩니다.\n");
			printf("\t\t정답은 %d, %d, %d입니다.\n",
				computer[0], computer[1], computer[2]);
		}
		printf("\n\n\t\t계속(Y/y) / 종료(아무키) : ");
		isExit = getchar();
		while (getchar() != '\n');
	} while (isExit == 'Y' || isExit == 'y');
	return 0;
}

void generateRandomNUmbers(int* computer)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < NUM_DIGITS; i++) {
		computer[i] = rand() % 9 + 1; // 1~9
		for (int j = 0; j < i; j++) { // 중복검사를 위한 j loop
			if (computer[i] == computer[j]) {
				i--; // 다시 뽑으세요
				break;
			}
		}// end j loop
	}

	printf("\n테스트 모드에서만 정답 : %d %d %d\n",
		computer[0], computer[1], computer[2]);
}

void checkResult(int* computer, int* user, int* result)
{
	for (int i = 0; i < NUM_DIGITS; i++) {
		if (computer[i] == user[i]) {
			// 같은 index이고, 숫자가 같으면 strike
			result[0]++; // increase strike count
		}
		else {
			// check ball
			for (int j = 0; j < NUM_DIGITS; j++) {
				//다른 index에 같은 숫자가 있어? -> ball
				if (user[i] == computer[j]) {
					result[1]++; // increase ball count
				}
			}
		}
	}
	result[2] = NUM_DIGITS - result[0] - result[1];
}

void arrayClear(int* result)
{
	for (int i = 0; i < NUM_DIGITS; i++) {
		result[i] = 0;
	}
}
