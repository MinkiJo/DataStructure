//2016115921
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다 .
#include <stdio.h>
#include <stdlib.h>


#define MAX_ROW 10
#define MAX_COL 10
#define MAX_STACK_SIZE 100 
#define TRUE 1               
#define FALSE 0              


typedef struct {                        
    short int row;
    short int col;
    short int dir;
}element;
element stack[MAX_STACK_SIZE];
int top = -1;

typedef struct {
    short int vert;
    short int horiz;
}offsets;

offsets move[8] = { {-1, 0}, {-1,1},{0,1},{1,1}, {1,0},{1,-1},{0,-1},{-1,-1} };



int EXIT_ROW, EXIT_COL;


int maze[MAX_ROW][MAX_COL];                
int mark[MAX_ROW][MAX_COL];               




int push(element item)
{
    if (top >= MAX_STACK_SIZE - 1) return;
    stack[++top] = item;

}


element pop()
{
    if (top == -1) return;
    return stack[top--];
}

void path()
{
  
    int i, row, col, next_row, next_col, dir, found = FALSE;
    
    element position;
    mark[1][1] = 1;
    top = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 1;

    while (top > -1 && !found) {
        position = pop();                      
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found) {                       
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
            if (next_row == EXIT_ROW && next_col == EXIT_COL)
                found = TRUE;
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                push( position);              
                row = next_row;
                col = next_col;
                dir = 0;
            }
            else ++dir;
        }
    }
    if (found) {                                                               
        printf("The path is : \n");
        printf("row col\n");
        for (i = 0; i <= top; i++)
            printf("%2d%5d\n", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    }
    else printf("The maze dose not have a path\n");
}



int main(void) {
    int i, j;

    
    FILE* fpin = fopen("input.txt", "r");
    fscanf(fpin, "%d%d", &EXIT_ROW, &EXIT_COL);

    for (int i = 0;i < 10;i++) 
    {
        for (int j = 0;j < 10;j++)
        {
            maze[i][j] = 1;
        }
    }

    for (int i = 1;i <= EXIT_ROW;i++)
    {
        for (int j = 1;j <= EXIT_COL;j++)
        {
            fscanf(fpin, "%d", &maze[i][j]);
        }
    }
    
    printf("MAZE\n");
    for (int i = 0;i <= EXIT_ROW + 1;i++)
    {
        for (int j = 0;j <= EXIT_COL + 1;j++)
        {
            printf("%3d", maze[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX_ROW; i++)
        for (j = 0; j <= MAX_COL; j++)
            mark[i][j] = 0;
   
    path();
   

    return 0;
}