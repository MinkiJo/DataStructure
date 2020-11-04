//학번 : 2016115921 이름 :조민기
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
#include<stdio.h>
int sumAry2D_f1(int ary[][3], int ROW, int COL);
int sumAry2D_f2(int(*ary)[3], int ROW, int COL);
int sumAry2D_f3(int ary[2][3], int ROW, int COL);

int main(void)
{
	int ary2D[][3] = { {1, 2, 3}, {4, 5, 6} };
	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, 2, 3));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, 2, 3));
	printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, 2, 3));
	return 0;
}


int sumAry2D_f1(int ary[][3], int ROW, int COL)
{
	int sum = 0;
	for (int i = 0;i < ROW;i++)
	{
		for (int j = 0;j < COL;j++)
		{
			sum = sum + ary[i][j];
		}
	}
	return sum;
}
int sumAry2D_f2(int(*ary)[3], int ROW, int COL)
{
	int sum = 0;
	for (int i = 0;i < ROW;i++)
	{
		for (int j = 0;j < COL;j++)
		{
			sum = sum + ary[i][j];
		}
	}
	return sum;
}
int sumAry2D_f3(int ary[2][3], int ROW, int COL)
{
	int sum = 0;
	for (int i = 0;i < ROW;i++)
	{
		for (int j = 0;j < COL;j++)
		{
			sum = sum + ary[i][j];
		}
	}
	return sum;
}