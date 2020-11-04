//2016115921 조민기
//본인은 이 소스파일을 다른사람의 소스를 복사하지않고 직접 작성하였습니다
#define MAX_SIZE 100
#include<stdio.h>
#include<stdlib.h>



void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols);
void input(int* pNum[][MAX_SIZE], int rows, int cols, FILE* fpIn);
void output(int* pNum[][MAX_SIZE], int rows, int cols, FILE* fpOut);

int count;

int main()
{
	int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
	int rows = 3, cols = 4;

	FILE* fpIn1 = fopen("a.txt", "r");
	FILE* fpIn2 = fopen("b.txt", "r");
	FILE* fpOut = fopen("c.txt", "w");

	input(a, rows, cols, fpIn1);
	input(b, rows, cols, fpIn2);
	add(a, b, c, rows, cols);
	output(c, rows, cols, fpOut);


	fclose(fpIn1);
	fclose(fpIn2);
	fclose(fpOut);
	printf("step count:%d", count);
	return 0;

}

void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols)
{

	for (int i = 0;i < rows;i++)
	{
		count++;
		for (int j = 0;j < cols;j++) {
			count++;
			c[i][j] = a[i][j] + b[i][j];
			count++;
		}
		count++;
	}
	count++;
}
void input(int* pNum[][MAX_SIZE], int rows, int cols, FILE* fpIn)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++) {
			fscanf(fpIn, "%d", &pNum[i][j]);
		}
	}
}

void output(int* pNum[][MAX_SIZE], int rows, int cols, FILE* fpOut)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++) {
			fprintf(fpOut, "%2d", pNum[i][j]);
		}
		fprintf(fpOut, "%\n");
	}
}