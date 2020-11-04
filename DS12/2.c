#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef struct node* treePointer;
typedef struct node {
	char data; // char 문자출력을 위해 형으로 지정
	treePointer leftChild, rightChild;
}tNode;
treePointer root;
treePointer queue[MAX_QUEUE_SIZE];
int rear = -1, front = -1;

void addq(treePointer node);
treePointer getFront();
treePointer deleteq(void);
void createCompBinTree(FILE* fp);
treePointer createNode(char data);
int hasBothChild(treePointer pNode);
void insert(treePointer* qRoot, treePointer pNode);
treePointer deleteEmpty();
void queueFull();


void queueFull()
{
	printf("queue is FULL!\n");
	exit(1);
}
treePointer deleteEmpty()
{
	printf("queue is Empty!\n");
	return NULL;
}
void addq(treePointer node)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (front == rear)
		queueFull();
	queue[rear] = node;
} 
treePointer getFront()
{
	return queue[front+1];
}
treePointer deleteq(void)
{
	if(front ==rear)
		return deleteEmpty();
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}
void createCompBinTree(FILE* fp)
{
	char a;		
	while (1)
	{
		fscanf(fp, "%c", &a);
		if (feof(fp)) break;
		insert(&root, createNode(a));
	}	
}

treePointer createNode(char data)
{
	treePointer temp = (treePointer)malloc(sizeof(tNode));
	temp->data = data;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	return temp;
}

int hasBothChild(treePointer pNode)
{
	if (pNode->leftChild != NULL && pNode->rightChild != NULL)
		return 0;
	else return 1;
}

void insert(treePointer* qRoot, treePointer pNode)
{
	if ((*qRoot) == NULL){
		root = pNode;		
	}
	else {
		treePointer p = getFront();
		if (p->leftChild == NULL) {
			p->leftChild = pNode;			
		}
		else if (p->rightChild == NULL)
		{
			p->rightChild = pNode;			
		}
		else if (hasBothChild(p) == 0)
		{
			deleteq();			
			insert(&root, pNode);
		}		
	}
	addq(pNode);	
}
void inorder(treePointer ptr) {
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}

int main()
{
	FILE* fp = fopen("input.txt", "r");
	createCompBinTree(fp);
	printf("creating a complete binary tree\n");
	printf("three binary tree traversals\n");
	printf("inorder traversal      : "); inorder(root); printf("\n");
	printf("preder traversal       : "); preorder(root); printf("\n");
	printf("postorder traversal    : "); postorder(root); printf("\n");	
	
}