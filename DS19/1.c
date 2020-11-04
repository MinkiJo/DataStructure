//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct element {
	int key;
	char name[10];
	int grade;
}element;


void insert(element e, element a[], int i)
{
	a[0] = e;
	while (e.key < a[i].key)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}

void insertionSort(element a[], int n)
{
	int j;
	for (j = 2;j <= n;j++) {
		element temp = a[j];
		insert(temp, a, j - 1);
	}
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	int n;
	element arr[10];
	fscanf(fin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(fin, "%d %s %d", &arr[i].key, arr[i].name,&arr[i].grade);
	}

	printf("<<<<<<<<<<Input List>>>>>>>>>>\n");
	for (int i = 1;i <= n;i++)
	{
		printf("(%d, %s, %d)\n", arr[i].key,arr[i].name,arr[i].grade);
	}

	FILE*fout = fopen("output.txt", "w");
	insertionSort(arr, n);
	printf("\n<<<<<<<<<<Output List>>>>>>>>>>\n");
	for (int i = 1;i <= n;i++)
	{
		printf("(%d, %s, %d)\n", arr[i].key, arr[i].name, arr[i].grade);
		fprintf(fout,"(%d, %s, %d)\n", arr[i].key, arr[i].name, arr[i].grade);
	}
}