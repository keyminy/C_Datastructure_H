#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct point {
	int x, y;
} point;

int main() {
	//point p1; // 정적할당 : 컴파일 시점에, 할당될 메모리의 크기를 결정
	point* ptr;
	ptr = (point*)malloc(sizeof(point)); // 실행 중에 4byte메모리가 할당됨
	ptr->x = 3;
	ptr->y = 5;

	printf("p1(%d, %d)\n", ptr->x, ptr->y);
	//free(포인터); // 포인터가 참조하는 메모리를 제거
	free(ptr);
	return 0;
}