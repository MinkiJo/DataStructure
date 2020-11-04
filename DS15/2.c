//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MALLOC(p,s)if (!((p) = malloc(s))) {fprintf(stderr, "Insufficient memory");exit(EXIT_FAILURE);}


typedef int iType;
typedef struct {
	int key;
	iType item;
}element;

typedef struct node* treePointer;
typedef struct node {
	element data;
	treePointer leftChild, rightChild;
}node;

element* search(treePointer root, int k)
{
	if (!root) return NULL;
	if (k == root->data.key) return &(root->data);
	if (k < root->data.key)
		return search(root->leftChild, k);
	return search(root->rightChild, k);
}

element* iterSearch(treePointer tree, int k)
{
	while (tree) {
		if (k == tree->data.key) return &(tree->data);
		if (k < tree->data.key)
			tree = tree->leftChild;
		else
			tree = tree->rightChild;
	}
	return NULL;
}

treePointer modifiedSearch(treePointer tree, int k)
{
	while (tree) {
		if (k == tree->data.key) return NULL;
		if (k < tree->data.key)
			if (tree->leftChild == NULL) return tree;
			else tree = tree->leftChild;
		else
			if (tree->rightChild == NULL) return tree;
			else tree = tree->rightChild;
	}
	return NULL;
}
void insert(treePointer* node, int k, iType theItem)
{
	treePointer ptr, temp = modifiedSearch(*node, k);
	if (temp || !(*node))
	{
		MALLOC(ptr, sizeof(*ptr));
		ptr->data.key = k;
		ptr->data.item = theItem;
		ptr->leftChild = ptr->rightChild = NULL;
		if (*node)
			if (k < temp->data.key) temp->leftChild = ptr;
			else temp->rightChild = ptr;
		else *node = ptr;
	}
}
void inorder(treePointer node)
	{
	if (node)
	{
		
		inorder(node->leftChild);
		printf("%d  ", node->data.key);
		inorder(node->rightChild);
	}
	}


int main()
{
	treePointer node = NULL;
	
	printf("random number generation(1~500)\n");
	int ran[500] = { 0, };
	int n, seed, target;
	
	printf("the number of nodes in BST(less than and equal to 50):   "); scanf("%d", &n);
	
	printf("seed  :  "); scanf("%d", &seed);
	srand(seed);
	
	printf("creating a BST from random numbers\n\n\n");
	for(int i = 0;i < n;i++) 
	{
		ran[i] = (rand() % 500) + 1;
		for (int j = 0;j < i;j++)
		{
			if (ran[j] == ((rand() % 500) + 1)) //중복체크
				i--;
			break;
		}		
	}
	
	for (int i = 0;i < n;i++) //랜덤수 확인
	{
		printf("%d   ", ran[i]);
	}printf("\n");

	for (int i = 0;i < n;i++)
	{
		insert(&node,ran[i],ran[i]);
	}
	printf("The key to search :  ");  scanf("%d", &target);
	printf("the element's item : ");

	element *find = iterSearch(node, target);
	if (find == NULL)
		printf("there is no such an element\n");
	else
		printf("%d\n", (*find).item);

	printf("\n\n\n");

	printf("inorder traversal of the BST shows the sorted sequence\n ");
	inorder(node);


	
}