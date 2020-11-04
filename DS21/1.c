//2016115921
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다    
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) t =x; x=y; y=t
typedef struct {
	int key;
}element;
int count = 1;
void heapSort(element a[], int n);
void adjust(element a[], int root, int n);
void print(element a[], int n);
void heapSort(element a[], int n)
{
	int i, j;
	element temp;
	for (i = n / 2;i > 0;i--)
		adjust(a, i, n);
	printf("after initialization of max heap...\n");
	print(a, n);
	printf("\n");
	for (i = n - 1;i > 0;i--) {
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);

		printf("step  %d: ", n-i);
		print(a, n);
	}
}

void adjust(element a[], int root, int n)
{
	int child, rootkey;
	 
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root; 
	while (child <= n) {
		if ((child < n) && (a[child].key < a[child + 1].key))
			child++;
		if (rootkey > a[child].key)
			break;
		else {
			a[child / 2] = a[child];
			child *= 2;
		}
		
	}
	a[child / 2] = temp;
	
}
void print(element a[],int n)
{
	for (int i = 1;i <= n;i++)
		printf(" %d ", a[i].key);
	printf("\n");
}
int main()
{
	element a[100];
	int n;
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");
	fscanf(fin, "%d", &n);
	for (int i = 1;i <= n;i++)
	{
		fscanf(fin, "%d", &a[i].key);
	}

	printf("<<<<<<<<<<Input List>>>>>>>>>>\n");
	print(a, n);

	printf("\n<<<<<<<<<<executing heap sort>>>>>>>>>>\n");
	heapSort(a, n);

	printf("\n<<<<<<<<<<Sorted List>>>>>>>>>>\n");
	for (int i = 1;i <= n;i++) { //최종결과출력
		printf("%d ", a[i].key);
		fprintf(fout, "%d ", a[i].key);
	}
}