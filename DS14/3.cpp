#define _CRT_SECURE_NO_WARNINGS
//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다.

#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define MAX_STACK_SIZE 100

typedef struct node *treePointer;
typedef struct node
{
	char data;		// operator or operand in char type
	bool value;		// boolean
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

treePointer stack[MAX_STACK_SIZE];
int top = -1;
void push(treePointer item);
void stackFull();
treePointer pop();
treePointer stackEmpty();

char expr[81];

typedef enum {
	lparen, rparen, land, lor, lnot, eos, operand
} precedence;
precedence getToken(char *symbol, int *n);
treePointer createBinTree(void);

void perm(int cur, int N);
void postOrderEval(treePointer node);

bool boolean[10];

int main(void)
{
	int result;
	int N;
	FILE *fp;

	if ((fp = fopen("input.txt", "r")) == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	printf("the length of input string should be less than 80\n");
	fgets(expr, 80, fp);
	printf("input string (postfix expression) : %s\n", expr);



	printf("creating its binary tree\n\n");
	root = createBinTree();

	printf("input your the count of variable : ");
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		printf("%c ", 'a' + i);
	}
	perm(0, N);
	printf("\n");

	return 0;
}

/* all possible permutation */
void perm(int cur, int N) {
	if (cur == N) {
		printf("\n");
		for (int i = 0; i < N; i++) {
			if (boolean[i])
				printf("t ");
			else
				printf("f ");
		}

		printf(": ");
		postOrderEval(root);
		if (root->value)
			printf(" TRUE");
		else
			printf(" FALSE");
		return;
	}

	boolean[cur] = true;
	perm(cur + 1, N);
	boolean[cur] = false;
	perm(cur + 1, N);

}

void postOrderEval(treePointer node) {
	if (node) {
		postOrderEval(node->leftChild);
		postOrderEval(node->rightChild);
		switch (node->data) {
		case '~': node->value = !node->rightChild->value; break;
		case '&': node->value = node->rightChild->value && node->leftChild->value; break;
		case '|': node->value = node->rightChild->value || node->leftChild->value; break;
		default: node->value = boolean[node->data - 'a'];
		}
	}
}

treePointer createNode(char data) {
	treePointer newNode = (treePointer)malloc(sizeof(*newNode));
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

treePointer createBinTree(void)
{
	treePointer pNode;

	precedence token;
	char symbol;
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
		{
			pNode = createNode(symbol);
			push(pNode);
		}
		else {
			pNode = createNode(symbol);
			pNode->rightChild = pop();
			if (pNode->data != '~')
				pNode->leftChild = pop();

			push(pNode);
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

precedence getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '&': return land;
	case '|': return lor;
	case '~': return lnot;
	case '\0': return eos;
	default: return operand;
	}
}

treePointer pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

treePointer stackEmpty()
{
	treePointer item;
	item = NULL;
	return item;
}

void push(treePointer item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	fprintf(stderr, "stack is full, cannot add item\n");
	exit(EXIT_FAILURE);
}
