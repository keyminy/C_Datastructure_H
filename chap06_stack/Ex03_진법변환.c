#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

#pragma warning (disable : 4996)

typedef struct node {
	int value;
	struct node* next;
} node;

int main() {
	node* head = NULL;
	int n;

	printf("10진수를 입력 하세요: ");
	scanf("%d", &n);
	while (getchar() != '\n');

	binaryConversion(n);
	return 0;
}