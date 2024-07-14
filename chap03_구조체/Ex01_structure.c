#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct point {
	int x, y;
} point;

int main() {
	point p1,p2;
	p1.x = 3;
	p1.y = 5;
	scanf("%d", &p2.x);
	scanf("%d", &p2.y);

	printf("p1(%d, %d)\n", p1.x, p1.y);
	printf("p2(%d, %d)\n", p2.x, p2.y);
	return 0;
}