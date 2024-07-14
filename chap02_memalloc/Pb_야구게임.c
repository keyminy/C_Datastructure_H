#include <stdio.h>
#include <stdlib.h> // rand,srand
#include <time.h> // time

#pragma warning (disable : 4996)

#define NUM_DIGITS 3
#define ATTEMPS 10 //��ȸ
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
		system("cls"); // ȭ�� �����
		// ��ǻ�� ��ȣ �̱�
		generateRandomNUmbers(computer);
		//user �Է� ����
		for (i = 1; i <= ATTEMPS; i++) {
			// clear result array
			arrayClear(result);
			printf("%2d��° ��ȸ : ", i);
			scanf("%d %d %d", &user[0], &user[1], &user[2]);
			while (getchar() != '\n');// clear enter
			checkResult(computer, user, result);
			printf("\n\n\t\t%d strike %d ball %d out\n",
				result[0], result[1], result[2]);
			// 3 strike�ϼ��ϸ� 10�� ��� ���� �ʴ´�
			if (result[0] == NUM_DIGITS) {
				printf("\n\n\t\t�����մϴ�! �����Դϴ�!\n");
				break;
			}
		}
		if (i > ATTEMPS) {
			printf("\n\n\t\t10���� ��ȸ�� ��� ��Ĩ�ϴ�.\n");
			printf("\t\t������ %d, %d, %d�Դϴ�.\n",
				computer[0], computer[1], computer[2]);
		}
		printf("\n\n\t\t���(Y/y) / ����(�ƹ�Ű) : ");
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
		for (int j = 0; j < i; j++) { // �ߺ��˻縦 ���� j loop
			if (computer[i] == computer[j]) {
				i--; // �ٽ� ��������
				break;
			}
		}// end j loop
	}

	printf("\n�׽�Ʈ ��忡���� ���� : %d %d %d\n",
		computer[0], computer[1], computer[2]);
}

void checkResult(int* computer, int* user, int* result)
{
	for (int i = 0; i < NUM_DIGITS; i++) {
		if (computer[i] == user[i]) {
			// ���� index�̰�, ���ڰ� ������ strike
			result[0]++; // increase strike count
		}
		else {
			// check ball
			for (int j = 0; j < NUM_DIGITS; j++) {
				//�ٸ� index�� ���� ���ڰ� �־�? -> ball
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
