//2016115921 조민기
//본인은 이 소스파일을 다른사람의 소스를 복사하지않고 직접 작성하였습니다
#include<stdio.h>
#include<stdlib.h>


int* func1()
{
	return (int*)malloc(sizeof(int));
}
int* func2(int* pNum)
{
	*pNum = 100;
	return pNum;
}
int** func3(int** pNum)
{
	**pNum = 200;
	return pNum;
}
int main()
{
	int* pNum = func1();
	printf("%d\n", *pNum);
	printf("%d\n", *func2(pNum));
	printf("%d\n", **func3(&pNum));
	free(pNum);

	return 0;
}