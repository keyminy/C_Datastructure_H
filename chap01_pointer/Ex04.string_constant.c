#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main() {
	// 포인터가 가리키는 대상이 문자열상수이므로 const를 붙임
	// 포인터를 상수화시키면, 포인터로 참조하는 메모리를 수정할 수 없음.
	const char* p = "Hello";
	printf("%p\n", p);
	// %s : p가가진 주소부터, NULL('\0')이전까지 출력하라
	printf("%s\n", p); // Hello
	printf("%s\n", p+2); // llo

	//printf("%s\n", *p); // error
	// %s는 주소값을 넣어야함

	// 역참조 표현 m1
	printf("%c\n", *p); // H
	printf("%c\n", *(p+1)); // e
	// 역참조 표현 m2
	printf("%c\n", p[0]); // H
	printf("%c\n", p[1]); // e
	return 0;
}