#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	// �����Ͱ� ����Ű�� ����� ���ڿ�����̹Ƿ� const�� ����
	// �����͸� ���ȭ��Ű��, �����ͷ� �����ϴ� �޸𸮸� ������ �� ����.
	const char* p = "Hello";
	printf("%p\n", p);
	// %s : p������ �ּҺ���, NULL('\0')�������� ����϶�
	printf("%s\n", p); // Hello
	printf("%s\n", p+2); // llo

	//printf("%s\n", *p); // error
	// %s�� �ּҰ��� �־����

	// ������ ǥ�� m1
	printf("%c\n", *p); // H
	printf("%c\n", *(p+1)); // e
	// ������ ǥ�� m2
	printf("%c\n", p[0]); // H
	printf("%c\n", p[1]); // e
	return 0;
}