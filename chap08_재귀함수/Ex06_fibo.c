#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

// �Ǻ���ġ ������ ���� �����ϴ� �迭�̴�.
double mz[101] = {0,1,1}; //0��°,1��°,2��° �� �迭


double fibodp(int n) {
	if (mz[n] != 0)
		// ����� ���� �����ϴ� ���? 
		// fibonacci������ ���� ������(����� �� ����ϰٴ�)
		return mz[n]; // ����� ���� �����ؼ� ����ϰڴ�.
	//����� ���� ������(mz[n]=0) , ���� �Ǻ���ġ ���� �����ϰڴ�
	mz[n] = fibodp(n - 1) + fibodp(n - 2);
	return mz[n];

}

double fibonacci(int n) {
	if (n == 1 || n == 2) {
		// �������� n<=2
		return 1;
	}
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
	printf("\n6��° ���� ���� %.0f�Դϴ�.\n", fibodp(100));
	return 0;
}