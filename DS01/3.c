//학번 : 2016115921 이름 :조민기
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
#include<stdio.h>

int sumAry1D_f1(int ary[], int size);
int sumAry1D_f2(int* ary, int size);
int sumAry1D_f3(int ary[6], int size);

int main()
{
	int ary1D[] = { 1,2,3,4,5,6 };
	printf("sumAry1D_f1() %d\n", sumAry1D_f1(ary1D, sizeof(ary1D) / sizeof(int)));
	printf("sumAry1D_f1() %d\n", sumAry1D_f2(ary1D, sizeof(ary1D) / sizeof(int)));
	printf("sumAry1D_f1() %d\n", sumAry1D_f3(ary1D, sizeof(ary1D) / sizeof(int)));
}
int sumAry1D_f1(int ary[], int size) {
	int sum = 0;
	for (int i = 0;i < size; i++)
	{
		sum = sum + ary[i];
	}
	return sum;
}
int sumAry1D_f2(int* ary, int size)
{
	int sum = 0;
	for (int i = 0;i < size; i++)
	{
		sum = sum + ary[i];
	}
	return sum;
}
int sumAry1D_f3(int ary[6], int size) {
	int sum = 0;
	for (int i = 0;i < size; i++)
	{
		sum = sum + ary[i];
	}
	return sum;
}