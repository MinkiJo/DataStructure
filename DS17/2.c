//2016115921
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef enum { FALSE, TRUE } tBoolean;
typedef struct edge* tEdgePointer;
typedef struct edge {
	tBoolean marked;
	int vertex1;
	int vertex2;
	tEdgePointer link1;
	tEdgePointer link2;
}edge;
tEdgePointer* graph;
tEdgePointer createEdge(int ver1, int ver2) {
	tEdgePointer temp = (tEdgePointer)malloc(sizeof(edge));
	temp->vertex1 = ver1;
	temp->vertex2 = ver2;
	temp->link1 = NULL; temp->link2 = NULL;
	return temp;
}
void addEdge(tEdgePointer temp, int ver1, int ver2) {

	if (graph[ver1]->link1 == NULL && graph[ver1]->link2 == NULL) //ver1인덱스에 연결
		graph[ver1]->link1 = temp;

	else {
		tEdgePointer cur1 = graph[ver1]->link1;

		while (1)
		{
			if (cur1->vertex1 == ver1) {
				if (cur1->link1 == NULL)
				{
					cur1->link1 = temp;
					break;
				}
				else
					cur1 = cur1->link1;
			}
			else if (cur1->vertex2 == ver1)
				if (cur1->link2 == NULL)
				{
					cur1->link2 = temp;
					break;
				}
				else cur1 = cur1->link2;
		}

	}

	if (graph[ver2]->link1 == NULL && graph[ver2]->link2 == NULL) //ver2인덱스에 연결
		graph[ver2]->link1 = temp;
	else {
		tEdgePointer cur2 = graph[ver2]->link1;
		while (1)
		{
			if (cur2->vertex1 == ver2) {
				if (cur2->link1 == NULL)
				{
					cur2->link1 = temp;
					break;
				}
				else
					cur2 = cur2->link1;
			}
			else if (cur2->vertex2 == ver2)
				if (cur2->link2 == NULL)
				{
					cur2->link2 = temp;
					break;
				}
				else cur2 = cur2->link2;
		}

	}
}

void printMultilist(int numVertex, int choice) {

	if (choice == 0) //입력데이터 순서대로
	{
		for (int i = 0;i < numVertex;i++)
		{
			tEdgePointer cur = graph[i]->link1;
			printf("edges incident to vertex %d  : ", i);
			while (cur != NULL)
			{
				printf("(%d,%d)  ", cur->vertex1, cur->vertex2);
				if (cur->vertex1 == i)
					cur = cur->link1;
				else cur = cur->link2;
			}
			printf("\n");
		}
	}
	if (choice == 1) //헤더노드 정점먼저
	{
		for (int i = 0;i < numVertex;i++)
		{
			tEdgePointer cur = graph[i]->link1;
			printf("edges incident to vertex %d  : ", i);
			while (cur != NULL)
			{

				if (cur->vertex1 == i)
				{
					printf("(%d,%d)  ", cur->vertex1, cur->vertex2);
					cur = cur->link1;
				}
				else {
					printf("(%d,%d)  ", cur->vertex2, cur->vertex1);
					cur = cur->link2;
				}
			}
			printf("\n");
		}
	}
}
int main() {
	FILE* fp = fopen("input.txt", "r");

	int v, e;
	fscanf(fp, "%d", &v);
	fscanf(fp, "%d", &e);
	graph = (tEdgePointer)malloc(sizeof(edge) * v);
	for (int i = 0;i < v;i++)
	{
		graph[i] = (tEdgePointer)malloc(sizeof(edge));
		graph[i]->link1 = NULL;
		graph[i]->link2 = NULL;
	}

	for (int i = 0;i < e;i++)
	{
		int a, b;
		fscanf(fp, "%d %d", &a, &b);
		tEdgePointer temp = createEdge(a, b);
		addEdge(temp, a, b);

	}

	printf("간선의 정점 출력 순서 - 입력데이터 순서대로\n");
	printMultilist(v, 0);

	printf("\n간선의 정점 출력 순서 - 헤더노드 정점이 먼저\n");
	printMultilist(v, 1);

}