
#include <stdio.h>
#include <math.h>
int main(void)//the program starts from here
{
    int matrix[20][20],copy[20][20],size,gen,i,j,numberGen;
    printf("**************************WELCOME TO 'The Game of Life'**************************\n");
    printf("ENTER THE SIZE : ");
    scanf("%d",&size);//inputs the size of the 2D matrix
    printf("ENTER THE NUMBER OF GENERATIONS : ");
    scanf("%d",&numberGen);//inputs the number of generations
    assign(matrix,size);//fills up the matrix with random living cells and dead cells
    for(gen=1;gen<=numberGen;gen++)//generation loop
    {
        printf("\nGENERATION NUMBER [%d] :\n  ",gen);
        for(j=0;j<size;j++)//loop for designing
        {
        printf("----");
        }
        printf("\n");//newline feed
        display(matrix,size);//displays the current generation matrix
        copyMatrix(matrix,copy,size);//copy of the current generation matrix
        /**
         * Loop for the calculation of next generation
         * Updates the copy of the current generation matrix
         **/
        for(i=0;i<size;i++)
        {
        for(j=0;j<size;j++)
        {
           updateGen(matrix,copy,size,i,j);
        }
        }
        copyMatrix(copy,matrix,size);//copies the changes in the original generation matrix
    }
    return 0;//program terminates successfully
}
void display(int matrix[][20],int size)//displays the generation matrix
{
    int i,j,x;char c=' ';
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
        x=matrix[i][j];//takes the value of the current cell that is one for alive and zero for dead
        c=x==1?'0':' ';//if one then changes with 0 symbol and dead then changes with blank
        printf(" | %c",c);//prints the character 0 or blank
        }
        printf(" | \n");
        printf("  ");
        for(j=0;j<size;j++)
        {
        printf("----");
        }
        printf("\n");
    }
}
void updateGen(int org[][20],int copy[][20],int size,int r,int c)//make changes in the generation matrix
{
    int value,livingCells;
    value=org[r][c];//takes the value of current cell dead or alive
    livingCells=countLiving(org,size,r,c);//counts the number of living cells adjacent to the current cell
    if(value==1)//if living cell
    {
        if(livingCells<2||livingCells>3)
        {
            value=0;
            copy[r][c]=value;//updates the cell with dead cell
        }
        if(livingCells==2||livingCells==3)
        {
            value=1;
            copy[r][c]=value;//cell remains the same
        }
    }
    else//if dead cell
    {
        if(livingCells==3)
        {
            value=1;
            copy[r][c]=value;//updates the cell with living cell
        }
    }
}
void assign(int matrix[][20],int size)//fills the generation matrix with random living or dead cells
{
    int i,j,r;
    srand(time(NULL));//sets the seed of the random number generator algorithm with different sequence.
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            r=rand()%2;//creates 0s and 1s randomly
            matrix[i][j]=r;//fills the current matrix cell with the random 0 or 1
        }
    }
}
void copyMatrix(int org[][20],int copy[][20],int size)//makes a duplicate of the generation matrix
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            copy[i][j]=org[i][j];//copies the elements of one matrix to another
        }
    }
}
int countLiving(int matrix[][20],int size,int curRow,int curCol)//counts the number of adjacent living cells
{
    int i,j,c=0;
    for(i=curRow-1;i<=curRow+1;i++)
    {
        if(i<0||i==size)//skips the imaginary adjacent cells
        {
            continue;
        }
    for(j=curCol-1;j<=curCol+1;j++)
    {
        if(j<0||j==size)//skips the imaginary adjacent cells
        {
            continue;
        }
        if(i==curRow&&j==curCol)//skips the current cell
        {
            continue;
        }
        if(matrix[i][j]==1)//if adjacent cell is alive counts the cell as living cell
        {
            c++;//counts the adjacent living cells
        }
    }
    }
    return c;//returns the number of adjacent living cells
}
