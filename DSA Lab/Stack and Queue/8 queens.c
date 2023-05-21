#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "STACK.h"

void solve_column(int);
bool valid_place(int, int);
int display_board();
void solve();

int queens=8;
int chess_board[20][20];

int main()
{
    solve();

    return 0;
}

void solve()
{

    solve_column(0);
}

void solve_column(int column)
{

    if(column == queens)
    {

        display_board();
        return;
    }

    for(int i=0; i<queens; i++)
    {
        if(valid_place(i,column))
        {
            chess_board[i][column] = 1;
            solve_column(column+1);
            chess_board[i][column] = 0;
        }
    }
}

bool valid_place(int row, int column)
{
    for(int i=column; i>=0; i--)
    {
        if(chess_board[row][i] == 1)
            return false;
    }

    for(int i=row, j=column; i>=0 && j>=0; i--,j--)
    {
        if(chess_board[i][j] == 1)
            return false;
    }

    for(int i=row, j=column; i<queens && j>=0; i++,j--)
    {
        if(chess_board[i][j] == 1)
            return false;
    }

    return true;
}

int display_board()
{
    STACK* s;
    s = createStack( );
    for(int i=0; i<queens; i++)
    {
        for(int j=0; j<queens; j++)
        {
            if(chess_board[i][j] == 1)
                pushStack(s,j+1);
        }
    }
    printf("printing the column numbers where the queens are placed in each of the rows serially = \n");
    display(s);
}
