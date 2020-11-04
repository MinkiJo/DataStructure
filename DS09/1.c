#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;
char expr[MAX_STACK_SIZE];

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;


void push(int n)
{
	stack[++top] = n;
}
int pop()
{
	 return stack[top--];
}
int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while(token != eos)
	{
		if (token == operand)
			push(symbol - '0');
		else {
			op2 = pop();
			op1 = pop();
			switch (token) {
			case plus: push(op1 + op2);
				break;
			case minus: push(op1 - op2);
				break;
			case times: push(op1 * op2);
				break;
			case divide: push(op1 / op2);
				break;
			case mod: push(op1 % op2);
				break;
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
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


int main()
{
	
	printf("postfix expression:");

	scanf("%s", expr);
	printf("the evalutation value :");
	printf("%d", eval());
		

}