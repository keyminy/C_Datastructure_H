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
	printf("ó���� ��ٸ��� ����� �� �� �Դϱ�? ");
	scanf("%d", &n);
	while (getchar() != '\n');

	printf("�� ��° ����� ó�� �Ͻðڽ��ϱ�? ");
	scanf("%d", &kill);
	while (getchar() != '\n');

	standby(n);
	return 0;
}

void standby(int n)
{

}
