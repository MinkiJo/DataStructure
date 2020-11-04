//2016115921 조민기
// 본인은 이 소스파일을 복사 없이 직접 작성하였습니다.

#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 101
#define MAX_COL 10

typedef struct {
	int col;
	int row;
	int value;
}term;

term a[MAX_TERMS];
term b[MAX_TERMS];

void fastTranspose(term a[], term b[]) {
	
	int rowTerms[MAX_COL];
	int startingPosition[MAX_COL];
	int i,j,numCols = a[0].col, numTerms = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;	
	
	for (i = 0; i < numCols; i++) {
		rowTerms[i] = 0;
	}
	for (i = 1; i <= numTerms; i++) {
		rowTerms[a[i].col]++;
	}

	startingPosition[0] = 1;

	for (i = 1; i <= numCols; i++) {
		startingPosition[i] = startingPosition[i - 1] + rowTerms[i - 1];
	}

	for (i = 1; i <= numTerms; i++) {
		j = startingPosition[a[i].col]++;
		b[j].row = a[i].col;
		b[j].col = a[i].row;
		b[j].value = a[i].value;
	}
}
/*
void transpose(term a[], term b[])
{
	int n, i, j, currentb;
	n = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = n;
	if (n > 0)
	{
		currentb = 1;
		for (int i = 0;i < a[0].col;i++)
		{
			for (int j = 0;j <= n;j++)
			{
				if (a[j].col == i)
				{
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
	}
}*/
void print(term A[]) //배열  출력
{
	int arr[MAX_COL][MAX_COL] = {0,};
	
	
	for (int i = 0;i <= A[0].value;i++)
	{
		
		arr[A[i].row][A[i].col] = A[i].value;
	}
	for (int i = 0;i < A[0].row;i++)
	{
		for (int j = 0;j < A[0].col;j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	
	
	FILE* fpIn = fopen("input.txt", "r");
	FILE* fpOut = fopen("output.txt", "w");
	
	fscanf(fpIn, "%d",&a[0].col );
	fscanf(fpIn, "%d",&a[0].row );
	fscanf(fpIn, "%d", &a[0].value);
	for (int i = 1;i <= a[0].value;i++)
	{
		fscanf(fpIn, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
	}
	
	printf("A\n");
	print(a);
	fastTranspose(a, b);
	
	
	for (int j = 1;j <= a[0].value-1;j++) //b 오름차순으로 정렬
	{
		for (int i = 1;i <= a[0].value-1;i++)
		{
			if (b[i].col > b[i + 1].col)
			{				
				int temp1, temp2, temp3;
				temp1 = b[i].col, temp2 = b[i].row, temp3 = b[i].value;
				b[i].col = b[i + 1].col, b[i].row = b[i + 1].row, b[i].value = b[i + 1].value;
				b[i+1].col = temp1, b[i+1].row = temp2, b[i+1].value = temp3;
				

			}

			else if (b[i].col == b[i + 1].col)
			{
				if (b[i].row > b[i + 1].row) {
					int temp1, temp2, temp3;
					temp1 = b[i].col, temp2 = b[i].row, temp3 = b[i].value;
					b[i].col = b[i + 1].col, b[i].row = b[i + 1].row, b[i].value = b[i + 1].value;
					b[i + 1].col = temp1, b[i + 1].row = temp2, b[i + 1].value = temp3;
					
				}
			}
		}
	}

	printf("\nB\n");
	print(b);
	
	
	for (int i = 0;i <= a[0].value;i++)
	{
		fprintf(fpOut, "%d %d %d\n", b[i].col, b[i].row, b[i].value);
	}

	fclose(fpIn);
	fclose(fpOut);
}