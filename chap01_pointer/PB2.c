#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)
#define MAX_NUM 999

int num_with_one(int num);

int main() {
	int cnt = 0;
	for (int i = 1; i <= MAX_NUM; i++) {
		if (num_with_one(i)) {
			cnt++;
			printf("%3d ",i);
			if (cnt % 10 == 0) {
				puts("");
			}
		}
	}
	puts("");
	printf("°¹¼ö : %d\n",cnt);

	return 0;
}

int num_with_one(int num)
{
	while (num > 0) {
		if (num % 10 == 1) {
			return 1;
		}
		num /= 10;
	}
	return 0;
}
