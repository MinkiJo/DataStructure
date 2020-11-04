//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#include<stdio.h>
#include<stdlib.h>

int sumAry2D_f1(int ary2D[][3], int a, int b) {
	int sum=0;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			sum = sum + ary2D[i][j];
		}
	}
	return sum;
}
int sumAry2D_f2(int (*ary2D)[3], int a, int b) {
	int sum = 0;;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			sum = sum + ary2D[i][j];
		}
	}
	return sum;
}
int sumAry2D_f3(int ary2D[2][3], int a, int b) {
	int sum = 0;;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			sum = sum + ary2D[i][j];
		}
	}
	return sum;
}
int sumAry2D_f4(int** ary2D, int a, int b)
{
	int sum = 0;;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			sum = sum + ary2D[i][j];
		}
	}
	return sum;
}
int sumAry2D_f5(int ***ary2D, int a, int b) {
	int sum = 0;;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			sum = sum + (*ary2D)[i][j];
		}
	}
	return sum;
}
void freeAry2D(int** ary, int n) {
	
	for (int i = 0;i < n;i++) free(ary[i]);	
	printf("2d array - free!");
}


int main()
{
	int ary2D[][3] = { {1,2,3}, {4,5,6} };
	int r, c;

	int** ary = (int**)malloc(sizeof(int*) * 2);
		for (r = 0;r < 2;r++)
		{
			ary[r] = malloc(sizeof(int) * 3);
		}
		for (r = 0;r < 2;r++)
		{
			for (int c = 0;c < 3;c++)
			{
				ary[r][c] = r + c; //0,1,2,1,2,3
			}
		}
		printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, 2, 3));
		printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, 2, 3));
		printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, 2, 3));

		printf("sumAry2D_f4() %d\n", sumAry2D_f4(ary, 2, 3));
		printf("sumAry2D_f5() %d\n", sumAry2D_f5(&ary, 2, 3));

		freeAry2D(ary, 2);

		/*메모리해제 확인
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				printf(" %d", ary[i][j]);
			}
			printf("\n");
		}
		*/
		
}