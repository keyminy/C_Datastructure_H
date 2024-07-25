#include <iostream>

using namespace std;

int N,cnt;

void hanoi(int N, int from, int temp, int to);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	//갯수출력
	cout << (1 << N) - 1 << '\n'; //2^n-1
	hanoi(N, 1, 2, 3);
}
void hanoi(int N, int from, int temp, int to) {
	if (N == 1) {
		//원판이 하나일때는 마음대로 이동가능
		cout << from << " " << to << '\n';
		return;
	}
	// from -> temp
	hanoi(N - 1, from, to, temp);
	cout << from << " " << to << '\n'; // 가장 큰거 이동
	// temp -> to
	hanoi(N - 1, temp, from, to);
}