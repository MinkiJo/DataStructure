//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#include<stdio.h>
#include<stdlib.h>


int sumAry3D_f1(int ary3D[][2][3], int a, int b,int c) {
	int sum = 0;	
	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			for (int k = 0;k < c;k++)
			{
				sum = sum + ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f2(int(*ary3D)[2][3], int a, int b, int c) {
	int sum = 0;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			for (int k = 0;k < c;k++)
			{
				sum = sum + ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f3(int ary3D[2][2][3], int a, int b, int c) {
	int sum = 0;;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			for (int k = 0;k < c;k++)
			{
				sum = sum + ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f4(int ***ary3D, int a, int b, int c)
{
	int sum = 0;;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			for (int k = 0;k < c;k++)
			{
				sum = sum + ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f5(int ****ary3D, int a, int b, int c) {
	int sum = 0;;

	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			for (int k = 0;k < c;k++)
			{
				sum = sum + (*ary3D)[i][j][k];
			}
		}
	}
	return sum;
}
void freeAry3D(int*** ary, int n, int m) {
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			free(ary[i][j]);
		}
	}
	printf("3d array - free!");
}


int main()
{
	int ary3D[][2][3] = { {{1, 2, 3}, {4, 5, 6}},{{7, 8, 9}, {10, 11, 12} } };
	int i,j,k;

	int*** ary = (int***)malloc(sizeof(int**) * 2);
	
	for (i = 0;i < 2;i++)
	{
		ary[i] = malloc(sizeof(int*) * 2);
	}

	
	for (j = 0;j < 2;j++)
	{	
		for (int k = 0;k < 2;k++)
		{
			ary[j][k] = malloc(sizeof(int) * 3);
		}
	}

	for (int i = 0;i < 2;i++)
	{
		for (j = 0;j < 2;j++)
		{
			for (int k = 0;k < 3;k++)
			{
				ary[i][j][k] = i + j + k;  //임의의 값
			}
		}
	}
	printf("sumAry3D_f1() %d\n", sumAry3D_f1(ary3D, 2,2, 3));
	printf("sumAry3D_f2() %d\n", sumAry3D_f2(ary3D, 2,2, 3));
	printf("sumAry3D_f3() %d\n", sumAry3D_f3(ary3D, 2,2, 3));

	printf("sumAry3D_f4() %d\n", sumAry3D_f4(ary, 2, 2,3));
	printf("sumAry3D_f5() %d\n", sumAry3D_f5(&ary, 2, 2,3));

	freeAry3D(ary, 2,2);

	/*메모리 해제 확인
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			for (int k = 0;k < 3;k++)
			{
				printf(" %d", ary[i][j][k]);
			}
		}
		printf("\n");
	}
	*/

}