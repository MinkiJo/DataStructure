//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct element {
	int key;	
}element;

void merge(element initList[], element mergedList[], int i, int m, int n)
{
	int j, k, t;
	j = m + 1;
	k = i;

	while (i <= m && j <= n)
	{
		if (initList[i].key <= initList[j].key)
			mergedList[k++] = initList[i++];
		else
			mergedList[k++] = initList[j++];
	}
	if (i > m)
		for (t = j;t <= n;t++)
			mergedList[k++] = initList[t];
	else
		for (t = i;t <= m;t++)
			mergedList[k++] = initList[t];
}

void mergePass(element initList[], element mergedList[], int n, int s)
{
	printf("segment size : %d \n", s);

	int i, j;
	for (i = 1;i <= n - 2 * s + 1;i += 2 * s)
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
	//printf("%d", i);
	if (i + s - 1 < n)
		merge(initList, mergedList, i, i + s - 1, n);
	else
		for (j = i;j <= n;j++)
			mergedList[j] = initList[j];

	
}

void mergeSort(element a[], int n)
{
	int s = 1;
	element extra[MAX_SIZE];
	while (s < n) {
		mergePass(a, extra, n, s);
		s *= 2;

		printf("    a : ");
		for (int i = 1;i <= n;i++)
		{
			printf("%d ", a[i].key);
		}printf("\n");
		printf("    extra : ");
		for (int i = 1;i <= n;i++)
		{
			printf("%d ", extra[i].key);
		}printf("\n");

		mergePass(extra, a, n, s);
		s *= 2;

		printf("    extra : ");
		for (int i = 1;i <= n;i++)
		{
			printf("%d ", extra[i].key);
		}printf("\n");
		printf("    a : ");
		for (int i = 1;i <= n;i++)
		{
			printf("%d ", a[i].key);
		}printf("\n");
		
	}
}

int main()
{
	int n;
	element a[MAX_SIZE];
	FILE* fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	for (int i = 1;i <= n;i++)
	{
		fscanf(fp, "%d", &a[i].key);
	}
	printf("<<<<<<<<<<Input List>>>>>>>>>>\n");
	for (int i = 1;i <= n;i++)
	{
		printf("%d ", a[i].key);
	}printf("\n\n");



	printf("<<<<<<<<<<executing itterative mertge sort>>>>>>>>>>\n");
	mergeSort(a, n);


	printf("<<<<<<<<<<Sorted List>>>>>>>>>>\n");
	for (int i = 1;i <= n;i++)
	{
		printf("%d ", a[i].key);
	}
}