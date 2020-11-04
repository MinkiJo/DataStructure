//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다  
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char item[10];
	int key;
}element;

typedef struct node* nodePointer;
typedef struct node{
	element data;
	nodePointer link;
}node;

nodePointer* ht;
int b = 11;
int com;


int h(int k)
{
	return k % b;
}
unsigned int stringToInt(char* key)
{
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}
element* search(int k)
{
	com = 0;
	nodePointer current;
	int homeBucket = h(k);
	for (current = ht[homeBucket]; current; current = current->link) {
		com++;
		if (current->data.key==k)
			return &current->data;
	}
	return NULL;
}
void insert(int k, element* input)
{
	nodePointer current;
	nodePointer temp = (nodePointer)malloc(sizeof(node));
	temp->data = (*input);
	temp->link = NULL;
	int homeBucket = h(k);
	if (ht[homeBucket] == NULL)
		ht[homeBucket] = temp;
	else {
		for (current = ht[homeBucket]; current->link; current = current->link);
		temp->link = current->link;
		current->link = temp;
	}
		
}
void printht()
{
	for (int i = 0;i < b;i++) {
		printf("ht[%d] : ", i);
		for (nodePointer cur = ht[i]; cur;cur = cur->link) {
			
				printf("(%s   %d)  ", cur->data.item, cur->data.key);
			
		}
		printf("\n");
	}
}
int main()
{
	element arr[100];

	ht = (nodePointer*)malloc(sizeof(node) * b); //hash table
	for (int i = 0;i < b;i++)
		ht[i] = NULL;

	int num = 0;
	FILE* fp = fopen("input.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s", &arr[num].item);
		num++;
	}
	printf("input strings: ");
	for (int i = 0;i < num;i++)
		printf("%s ", arr[i].item);
	printf("\n\n");

	for (int i = 0;i < num;i++)
		arr[i].key = stringToInt(arr[i].item); //문자를 키로변경

	for (int i = 0;i < num;i++)
		insert(arr[i].key, &arr[i]); 

	printht();

	char target[100];
	while (1)
	{
		printf("\ninput ^Z to quit\n");
		printf("string to search >>  ");
	
		if (gets(target) == NULL) //ctrl z 입력시 종료
				break;
		if (search(stringToInt(target)) != NULL) {
			printf("item : %s, key: %d, the number of comparisions : %d\n\n", search(stringToInt(target))->item, search(stringToInt(target))->key, com);
		}
		else printf("it doesn't exist!\n");
	}

	return 0;
}