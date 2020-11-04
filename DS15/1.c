//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
	int key;
}element;

element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int* n)
{
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full");
		exit(EXIT_FAILURE);
	}
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap [i / 2];
		i /= 2;
	}
	heap[i] = item;
}

element pop(int* n)
{
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty\n");
		exit(EXIT_FAILURE);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n)
	{
		if ((child < *n) && (heap[child].key<heap[child+1].key))
		{
			child++;
		}
		if (temp.key >= heap[child].key) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
void print()
{
	for (int i = 1;i <= n;i++)
	{
		printf("%d  ", heap[i].key);
	}
	printf("\n");
}
int main()
{
	FILE* fp = fopen("input.txt", "r");

	printf("*****insertion into a max heap*****\n");
	element a;
	while (!feof(fp)) {
		fscanf(fp, "%d", &a.key);
		push(a, &n);
		print();
	}

	printf("*****insertion into a max heap*****\n");
	
	int count = n;
	for (int i = 0;i < count;i++)
	{
		pop(&n);
		print();
	}

	fclose(fp);

}