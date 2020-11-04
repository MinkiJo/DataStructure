//2016115921
//본인은 이 소스파일을 복사없이 직접 작성했습니다.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COMPARE(x,y)(((x) < (y))? -1: ((x) == (y))? 0 :1)
#define MALLOC(p,s) p = malloc(s)
#define TRUE 1;
#define FALSE 0;

typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;
polyPointer a, b, c,lastA,lastB, avail = NULL;

polyPointer getNode(void)
{
	polyPointer node;
	if (avail) {
		node = avail;
		avail = avail->link;
	}
	else
		MALLOC(node, sizeof(polyNode));
	return node;
}
void retNode(polyPointer node)
{
	node->link = avail;
	avail = node;
}
void attach(int coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp;
	temp = getNode();
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}
void insertFront2( polyPointer* header,polyPointer* last, int coefficient, int exponent) //헤더노드 바로뒤에 추가
{
	polyPointer node = getNode();	
	node->coef = coefficient;
	node->expon = exponent;

	node -> link= (*header)->link;
	(*header)->link = node;
	if (!(*last)) {
		*last = node;
		(*last)->link = *header;
	}
}
void insertLast(polyPointer* header, polyPointer* last, int coefficient, int exponent) //Last 뒤에 추가
{
	polyPointer node = getNode();
	node->coef = coefficient;
	node->expon = exponent;

	if (!(*last)) {
		*last = node;
		(*header)->link = node;
		node->link = *header;
	}
	else {
		node->link = (*last)->link;
		(*last)->link = node;
		(*last) = node;
	}
}


polyPointer Cpadd(polyPointer a, polyPointer b)
{
	polyPointer startA, c, lastC;
	int sum, done = FALSE;
	startA = a;
	a = a->link; b = b->link;

	c = getNode();
	c->expon = -1;lastC = c;
	do {
		switch (COMPARE(a->expon, b->expon)) {
		case -1:
			attach(b->coef, b->expon, &lastC);
			b = b->link;
			break;
		case 0:
			if (startA == a)
				done = TRUE
			else {
				sum = a->coef + b->coef;
				if (sum) attach(sum, a->expon, &lastC);
				a = a->link; b = b->link;
			}
			break;
		case 1:
			attach(a->coef, a->expon, &lastC);
			a = a->link;
		}
	} while (!done);
	lastC->link = c;
	return c;
}


void inputPolyCL(int coefficient, int exponent, polyPointer* ptr, char c)
{

	if (c == 'a') {
		insertFront2(&a,&lastA,coefficient, exponent);
	}
	else if (c == 'd') {

		insertLast(&b,&lastB, coefficient, exponent);
	}	
}

void printCList(polyPointer ptr)
{
	polyPointer cur = ptr->link;
	for (;cur != ptr; cur = cur->link)
		printf("%+dx^%d ", cur->coef, cur->expon);
	printf("\n");
	
}
/*void printAvail(polyPointer ptr)
{
	polyPointer cur = ptr;
	for (;cur != NULL; cur = cur->link)
		printf("%+dx^%d ", cur->coef, cur->expon);
	printf("\n");

}*/
void erase(polyPointer* ptr)
{
	polyPointer temp;
	while (*ptr) {
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}
void cerase(polyPointer* ptr)
{
	polyPointer temp;
	if (*ptr) {
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}

int main()
{
	
	FILE* fa = fopen("a.txt", "r");
	FILE* fb = fopen("b.txt", "r");
	char p;
	int coef, exp;

	MALLOC(a, sizeof(polyNode));//a,b의 헤더노드 생성
	MALLOC(b, sizeof(polyNode));
	

	fscanf(fa, "%c", &p); //a 다항식 만들기

	while (!feof(fa)) {
		fscanf(fa, "%d %d", &coef, &exp);
		inputPolyCL(coef, exp, &a, p);
	}

	fscanf(fb, "%c", &p); //b다항식 만들기
	while (!feof(fb)) {
		fscanf(fb, "%d %d", &coef, &exp);
		inputPolyCL(coef, exp, &b, p);
	}
	
	printf("a:   ");
	printCList(a);
	printf("b:   ");
	printCList(b);
	printf("c:   ");
	
	polyPointer c;
	c = Cpadd(a, b);
	printCList(c);


	cerase(&a); //a,b,c 다항식을 avail에 연결
	cerase(&b);
	cerase(&c);
	
	//printAvail(avail);
	erase(&avail);	//.모두삭제

	fclose(fa);
	fclose(fb);
	
}
