//학번 : 2016115921 이름 :조민기
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
#include<stdio.h>

int main()
{
	int count = 1;
	int arr[2][2][3];
	int(*p)[2][3] = arr;
	arr[0][0][0] = 1;
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			for (int k = 0;k < 3;k++)
			{
				arr[i][j][k] = count++;
			}
		}
	}

	printf("ary를 이용한  출력\n");
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			{
				for (int k = 0;k < 3;k++)
				{
					printf("%3d", arr[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}


	printf("p를 이용한  출력\n");
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			{
				for (int k = 0;k < 3;k++)
				{
					printf("%3d", (*(p + i))[j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}

}