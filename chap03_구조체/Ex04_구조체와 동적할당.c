#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct point {
	int x, y;
} point;

int main() {
	//point p1; // �����Ҵ� : ������ ������, �Ҵ�� �޸��� ũ�⸦ ����
	point* ptr;
	ptr = (point*)malloc(sizeof(point)); // ���� �߿� 4byte�޸𸮰� �Ҵ��
	ptr->x = 3;
	ptr->y = 5;

	printf("p1(%d, %d)\n", ptr->x, ptr->y);
	//free(������); // �����Ͱ� �����ϴ� �޸𸮸� ����
	free(ptr);
	return 0;
}