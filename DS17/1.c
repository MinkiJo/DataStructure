//2016115921
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
}node;

void add(nodePointer root, int index)
{
	node* temp = (nodePointer)malloc(sizeof(node));
	temp->data = index;
	temp->link = root->link;
	root->link = temp;
}

void showGraph(nodePointer root)
{
	nodePointer cur = root->link;
	while (cur != NULL)
	{
		printf("%d   ", cur->data);
		cur = cur->link;
	}
	printf("\n");
}
int main() {
	FILE* fp = fopen("input3.txt", "r");
	char direct;
	int v,e;
	fscanf(fp, "%c", &direct);
	fscanf(fp, "%d", &v);
	fscanf(fp, "%d", &e);
	nodePointer* graph = (nodePointer)malloc(sizeof(node)*v);
	for (int i = 0;i < v;i++)
	{
		graph[i] = (nodePointer)malloc(sizeof(node));
		graph[i]->link = NULL;
	}
	if (direct == 'd')
	{
		for (int i = 0;i < e;i++)
		{
			int a, b;
			fscanf(fp, "%d", &a);
			fscanf(fp, "%d",&b);
			add(graph[a],b);
		}
	}
	else if (direct == 'u')
	{
		{
			for(int i=0;i<e;i++)
			{
				int a, b;
				fscanf(fp, "%d", &a);
				fscanf(fp, "%d", &b);
				add(graph[a], b);
				add(graph[b], a);
			}
		}
	}


	printf("<<<<<Adjacency List>>>>>>\n");
	for (int i = 0;i < v;i++)
	{
		printf("adjList[%d] :   ",i);
		showGraph(graph[i]);
	}







}