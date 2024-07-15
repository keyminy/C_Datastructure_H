#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int orgNum,temp;
	int reverseNum = 0; // 역순으로 뒤집은 숫자
	int unit = 1000000; // 1,000,000 백만
	// orgNum계속 10씩 /로 나눔
	printf("정수 입력 : ");
	scanf("%d", &orgNum);
	
	temp = orgNum; // 원래 입력한수 나누고 계산하고..

	while (temp > 0) {
		reverseNum += (temp % 10) * unit; // 1234567 % 10 = 7(1의 자리수)
		// 700만(7,000,000) 나옴
		temp /= 10; // 10의자리수 구하기, 123456 , ... 0이 될때까지 나누기
		unit /= 10; // 100,000 십만 , ... * 10 * 1
	}
	printf("org Num : %d\n", orgNum);
	printf("reverse Num : %d\n", reverseNum);
	printf("sum : %d\n", orgNum + reverseNum);
	return 0;
}