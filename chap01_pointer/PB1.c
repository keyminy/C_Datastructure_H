#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void getApproximation(int* num, int* endNum, int* closestSum);

int main() {
	int num;
	printf("���� �Է� : ");
	scanf("%d", &num);
	int startNum=1,endNum=0,closestSum=0;
	getApproximation(num,&endNum,&closestSum);
	printf("%d�� ����� �ٻ�ġ ����[%d~%d]������ ���� [%d]�Դϴ�."
		, num,startNum,endNum, closestSum);
	return 0;
}

void getApproximation(int num,int *endNum,int *closestSum) {
	int tempSum = 0;
	int i = 0;
	int prevSum = 0;
	while (tempSum < num) {
		i++;
		tempSum += i;
	}
	*endNum = i;
	prevSum = tempSum -i;
	if (tempSum - num < num - prevSum) {
		*closestSum = tempSum;
	}
	else {
		*closestSum = prevSum;
		--*endNum;
	}
}