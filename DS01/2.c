//학번 : 2016115921 이름 :조민기
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
#include<stdio.h>

int main()
{
	int a = 2, b = 3, c = 4;
	int* ary[3] = { &a, &b, &c };
	
	printf("포인터 배열의 배열요소를 이용한 a,b,c출력");printf("\n");
	printf("a:%d  ", *(ary[0]));
	printf("b:%d  ", *(ary[1]));
	printf("c:%d  ", *(ary[2]));
}