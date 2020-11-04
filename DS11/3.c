//2016115921
//본인은 이 소스파일을 복사없이 직접 작성했습니다.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COMPARE(x,y)(((x) < (y))? -1: ((x) == (y))? 0 :1)
#define MALLOC(p,s) p = malloc(s)

typedef struct node*nodePointer;
typedef struct node {
	nodePointer llink;
	int data;
	nodePointer rlink;
}node;

nodePointer header = NULL;

void dinsert(nodePointer node, nodePointer newnode)
{
	newnode-> llink = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
	node->rlink = newnode;
}
void ddelete(nodePointer node, nodePointer deleted)
{
	if (node == deleted)
		printf("Deletion of header node not permitted.\n");
	else {
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
		free(deleted);
	}
}
void delete50(nodePointer node)
{
	nodePointer cur = node->llink;
	nodePointer del = cur;
	
	while (cur != header){		
		del = cur;
		if (cur->data <= 50) {
			cur = cur->llink; 
			ddelete(header, del);
		}
		else cur = cur->llink;
			
	}
}
void deleteAll(nodePointer node)
{
	nodePointer cur = node->llink;
	nodePointer del;

	while (cur != header) {
		del = cur;		
		cur = cur->llink;
		ddelete(header, del);
	}
}

nodePointer makenode(int data)
{
	nodePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;
	return temp;
}

void printList1(nodePointer node)
{
	int count = 1;
	nodePointer cur = node->llink;
	while (cur != header)
	{
		printf("%3d", cur->data);
		cur = cur->llink;
		if (count % 10 == 0)
			printf("\n");
		count++;
	}
	printf("\n");
}
void printList2(nodePointer node)
{
	int count = 1;
	nodePointer cur = node->rlink;
	while (cur!= header)
	{
		printf("%3d", cur->data);
		cur = cur->rlink;
		if (count % 10 == 0)
			printf("\n");
		count++;
	}
	printf("\n");
}


int main()
{
	MALLOC(header, sizeof(node));
	header->llink = header; header->rlink = header;
	FILE* fp = fopen("input.txt", "r");
	int data;
	

	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
		dinsert(header, makenode(data));
	}
	printf("forward\n"); //forward와 backward 출력
	printList1(header);
	printf("\n");
	printf("backward\n");
	printList2(header);
	printf("\n");
	
	
	delete50(header); //50이하의 데이터 삭제
	printf("After deleting numbers less than and equal to 50: \n");
	printf("forward\n");
	printList1(header);
	
	printf("\nbackward\n");
	printList2(header);

	printf("\nAfter deleting numbers less than and equal to 50: \n");	
	deleteAll(header); //모두 지우기
	printf("forward\n");
	printList1(header);

	printf("\nbackward\n");
	printList2(header);
	free(header);
	fclose(fp);
}