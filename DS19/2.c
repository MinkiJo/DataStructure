//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다.
#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) =(t))
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count = 0;

typedef struct element {
	int key;
	char name[10];
	int grade;
}element;

void print(element arr[], int n)
{
	for (int i = 1;i <= n;i++)
	{
		printf("%d  ", arr[i].key);
	}printf("\n");
}
void quickSort(element a[], int left, int right,int n)
{
	int pivot, i, j;
	element temp;
	print(a, n); count++;
	if (left < right) {
		i = left; j = right+1;
		pivot = a[left].key;
		do {
			
			do i++; while (a[i].key < pivot);
			do j--; while (a[j].key > pivot);
			if (i < j) SWAP(a[i], a[j], temp);
		} while (i < j);
		SWAP(a[left], a[j], temp);
		quickSort(a, left, j - 1,n);
		quickSort(a, j + 1, right,n);

	}
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	int n;
	element arr[100];
	fscanf(fin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(fin, "%d", &arr[i].key);
	}
	printf("<<<<<<<<<<Input List>>>>>>>>>>\n");
	print(arr, n);
	printf("\n<<<<<<<<<<executionof quick sortx...>>>>>>>>>>\n");
	quickSort(arr, 1, n,n);
	printf("calls of quick sort: %d\n\n", count);
	printf("<<<<<<<<<<Sorted List>>>>>>>>>>\n");
	print(arr, n);

	FILE* fout = fopen("output.txt", "w");
	fprintf(fout, "%d\n", n);
	for (int i = 1;i <= n;i++)
	{
		fprintf(fout, "%d  ", arr[i].key);
	}
	

	
	
}