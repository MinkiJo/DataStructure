//2016115921 조민기
//본인은 이 소스파일을 다른사람의 소스를 복사하지않고 직접 작성하였습니다

#include<stdio.h>

int count;
float rsum(float list[], int n)
{

	count++;
	if (n) {
		count++;
		return rsum(list, n - 1) + list[n - 1];
	}
	count++;
	return 0;
}

int main()
{
	float arr[5] = { 1,2,3,4,5 };
	printf("배열 원소의 합:%f\n", rsum(arr, sizeof(arr) / sizeof(float)));
	printf("step count:%d", count);
}