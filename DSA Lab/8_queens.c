#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
} POSITION;

int getsize();
void fillBoard(STACK *stack, int boardSize);
void printBoard(STACK *stack, int boardSize);
bool guarded(int board[][9], int row, int col, int boardSize);

int main(void)
{
    int boardSize;
    STACK *stack;
    boardSize = getsize();
    stack = createStack();
    fillBoard(stack, boardSize);
    printBoard(stack, boardSize);
    destroyStack(stack);
    printf("\nWe hope you enjoyed Eight Queens.\n");
    return 0;
}

int getsize()
{
    int boardSize;
    printf("Welcome to Eight Queens. You may select\n"
           "a board size from 4 x 4 to 8 x 8. I will\n"
           "then position a queen in each row of the\n"
           "board so no queen may capture another\n"
           "queen. Note: There are no solutions for \n"
           "boards less than 4 x 4.\n");
    printf("\nPlease enter the board size: ");
    scanf("%d", &boardSize);
    while (boardSize < 4 || boardSize > 8)
    {
        printf("Board size must be greater than 3 \n"
               "and less than 9. You entered %d.\n"
               "Please re-enter. Thank you.\a\a\n\n"
               "Your board size: ",
               boardSize);
        scanf("%d", &boardSize);
    }
    return boardSize;
}

void fillBoard(STACK *stack, int boardSize)
{
    int row;
    int col;
    int board[9][9] = {0};
    POSITION *pPos;
    row = 1;
    col = 0;
    while (row <= boardSize)
    {
        while (col <= boardSize && row <= boardSize)
        {
            col++;
            if (!guarded(board, row, col, boardSize))
            {
                board[row][col] = 1;
                pPos = (POSITION *)malloc(sizeof(POSITION));
                pPos->row = row;
                pPos->col = col;
                pushStack(stack, pPos);
                row++;
                col = 0;
            }
            while (col >= boardSize)
            {
                pPos = popStack(stack);
                row = pPos->row;
                col = pPos->col;
                board[row][col] = 0;
                free(pPos);
            }
        }
    }
    return;
}

bool guarded(int board[][9], int chkRow, int chkCol, int boardSize)
{
    int row;
    int col;
    col = chkCol;
    for (row = 1; row <= chkRow; row++)
        if (board[row][col] == 1)
            return true;
    for (row = chkRow - 1, col = chkCol + 1;
         row > 0 && col <= boardSize;
         row--, col++)
        if (board[row][col] == 1)
            return true;
    for (row = chkRow - 1, col = chkCol - 1;
         row > 0 && col > 0;
         row--, col--)
        if (board[row][col] == 1)
            return true;

    return false;
}
void printBoard(STACK *stack, int boardSize)
{
    int col;
    POSITION *pPos;
    STACK *pOutStack;
    if (emptyStack(stack))
    {
        printf("There are no positions on this board\n");
        return;
    }
    printf("\nPlace queens in following positions:\n");
    pOutStack = createStack();
    while (!emptyStack(stack))
    {
        pPos = popStack(stack);
        pushStack(pOutStack, pPos);
    }
    while (!emptyStack(pOutStack))
    {
        pPos = popStack(pOutStack);
        printf("Row:%d-Col %d: \t|",
               pPos->row, pPos->col);
        for (col = 1; col <= boardSize; col++)
        {
            if (pPos->col == col)
                printf(" Q |");
            else
                printf(" |");
        }
        printf("\n");
    }
    destroyStack(pOutStack);
    return;
}