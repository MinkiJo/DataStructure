//2016115921
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다  
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) t =x; x=y; y=t
typedef struct {
	int key;
}element;
int* front,*rear;
int first;
int digit(element a, int i, int r, int d);
int radixSort(element a[], int link[], int d, int r, int n);
void printList(element a[], int link[], int n, int first);
void printQueues(int r);




int digit(element a, int i, int r, int d)
{
	int val = a.key;
	for (int j = 0;j < d - i - 1;j++)
		val /= r;
	return val % 10;
}
int radixSort(element a[], int link[], int d, int r, int n)
{
	front = (int*)malloc(sizeof(int)*r);
	rear = (int*)malloc(sizeof(int) * r);
	int i, bin, current, last;
	first = 1;
	for (i = 1;i < n;i++)
		link[i] = i + 1;
	link[n] = 0;
	printList(a, link, n,first);
	//printQueues(r);
	

	for (i = d - 1;i >= 0;i--){
		for (bin = 0;bin < r;bin++) {
			front[bin] = 0;
			rear[bin] = 0;
		}

		for (current = first;current;current = link[current])
		{
			bin = digit(a[current], i, r,d);
			if (front[bin] == 0) 
				front[bin] = current;
			else link[rear[bin]] = current;
			rear[bin] = current;			

		}

		for (bin = 0;!front[bin];bin++);
		first = front[bin]; last = rear[bin];
		
		for (bin++; bin < r;bin++)
			if (front[bin])
			{
				link[last] = front[bin]; last = rear[bin];
			}
		link[last] = 0;
		printf("********************pass %d********************\n",d-i);
		printList(a, link, n,first);
		printQueues(r);
	



	}
	return first;
}

void printList(element a[], int link[], int n, int first)
{	
	printf("     ");
	for (int i = 1;i <=n;i++)
		printf("[%d] ", i);
	printf("\n");

	printf("link: ");
	for (int i = 1;i <= n;i++)
	{
		printf("%2d  ", link[i]);
	}printf("\n");
	printf("   a:");
	for (int i = 1;i <= n;i++)
	{
		printf(" %2d ", a[i].key);
	}printf("\n");

	printf("first:  %d\n\n", first);

	printf("result:");
	for (int i = first;i != 0;i = link[i])
		printf("%2d  ", a[i].key);
	printf("\n\n");
	
}
void printQueues(int r)
{
	printf("       ");
	for (int i = 0;i < r;i++)
		printf("[%d] ", i);
	printf("\n");
	printf(" rear: ");
	for (int i = 0;i < r;i++)
	{
		printf("%2d  ", rear[i]);
	}printf("\n");
	printf("front: ");
	for (int i = 0;i < r;i++)
	{
		printf("%2d  ", front[i]);
	}printf("\n");
	
}

int main()
{
	element a[100];
	int d,n;
	int link[100];
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");
	fscanf(fin, "%d", &d);
	fscanf(fin, "%d", &n);
	for (int i = 1;i <= n;i++)
	{
		fscanf(fin, "%d", &a[i].key);
	}

	printf("<<<<<<<<<Initial chain>>>>>>>>>>\n");
	
	radixSort(a, link, d, 10, n); //r =10
	

	for (int i = first;i != 0;i = link[i])
		fprintf(fout,"%d ", a[i].key);
	
	
}