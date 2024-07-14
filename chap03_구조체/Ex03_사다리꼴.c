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
	printf("\n��ٸ����� ���̴� %.2f�Դϴ�.\n", getArea(&tra));
	return 0;
}

void input(trapezoid* p_tra) {
	printf("\n��ٸ��� ���� �Է�: ");
	scanf("%lf", &p_tra->top); // top�� �ִ°��� �ּ� ����Ű�� ����
	printf("\n��ٸ��� �غ� �Է�: ");
	scanf("%lf", &p_tra->base); // base�� �ִ°��� �ּ� ����Ű�� ����
	printf("\n��ٸ��� ���� �Է�: ");
	scanf("%lf", &p_tra->height); // height�� �ִ°��� �ּ� ����Ű�� ����
}

double getArea(const trapezoid* ptr) {
	return (ptr->top + ptr->base) * ptr->height / 2;
}
