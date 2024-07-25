#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int binarySearch(int* arr,int left, int right,int target);
int binarySearchLoop(int* arr,int left, int right,int target);

int main() {
	int arr[10] = { 5,6,7,8,9,10,11,12,13,14};
	int target,index;
	printf("\nã�� �� �Է� : ");
	scanf("%d", &target);

	// ã�� ���� �����ϸ�, ã�� ���� ����� �ε����� ����
	// ã�� ���� �������� �ʴ� ��� -1�� ����
	//index = binarySearch(arr, 0, 9, target);
	index = binarySearchLoop(arr, 0, 9, target);
	if (index == -1)
		printf("\n\n\t\tã�� ���� �������� �ʽ��ϴ�.\n");
	else
		printf("\n\n\t\tã�� ���� arr[%d]��°�� �����մϴ�.\n", index);
	return 0;
}


int binarySearch(int* arr, int left, int right, int target)
{
	int mid;
	/* �� ã������ */
	if (left > right) {
		return -1;
	}
	mid = (left + right) / 2;
	if (arr[mid] == target) {
		return mid; // ã�� ���� �ε����� �������ش�.
	}
	else if (arr[mid] < target) {
		// ã�� ���� �� ũ��(�����ʿ� ����)
		//left = mid + 1;
		// ���ȣ��� ǥ���ϱ�(���������� ���ȣ��)k
		return binarySearch(arr,mid+1,right,target);
	}
	else {
		// �������� ���ȣ���ϱ�
		return binarySearch(arr,left,mid-1,target);
	}
	return 0;
}

int binarySearchLoop(int* arr, int left, int right, int target)
{
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == target) {
			return mid; // ã�� ���� �ε����� �������ش�.
		}
		else if (arr[mid] < target) {
			// ã�� ���� �� ũ��(�����ʿ� ����)
			left = mid + 1; // ������ ���� ����
		}
		else {
			// �������� ���ȣ���ϱ�
			right = mid - 1;
		}
	}
	return -1; // left > right�϶� ã�� �� ����
}