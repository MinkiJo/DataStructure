//2016115921 조민기
//본인은 이 소스파일을 다른사람의 소스를 복사하지않고 직접 작성하였습니다
#include<stdio.h>

void swap1(int p1, int p2);
void swap2(int* p1, int* p2);
void swap3(int** p1, int** p2);

int main()
{
	int a, b;
	int* pa = &a;
	int** ppa = &pa;
	int* pb = &b;
	int** ppb = &pb;

	printf("After calling swap1<a,b>, ");
	a = 1;b = 2;
	swap1(a, b);
	printf("a:%d  b:%d\n", a, b);

	printf("After calling swap1<&a,&b>, ");
	a = 1;b = 2;
	swap2(&a, &b);
	printf("a:%d  b:%d\n", a, b);

	printf("After calling swap1<pa,pb>, ");
	a = 1;b = 2;
	swap2(pa, pb);
	printf("a:%d  b:%d\n", a, b);

	printf("After calling swap1<&pa,&pb>, ");
	a = 1;b = 2;
	swap3(&pa, &pb);
	printf("a:%d  b:%d\n", a, b);

	printf("After calling swap1<ppa,ppb>, ");
	a = 1;b = 2;
	swap3(ppa, ppb);
	printf("a:%d  b:%d\n", a, b);

	return 0;

}

void swap1(int p1, int p2)
{
	int temp = p1;
	p1 = p2;
	p2 = temp;
}
void swap2(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void swap3(int** p1, int** p2)
{
	int temp = **p1;
	**p1 = **p2;
	**p2 = temp;
}