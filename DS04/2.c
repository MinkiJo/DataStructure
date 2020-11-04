#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define MAX_SIZE 2001

void sel_Sort(int list[], int size);
int compare(int x, int y);
void swap(int* x, int* y);

void sel_Sort(int list[], int size)
{
	for (int i = 0;i < size - 1;i++) 
		
		for (int j = i + 1;j < size;j++) {

			if (compare(list[i], list[j]) == 0)  swap(&list[i], &list[j]);
		}
	
}
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


int main()
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;
	FILE* fp = fopen("output.txt", "w");
	fprintf(fp, "     n     repetitions    time\n");
	for (n = 0; n <= 2000; n += step)
	{
		long repetitions = 0;
		start = clock();
		do {
			repetitions++;
			for (i = 0;i < n;i++)
				a[i] = n - 1;


			sel_Sort(a, n);
		} while (clock() - start < 1000);
		duration = ((double)(clock() - start)) / (CLOCKS_PER_SEC);

		duration /= repetitions;
		fprintf(fp, "%6d   %9d   %f\n", n,repetitions, duration);
		if (n == 100) step = 100;

	}

}