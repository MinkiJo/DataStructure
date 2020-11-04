//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define MALLOC(p,s) if (!((p) = malloc(s))) {fprintf(stderr, "Insufficient memory");exit(EXIT_FAILURE);}
void add(int **a, int **b, int **c, int rows, int cols)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	

}
int** make2dArray(int rows, int cols)
{
	int** x, i;
	MALLOC(x, rows * sizeof(*x));
	for (int i = 0;i < rows;i++)
	{
		MALLOC(x[i], cols * sizeof(**x));		
	}
	return x;
}
int main()
{
	int**A = make2dArray(3, 7);
	int**B = make2dArray(3, 7);
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 7;j++)
		{
			A[i][j] = i + j+1;
			B[i][j] = i + j+2;
		}
	}
	printf("\nmaxtrix A\n");
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 7;j++)
		{
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
	printf("\nmaxtrix B\n");
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 7;j++)
		{
			printf("%3d", B[i][j]);
		}
		printf("\n");
	}
	
	int** C = make2dArray(3, 7);
	add(A, B, C, 3, 7);

	
	
	printf("\nmaxtrix C\n");
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 7;j++)
		{
			printf("%3d",C[i][j]);
		}
		printf("\n");
	}
	
	//동적할당 해제
	for (int i = 0;i < 3;i++) free(A[i]);
	for (int i = 0;i < 3;i++) free(B[i]);
	for (int i = 0;i < 3;i++) free(C[i]);
	

}