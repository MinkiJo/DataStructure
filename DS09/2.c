#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100


typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;

int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };

precedence stack[MAX_STACK_SIZE];
int top = -1;
char expr[80];

void push(precedence n)
{
	stack[++top] = n;
}
precedence pop()
{
	return stack[top--];
}


precedence getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos; 
	default: return operand;
	}
}
void printToken(precedence a, FILE*fp)
{
	switch (a)
	{
	case lparen: printf("(");  fprintf(fp, "(");break;
	case rparen: printf(")"); fprintf(fp, ")");break;
	case plus: printf("+"); fprintf(fp, "+");break;
	case minus: printf("-"); fprintf(fp, "-");break;
	case divide: printf("/"); fprintf(fp, "/");break;
	case times: printf("*"); fprintf(fp, "*");break;
	case mod: printf("%"); fprintf(fp, "%");break;
	case eos: printf("\0"); fprintf(fp, "\0");break;
	
	}
}

void postfix(FILE*fp)
{
	char symbol;
	precedence token;
	int n = 0;
	top = 0;
	stack[0] = eos;
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
		{
			printf("%c", symbol);fprintf(fp, "%c", symbol);
		}
		
		else if (token == rparen)
		{
			while (stack[top] != lparen)
				printToken(pop(),fp);
			pop();
		}
		else {
			while (isp[stack[top]] >= icp[token])
				printToken(pop(),fp);
			push(token);
		}
	}

	while ((token = pop()) != eos)
		printToken(token,fp);
	printf("\n");
}

int main()
{
	FILE* fp = fopen("output.txt", "w");
	printf("<<<infix to postfix>>>\n");
	fprintf(fp, "<<<infix to postfix>>>\n");
	printf("infix expression     :");

	scanf("%s", expr);
	printf("postfix expression     :");
	fprintf(fp,"postfix expression     :");
	postfix(fp);


}