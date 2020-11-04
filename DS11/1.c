//2016115921
//본인은 이 소스파일을 복사없이 직접 작성했습니다.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COMPARE(x,y)(((x) < (y))? -1: ((x) == (y))? 0 :1)
#define MALLOC(p,s) p = malloc(s)
typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;
polyPointer a, b;

void attach(int coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}

polyPointer padd(polyPointer a, polyPointer b)
{
	polyPointer c, rear, temp;
	int sum;
	MALLOC(rear, sizeof(*rear));
	c = rear;
	while (a && b)
	{
		switch (COMPARE(a->expon, b->expon)) {
		case -1:
			attach(b->coef, b->expon, &rear);
			b = b->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum) attach(sum, a->expon, &rear);
			a = a->link; b = b->link;
			break;
		case 1:
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	}
	for (;a;a = a->link) attach(a->coef, a->expon, &rear);//나머지부분
	for (;b;b = b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	temp = c; c = c->link; free(temp);
	return c;
}

void insert(polyPointer* ptr, polyPointer x, int coefficient, int exponent, char c) {
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	if (c == 'a') {

		if ((*ptr) == NULL)
		{	
			temp->link = NULL;
			*ptr = temp;			
		}
		else {

			temp->link = *ptr;
			*ptr = temp;
		}
	}

	else if (c == 'd') {

		if ((*ptr) == NULL)
		{
			temp->link = NULL;
			*ptr = temp;
		}
		else {
			temp->link = x->link;
			x->link = temp;
		}
	}
}

polyPointer findLast(polyPointer* ptr)
{
	polyPointer p = *ptr;
	if (*ptr == NULL)
	{ // empty list
		return *ptr;
	}
	else {
		while (p->link != NULL)
			p = p->link;
		return p;
	}
}

void inputPoly(int coefficient, int exponent, polyPointer* ptr, char c)
{
	polyPointer x = findLast(ptr);
	insert(ptr, x, coefficient, exponent, c);
}
void printList(polyPointer ptr){

	for (;ptr;ptr = ptr->link)
		printf("%+dx^%d ", ptr->coef, ptr->expon);
	printf("\n");
}

void erase(polyPointer* ptr)
{
	polyPointer temp;
	while (*ptr) {
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}
int main()
{

	FILE* fa = fopen("a.txt", "r");
	FILE* fb = fopen("b.txt", "r");
	char p;
	int coef;
	int exp;
	fscanf(fa, "%c", &p); //a 다항식 만들기
	while (!feof(fa)) {
		fscanf(fa, "%d %d", &coef, &exp);
		inputPoly(coef, exp, &a, p);
	}

	fscanf(fb, "%c", &p); //b다항식 만들기
	while (!feof(fb)) {
		fscanf(fb, "%d %d", &coef, &exp);
		inputPoly(coef, exp, &b, p);
	}

	printf("a:   ");
	printList(a);
	
	printf("b:   ");
	printList(b);

	printf("c:   "); //c다항식 만들기
	polyPointer c = padd(a, b);
	printList(c); 

	erase(&a); erase(&b); erase(&c); //다항식 모두 삭제
	
	fclose(fa);
	fclose(fb);
}



