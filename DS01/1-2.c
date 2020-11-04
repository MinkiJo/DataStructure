//학번 : 2016115921 이름 :조민기
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
#include<stdio.h>

int main()
{
	int arr[2][3] = { {4,2,3},{5,2,3} };
	int(*p)[3] = arr;


	printf("ary를 이용한  출력\n");
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	printf("p를 이용한  출력\n");

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d", (*(p + i))[j]);
		}
		printf("\n");
	}
}