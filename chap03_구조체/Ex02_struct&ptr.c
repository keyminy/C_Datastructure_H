#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct point {
	int x, y;
} point;

int main() {
	point p1 = { 3,5 };
	point* ptr; // 구조체 변수의 포인터(주소를 저장하는 변수)

	ptr = &p1;

	printf("p1(%d, %d)\n", p1.x, p1.y);
	printf("p1(%d, %d)\n", ptr->x, ptr->y);
	return 0;
}