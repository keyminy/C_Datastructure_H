#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node {
	int value;
	struct node* next;
} node;

node* head = NULL;
node* tail = NULL;

void standby(int n);

int main() {
	int n, kill;
	printf("처형을 기다리는 사람은 몇 명 입니까? ");
	scanf("%d", &n);
	while (getchar() != '\n');

	printf("몇 번째 사람을 처형 하시겠습니까? ");
	scanf("%d", &kill);
	while (getchar() != '\n');

	standby(n);
	return 0;
}

void standby(int n)
{

}
