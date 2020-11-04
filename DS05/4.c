//2016115921 조민기
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FALSE 0
#define  TRUE 1

typedef struct person {
	char name[10];
	int age;
	int salary;
}humanBeing;

int humansEqual(humanBeing *person1, humanBeing* person2)
{
	if (strcmp(person1->name, person2->name)) return FALSE;
	if (person1->age != person2->age) return FALSE;
	if (person1->salary != person2->salary) return FALSE;
	return TRUE;
}

int main()
{	
	humanBeing* person1 = (humanBeing*)malloc(sizeof(humanBeing));
	humanBeing *person2 = (humanBeing*)malloc(sizeof(humanBeing));

	printf("Input person1's name, age, salary:\n");
	scanf("%s %d %d", person1->name, &person1->age, &person1->salary);
	printf("Input person2's name, age, salary:\n");
	scanf("%s %d %d", &person2->name, &person2->age, &person2->salary);
	if (humansEqual(person1, person2) == 1) printf("The two human beings are the same");
	else printf("The two human beings are not the same");

	free(person1);
	free(person2);
}

