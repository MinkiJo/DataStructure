//2016115921
//본인은 이 소스파일을 복사없이 직접작성하였습니다.
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 10
typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

void stackFull()
{

    fprintf(stderr, "Stack is full, cannot add element");
    fprintf(stderr, "current stack elements\n");
    for (int i = MAX_STACK_SIZE - 1;i > -1;i--)
    {
        printf("%d %s\n", stack[i].id, stack[i].name);
    }
    exit(EXIT_FAILURE);
}
element stackEmpty()
{
    element Empty;
    Empty.id = -9999;
    fprintf(stderr, "stack is empty, cannot delete element.\n");
    return Empty;
}

void push(element item)
{
    if (top >= MAX_STACK_SIZE - 1) stackFull();
    stack[++top] = item;


}

element pop()
{
    if (top == -1) return stackEmpty();
    return stack[top--];
}



int main(void)
{
    char input[80];                // input a line of string
    char* delimiter = " \n";    // delimiter for tokenizing
    char* op = NULL;            // push or pop
    element student;
    while (1)
    {
        gets(input);
        op = strtok(input, delimiter);
        if (!strcmp(op, "push"))
        {
            sscanf(input + strlen(op) + 1, "%d %s", &student.id, student.name);
            push(student);
        }
        else if (!strcmp(op, "pop"))
        {
            pop();
        }
        else if (!strcmp(op, "quit"))
            break;
        else
            printf("wrong command! try again!\n");
    }// while
    return 0;
}