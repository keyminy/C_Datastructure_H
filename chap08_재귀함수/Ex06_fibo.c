#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

// 피보나치 수열의 값을 저장하는 배열이다.
double mz[101] = {0,1,1}; //0번째,1번째,2번째 항 배열


double fibodp(int n) {
	if (mz[n] != 0)
		// 저장된 값이 존재하는 경우? 
		// fibonacci수열의 값이 존재함(저장된 값 사용하겟다)
		return mz[n]; // 저장된 값을 리턴해서 사용하겠다.
	//저장된 값이 없을때(mz[n]=0) , 구한 피보나치 값을 저장하겠다
	mz[n] = fibodp(n - 1) + fibodp(n - 2);
	return mz[n];

}

double fibonacci(int n) {
	if (n == 1 || n == 2) {
		// 종료조건 n<=2
		return 1;
	}
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
	printf("\n6번째 항의 값은 %.0f입니다.\n", fibodp(100));
	return 0;
}