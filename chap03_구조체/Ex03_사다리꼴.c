#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct trapezoid {
	double top, base, height;
} trapezoid;

void input(trapezoid* p_tra);
double getArea(const trapezoid* ptr);

int main() {
	trapezoid tra; // 24byte struct
	input(&tra);
	printf("\n사다리꼴의 넓이는 %.2f입니다.\n", getArea(&tra));
	return 0;
}

void input(trapezoid* p_tra) {
	printf("\n사다리꼴 윗변 입력: ");
	scanf("%lf", &p_tra->top); // top이 있는곳의 주소 가리키는 것임
	printf("\n사다리꼴 밑변 입력: ");
	scanf("%lf", &p_tra->base); // base가 있는곳의 주소 가리키는 것임
	printf("\n사다리꼴 높이 입력: ");
	scanf("%lf", &p_tra->height); // height가 있는곳의 주소 가리키는 것임
}

double getArea(const trapezoid* ptr) {
	return (ptr->top + ptr->base) * ptr->height / 2;
}
