#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	int orgNum,temp;
	int reverseNum = 0; // �������� ������ ����
	int unit = 1000000; // 1,000,000 �鸸
	// orgNum��� 10�� /�� ����
	printf("���� �Է� : ");
	scanf("%d", &orgNum);
	
	temp = orgNum; // ���� �Է��Ѽ� ������ ����ϰ�..

	while (temp > 0) {
		reverseNum += (temp % 10) * unit; // 1234567 % 10 = 7(1�� �ڸ���)
		// 700��(7,000,000) ����
		temp /= 10; // 10���ڸ��� ���ϱ�, 123456 , ... 0�� �ɶ����� ������
		unit /= 10; // 100,000 �ʸ� , ... * 10 * 1
	}
	printf("org Num : %d\n", orgNum);
	printf("reverse Num : %d\n", reverseNum);
	printf("sum : %d\n", orgNum + reverseNum);
	return 0;
}