//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 10
short int visited[MAX_VERTICES];

typedef struct node* nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
}node;
nodePointer* graph;


typedef struct node* queuePointer;
typedef struct qnode {
	int vertex;
	queuePointer link;
}qnode;

queuePointer front, rear;


void addq(int vertex)
{
	queuePointer temp = (queuePointer)malloc(sizeof(qnode));
	temp->vertex = vertex;
	temp->link = NULL;
	if (front)
		rear->link = temp;
	else front = temp;
	rear = temp;
}

int deleteq()
{
	queuePointer temp = front;
	if (!temp)
		return;
	int vertex = temp->vertex;
	front = temp->link;
	free(temp);
	return vertex;

}

void add(nodePointer root, int vertex)
{
	nodePointer temp = (nodePointer)malloc(sizeof(node));
	temp->vertex = vertex;

	temp->link = root->link;
	root->link = temp;
}
void bfs(int v)
{
	nodePointer w;
	front = rear = NULL;
	printf("%5d", v);
	visited[v] = TRUE;
	addq(v);
	while (front)
	{
		v = deleteq();
		for (w = graph[v]->link;w;w = w->link)
			if (!visited[w->vertex]) {
				printf("%5d", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
	}
}

int main()
{
	int v, e;
	FILE* fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &v);
	fscanf(fp, "%d", &e);


	graph = (nodePointer)malloc(sizeof(node) * v);
	for (int i = 0;i < v;i++)
	{
		graph[i] = (nodePointer)malloc(sizeof(node));
		graph[i]->link = NULL;
	}

	for (int i = 0;i < e;i++) {
		int v1, v2;
		fscanf(fp, "%d %d", &v1, &v2);

		add(graph[v1], v2);
		add(graph[v2], v1);
	}


	printf("<<<<<<<<<<Adjacency List>>>>>>>>>>\n");
	for (int i = 0;i < v;i++) {
		nodePointer cur = graph[i]->link;
		printf("graph[%d] : ", i);
		while (cur != NULL)
		{
			printf("%d   ", cur->vertex);
			cur = cur->link;
		}
		printf("\n");
	}


	printf("<<<<<<<<<Breath First Search>>>>>>>>>>\n");
	for (int i = 0;i < v;i++)
	{
		printf("bfs[%d] : ", i);
		bfs(i);
		for (int j = 0;j < MAX_VERTICES;j++)
			visited[j] = 0;
		printf("\n");
	}
}