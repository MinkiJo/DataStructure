//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다  
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char item[10];
	int key;
}element;

element** ht;
int b = 8;
int s = 1;
int ran[100];
int com;
int h(int k)
{
	return k % b;
}

void insert(int k, element* input)
{
	int homeBucket, currentBucket;
	homeBucket = h(k);
	currentBucket = homeBucket;
	int i = 0;
	while (ht[currentBucket])
		{
		
		if (input->key == ht[currentBucket]->key) {
			printf("key is alreay exist!");
			exit(1);
		}


		if (i == b - 1) { //i가 랜덤배열의 인텍스를 모두 탐색한다면 full 
			printf("hash table is full!\n");
			exit(1);

		}

		currentBucket = homeBucket;
		currentBucket = (currentBucket + ran[i++]) % b;
		
		}

	ht[currentBucket] = input;
}

element* search(int k)
{
	int homeBucket, currentBucket;
	homeBucket = h(k);
	currentBucket = homeBucket;
	int i = 1;
	com = 0;
	while (ht[currentBucket])
	{
		com++;
		if (ht[currentBucket]->key == k)
			return ht[currentBucket];
		
		if (i == b - 1) {
			return NULL;
		}
		
		else {
			currentBucket = homeBucket;
			currentBucket = (currentBucket + ran[i++]) % b;		
			
		}
		
	
	}
	return NULL;
}
int main()
{
	element arr[100];
	int seed;

	printf("seed: ");
	scanf("%d", &seed);
	srand(seed);
	
	ht = (element**)malloc(sizeof(element)*b); //hash table
	for (int i = 0;i < b;i++)
		ht[i] = NULL;
	int num = 0;
	for (int i = 1;i <= b-1;i++) {		
		ran[i] = (rand() % 7) + 1;

		for (int j = 1;j < i;j++)
		if (ran[j] == ran[i]) {
			i--;
			break;
		}

	}

	
	
	FILE* fp = fopen("input.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d", &arr[num].key);
		num++;
	}
	printf("key sqeuence from file: ");
	for (int i = 0;i < num;i++)
		printf("%d ", arr[i].key);
	printf("\n\n");

	for (int i = 1;i <=b-1;i++)
		printf("randNum[%d] : %d \n", i, ran[i]);
	printf("\n");

	for (int i = 0;i < num;i++)
		insert(arr[i].key, &arr[i]);

	for (int i = 0;i < b;i++)
	{
		if (ht[i] != NULL)
			printf("ht[ %-2d]  :     %3d\n", i,  ht[i]->key);
		else printf("ht[ %-2d]  :     \n", i);
	}printf("\n");


	int target;
	while (1)
	{
		
		printf("input 0 to quit\n");
		printf("key to search >> ");
		scanf("%d", &target);
		if (target == 0)
			return 0;

		if (search(target) != NULL)
			printf("key : %d, the number of comparisions : %d\n\n", search(target)->key, com);
		else printf("it doesn't exist!\n");

	}
}