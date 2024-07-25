#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int binarySearch(int* arr,int left, int right,int target);
int binarySearchLoop(int* arr,int left, int right,int target);

int main() {
	int arr[10] = { 5,6,7,8,9,10,11,12,13,14};
	int target,index;
	printf("\n찾는 값 입력 : ");
	scanf("%d", &target);

	// 찾는 값이 존재하면, 찾는 값이 저장된 인덱스를 리턴
	// 찾는 값이 존재하지 않는 경우 -1을 리턴
	//index = binarySearch(arr, 0, 9, target);
	index = binarySearchLoop(arr, 0, 9, target);
	if (index == -1)
		printf("\n\n\t\t찾는 값이 존재하지 않습니다.\n");
	else
		printf("\n\n\t\t찾는 값은 arr[%d]번째에 존재합니다.\n", index);
	return 0;
}


int binarySearch(int* arr, int left, int right, int target)
{
	int mid;
	/* 못 찾았을때 */
	if (left > right) {
		return -1;
	}
	mid = (left + right) / 2;
	if (arr[mid] == target) {
		return mid; // 찾는 값의 인덱스를 리턴해준다.
	}
	else if (arr[mid] < target) {
		// 찾는 값이 더 크다(오른쪽에 있음)
		//left = mid + 1;
		// 재귀호출로 표현하기(오른쪽으로 재귀호출)k
		return binarySearch(arr,mid+1,right,target);
	}
	else {
		// 왼쪽으로 재귀호출하기
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
			return mid; // 찾는 값의 인덱스를 리턴해준다.
		}
		else if (arr[mid] < target) {
			// 찾는 값이 더 크다(오른쪽에 있음)
			left = mid + 1; // 오른쪽 값을 변경
		}
		else {
			// 왼쪽으로 재귀호출하기
			right = mid - 1;
		}
	}
	return -1; // left > right일때 찾는 값 없다
}