//2016115921 조민기
// 본인은 이 소스파일을 복사 없이 직접 작성하였습니다.
#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100
#define COMPARE(x,y)(((x) < (y))? -1: ((x) == (y))? 0 :1)
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS]; //다항식 입력배열
polynomial terms_result[MAX_TERMS]; //다항식 출력배열

int avail = 0;
void padd(int  startA, int finishA, int startB, int finishB, int* startD, int* finishD);
void attatch(float coefficient, int exponent);
void padd(int  startA, int finishA, int startB, int finishB, int* startD, int* finishD)
{
	float coefficient;
	*startD = avail;

	while (startA <= finishA && startB <= finishB)
	{
		switch (COMPARE(terms[startA].expon, terms[startB].expon)) {
		case -1:
			attatch(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
			{
				attatch(coefficient, terms[startA].expon);
				
			}

			startA++;
			startB++;
			break;
		case 1:
			attatch(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	}
		for (;startA <= finishA; startA++)
			attatch(terms[startA].coef, terms[startA].expon);
		for (;startB <= finishB; startB++)
			attatch(terms[startB].coef, terms[startB].expon);
		*finishD = avail - 1;
}



void attatch(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS)	{

		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms_result[avail].coef = coefficient;
	terms_result[avail++].expon = exponent;
}
void print(int start, int finish, FILE*fp,polynomial*terms) //다항식 결과출력
{
	for (int i = start;i <finish ;i++)
	{
		if (terms[i].expon == 0) {
			fprintf(fp, "%.1f", terms[i].coef);
			
		}
		fprintf(fp, "%.1f", terms[i].coef);
		fprintf(fp, "x^%d +", terms[i].expon);
		
	}	
	if (terms[finish].expon == 0)
	{
		fprintf(fp, "%.1f", terms[finish].coef);
	}
	else {
		fprintf(fp, "%.1f", terms[finish].coef);
		fprintf(fp, "x^%d", terms[finish].expon);
	}
	
}
int main()
{
	int n, m;	

	int result[MAX_TERMS];
	FILE* fpIn = fopen("input.txt", "r");
	FILE* fpOut = fopen("output.txt", "w");

	fscanf(fpIn, "%d", &n);
	fscanf(fpIn, "%d", &m);

	int startD, finishD;
	
	for (int i = 0;i < n;i++)
	{
		fscanf(fpIn, "%f", &terms[i].coef);
		fscanf(fpIn, "%d", &terms[i].expon);
	}
	
	for (int i = 0;i < m;i++)
	{
		fscanf(fpIn, "%f", &terms[i + n].coef);
		fscanf(fpIn, "%d", &terms[i + n].expon);
	}
	fprintf(fpOut,"two input polynomials\n");
	fprintf(fpOut, "A<x>:");
	print(0, n-1, fpOut,terms);
	fprintf(fpOut, "\n");
	fprintf(fpOut, "B<x>:");
	print(n, n+m-1, fpOut,terms);

	padd(0, n - 1, n, n + m - 1, &startD, &finishD);
	fprintf(fpOut,"\n\nthe result of polynominal addition\n");
	fprintf(fpOut, "D<x>:");
	print(startD, finishD, fpOut,terms_result);
	
	
	fclose(fpIn);
	fclose(fpOut);
		
}