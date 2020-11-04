//2016115921
//본인은 이 소스파일을 복사없이 직접작성하였습니다.
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 10
typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
}element;

element queue[MAX_QUEUE_SIZE];
int rear = -1, front = -1;

element queueEmpty() {
    element Empty;
    Empty.id = -9999;
    fprintf(stderr, "queue is empty, cannot delete element.\n");
    return Empty;
}
void queueFull(element item) {
    if (front == -1 && rear == MAX_QUEUE_SIZE - 1)
    {
        fprintf(stderr, "Queue is full, cannot add element");
        fprintf(stderr, "current queue elements\n");
        for (int i = MAX_QUEUE_SIZE - 1;i > front;i--)
        {
            printf("%d %s\n", queue[i].id, queue[i].name);
        }
        exit(EXIT_FAILURE);
    }

    else {
        printf("array shifting\n"); //한칸씩만 앞으로 당겨줌
        for (int i = 0;i <= MAX_QUEUE_SIZE - 1;i++)
        {
            queue[i] = queue[i + 1];
        }
        front--;
        queue[rear] = item;
    }


}
void addq(element item)
{
    if (rear == MAX_QUEUE_SIZE - 1)
        queueFull(item);
    else {
        queue[++rear] = item;
    }
}

element deleteq()
{
    if (front == rear)
    {
        return queueEmpty();
    }
    return queue[++front];
}





int main(void)
{
    char input[80];
    char* delimiter = " \n";
    char* op = NULL;
    element student;
    printf("<<linear queue operations where MAX_QUEUE_SIZE is 5>>\n");
    while (1)
    {
        //for (int i = rear;i > front;i--)   printf("%d %s\n", queue[i].id, queue[i].name);

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