//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct element {
	int key;
}element;
int n;
int listMerge(element a[], int link[], int start1, int start2);
int rmergeSort(element a[], int link[], int left, int right);
void print(element a[], int link[], int n);

int rmergeSort(element a[], int link[], int left, int right) {
	int mid;
	printf("rmergeSort(a, link, %d, %d)\n", left, right);
	if (left >= right) return left;
	mid = (left + right) / 2;
	return listMerge(a, link, rmergeSort(a, link, left, mid), rmergeSort(a, link, mid + 1, right));
}

int listMerge(element a[], int link[], int start1, int start2) {
	int last1, last2, lastResult = 0;
	for(last1 = start1, last2 = start2;last1&&last2;)
		if (a[last1].key <= a[last2].key) {
			link[lastResult] = last1;
			lastResult = last1; last1 = link[last1];
		}
		else {
			link[lastResult] = last2;
			lastResult = last2; last2 = link[last2];
		}
	if (last1 == 0) link[lastResult] = last2;
	else link[lastResult] = last1;

	printf("\nlistMerged(a,link,%d, %d)\n", start1, start2);
	print(a, link, n);

	return link[0];
}
void print(element a[], int link[], int n) {
	printf("     ");
	for (int i = 0;i <= n;i++)
	{
		printf("[%2d]", i);
	}printf("\nlink: ");

	for (int i = 0;i <= n;i++)
	{
		printf("%2d  ", link[i]);
	}printf("\na:    ");

	for (int i = 0;i <= n;i++)
	{
		if (a[i].key == 0)
			printf("-   ");
		else printf("%2d  ", a[i].key);
	}printf("\n\n");

}
void printarr(element a[], int link[], int i, int count) {
	
	if (count == 0)
		return;
	printf("%d ", a[link[i]].key);
	count--;
	printarr(a, link, link[i], count);

}
int main()
{
	
	element a[MAX_SIZE] = { 0 };
	int link[MAX_SIZE] = { 0 };
	FILE* fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	for (int i = 1;i <= n;i++)
	{
		fscanf(fp, "%d", &a[i].key);
	}
	printf("<<<<<<<<<<starting from initial %d chains>>>>>>>>>>\n", n);
	print(a, link,n);

	printf("<<<<<<<<<<executing recursive merge sort>>>>>>>>>>\n");
	rmergeSort(a,link,1,n);


	printf("<<<<<<<<<<Sorted List>>>>>>>>>>\n");
	printarr(a, link,0,10);



}