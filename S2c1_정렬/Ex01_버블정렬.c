#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

#define ARR_SIZE 100

void randomize(int* arr, int maxSize);
void display(int* arr, int maxSize);
void bubbleSort(int* arr, int maxSize);
void selectionSort(int* arr, int maxSize);
void improvedBubbleSort(int* arr, int maxSize);
void insertionSort(int* arr, int maxSize);

#pragma warning (disable : 4996)

int main()
{
	int arr[ARR_SIZE];
	randomize(arr, ARR_SIZE);
	
	printf("정렬 전 데이터\n");
	display(arr, ARR_SIZE);

	//bubbleSort(arr, ARR_SIZE);
	//improvedBubbleSort(arr, ARR_SIZE);
	//selectionSort(arr, ARR_SIZE);
	insertionSort(arr, ARR_SIZE);

	printf("정렬 후 데이터\n");
	display(arr, ARR_SIZE);
	return 0;
}

void randomize(int* arr, int maxSize)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < maxSize; i++)
	{
		arr[i] = rand() % 999 + 1; // 1 ~ 999
	}
}

void display(int* arr, int maxSize)
{
	for (int i = 0; i < maxSize; i++)
	{
		printf("%5d ", arr[i]);
	}
	puts("");
}

void bubbleSort(int* arr, int maxSize)
{
	for (int i = 0; i < maxSize - 1; i++)
	{
		for (int j = 0; j < maxSize - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 앞의 비교 인덱스의 값이 더 클때
				int temp = arr[j]; 
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int* arr, int maxSize)
{
	int minIdx = 0;
	for (int i = 0; i < maxSize - 1; i++)
	{
		minIdx = i;// 정렬할 대상의 인덱스(i)로 최솟값 인덱스로 설정
		for (int j = i + 1; j < maxSize; j++)
		{
			if (arr[minIdx] > arr[j])
			{
				// 최솟값을 찾음
				minIdx = j;
			}
		}
		if (minIdx != i)
		{
			int temp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = temp;
		}
	}
	printf("\n\n\t\t Selection Sort done!\n");
}

void improvedBubbleSort(int* arr, int maxSize)
{
	int swapped; // 교환 여부를 판별
	for (int i = 0; i < maxSize - 1; i++)
	{
		swapped = 0;
		for (int j = 0; j < maxSize - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 앞의 비교 인덱스의 값이 더 클때
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1; // 값이 교환 됐다면 1로 변경
			}
		}
		if (!swapped)
		{
			break; // break i loop
		 }
	}
	puts("\n\n\t\tImproved Bubble sort done!!\n");
}

void insertionSort(int* arr, int maxSize)
{
	int i, j, temp;
	for (i = 1; i < maxSize; i++)
	{
		// i 루프는 꺼내는 카드를 의미(첫 카드 0번째는 정렬된 상태라고 가정)
		// 카드를 뽑는다!
		temp = arr[i];
		for (j = i; j>0 && arr[j-1] > temp; j--)
		{
			// 비교카드는 뽑은 카드 앞에 있는 카드와 비교한다.
			arr[j] = arr[j - 1]; // 앞에 있는 카드를 뒤로 한칸 미룬다.
		}
		arr[j] = temp; // 최종적으로 찾은 위치에 뽑은 카드 넣기
	}
	puts("\n\n\t\tInsertion Sort done!!\n");
}
