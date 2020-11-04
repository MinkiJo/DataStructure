#include<stdio.h>
#include<stdlib.h>

typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;

}tNode;
treePointer root;


void createBinTree(char data)
{
	root = (treePointer)malloc(sizeof(tNode));
	root->data = data;
	root->leftChild = NULL;
	root->rightChild = NULL;
}
treePointer createNode(char data)
{
	treePointer temp = (treePointer)malloc(sizeof(tNode));
	temp->data = data;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
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
	if(ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);		
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{
	if (ptr)
	{	postorder(ptr->leftChild);	
		postorder(ptr->rightChild);
		printf("%c", ptr->data);			
	}
}

int main()
{
	printf("creating a binary tree\n");
	createBinTree('A');
	treePointer B = createNode('B');
	treePointer C = createNode('C');
	treePointer D = createNode('D');
	treePointer E = createNode('E');
	root->rightChild = C;
	root->leftChild = B;
	B->leftChild = D;
	B->rightChild = E;

	printf("three binary tree traversals\n");
	printf("inorder traversal      : "); inorder(root); printf("\n");
	printf("preder traversal       : "); preorder(root); printf("\n");
	printf("postorder traversal    : "); postorder(root); printf("\n");

	
}