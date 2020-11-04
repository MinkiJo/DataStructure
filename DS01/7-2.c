//학번 : 2016115921 이름 :조민기
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) =(t))
#define COMPARE(x,y)(((x) < (y))? -1: ((x) == (y))? 0 :1)

void sel_Sort(int list[], int size);
int compare(int x, int y);
void swap(int* x, int* y);
int binarySearch(int list[], int start, int end, int value);

void sel_Sort(int list[], int size)
{
	int temp;
	for (int i = 0;i < size - 1;i++)
	{

		for (int j = i + 1;j < size;j++)
		{

			if (COMPARE(list[i], list[j]) == 1)  SWAP(list[i], list[j], temp);

		}
	}
}
/*
int compare(int x, int y)
{
	if (x > y) return 0;
	else return 1;
}
void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
*/

int binarySearch(int list[], int start, int end, int value)
{

	int middle = (end + start) / 2;
	if (list[middle] == value) return middle;
	else if (value < list[middle]) binarySearch(list, start, middle - 1, value);
	else if (value > list[middle]) binarySearch(list, middle + 1, end, value);
	else printf("The search number is not present");

}

int main()
{
	printf("Enter the number of numbers to generate");
	int n;
	scanf("%d", &n);
	int list[MAX_SIZE];
	if (n < 1 || n > MAX_SIZE)
	{
		fprintf(stderr, "Insufficient memory");
		exit(EXIT_FAILURE);
	}

	for (int i = 0;i < n;i++)
	{
		list[i] = rand() % 1000;
		printf("%5d", list[i]);

	}
	printf("\n");
	sel_Sort(list, n);
	printf("Sorted array\n");
	for (int i = 0;i < n;i++)
	{
		printf("%5d", list[i]);
	}
	printf("Enter number to search\n");
	int target;
	scanf("%d", &target);
	printf("The search number is present in list[%d]", binarySearch(list, 0, n - 1, target));

}