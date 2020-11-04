//2016115921
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다 .
#include<stdio.h>
#include<stdlib.h>
#define MAX_NAME_SIZE 100

#define MALLOC(a,b) a = malloc(b)
typedef struct {
	int id; // unique id
	char name[MAX_NAME_SIZE]; //last name
} element;

element* queue;

int capacity = 2;
int rear = 0;
int front = 0;

element queueEmpty()
{
	element Empty;
	Empty.id = -9999;
	fprintf(stderr, "Queue is empty, cannot delete element.\n");
	
	return Empty;
	
}
void copy(element* newfront, element* newrear, element *newqueue) {

	for (int i = 0;i < capacity-1;i++)
	{		
		newqueue[i] = *(newfront + i);
	}
	printf("queue capacity is doubled,\n");
	printf("current queue capacity is %d\n", capacity*2);
		
	
}
void queueFull()
{
	int start;
	element* newQueue;
	MALLOC(newQueue, 2 * capacity * sizeof(*queue));

	start = (front + 1) % capacity;
	if (start < 2)
		copy(queue + start, queue + start + capacity - 1, newQueue);
	else {
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}
	front = 2 * capacity - 1;
	rear = capacity-1;
	capacity *= 2;
	free(queue);
	queue = newQueue;
}

element deleteq()
{
	
	if (front == rear)
	{
		return queueEmpty();
		
	}
	front = (front + 1) % capacity;	
	
	printf("deleted item:%d %s\n", queue[front].id, queue[front].name );
	
	return queue[front];
}

void addq(element item)
	{
		rear = (rear + 1) % capacity;
		if (front == rear) queueFull();			

		queue[rear] = item;
		
		
		/*printf("현재 큐상태\n");
		for (int i = (front + 1) % capacity;i <= rear; i++)
		{
			printf("%d %s\n", queue[i % capacity].id, queue[i % capacity].name);
		}*/
	}


int main(void)
{
	queue = (element*)malloc(sizeof(element)*capacity);

	char input[80];                // input a line of string
	char* delimiter = " \n";    // delimiter for tokenizing
	char* op = NULL;            // push or pop
	element student;
	while (1)
	{
		gets(input);
		op = strtok(input, delimiter);
		if (!strcmp(op, "add"))
		{
			sscanf(input + strlen(op) + 1, "%d %s", &student.id, student.name);
			addq(student);
		}
		else if (!strcmp(op, "delete"))
		{
			deleteq();
		}
		else if (!strcmp(op, "quit"))
			break;
		else
			printf("wrong command! try again!\n");
	}// while
	return 0;
}