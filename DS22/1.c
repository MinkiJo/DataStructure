//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다  
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 11
typedef struct {
	char item[10];
	int key;
}element;

element** ht;
int b = 11;
int s = 1;
element* search(int k);
unsigned int stringToInt(char* key);
element* search(int k);
void insert(int k, element* input);

char target[MAX];
int count;
int h(int k) //hash function
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
	int homeBucket, currentBucket;
	homeBucket = h(k);
	count = 1; //비교횟수
	for(currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;)
	{
		currentBucket = (currentBucket + 1) % b; count++;
		if (currentBucket == homeBucket)
			return NULL;
	}
	if (ht[currentBucket] && ht[currentBucket]->key == k)
		return ht[currentBucket];
	return NULL;
	
}

void insert(int k, element* input)
{
	int homeBucket, currentBucket;
	homeBucket = h(k);
	currentBucket = homeBucket;
	for(currentBucket = homeBucket; ht[currentBucket];)
	{
		if (input->key == ht[currentBucket]->key) {
			printf("key is alreay exist!");
			exit(1);
		}
			
		currentBucket = (currentBucket + 1) % b;
		if (currentBucket == homeBucket) {
			printf("hash table is full!\n");
			exit(1);
		}
		

	}
	ht[currentBucket] = input;	
}




int main()
{
	FILE* fp = fopen("input.txt", "r");
	element* word = (element*)malloc(sizeof(element)*b);
	ht = (element**)malloc(sizeof(element)*11);
	for (int i = 0;i < 11;i++)
		ht[i] = NULL;


	
	int i = 0;
	while (!feof(fp)){
		fscanf(fp,"%s",&word[i].item);
		i++;
	}
	
	for (int j = 0;j<i;j++) {
		word[j].key = stringToInt(word[j].item); //key 변환해서 insert
		insert(word[j].key, &word[j]);
	}
	printf("Input strings:   ");
	for (int j = 0;j < i;j++)
	{
		printf("%s  ", word[j].item);
	}printf("\n\n");

	printf("              item         key\n");

	for (int i = 0;i < 11;i++)
	{
		if (ht[i] != NULL)
			printf("ht[ %-2d]  :    %-10s   %3d\n", i, ht[i]->item, ht[i]->key);
		else printf("ht[ %-2d]  :     \n",i);
	}

	printf("\nstring to search >> ");

	scanf("%s", target);
	int target_key = stringToInt(target); //key 변환해서 search
	element* ans = search(target_key);
	if (ans != NULL)
		printf("item: %s, key: %d, the number of comparisions: %d", ans->item, ans->key, count);
	else printf("It doesn't exist!\n");

	return 0;
}