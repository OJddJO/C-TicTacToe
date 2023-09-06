#include <stdio.h>
#include <stdlib.h>

int checkWin();
void printBoard();

int main(void)
{
    int playerTurn = 0;
    int gameOver = 0;
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char playerSymbols[2] = {'X', 'O'};
    while (1) {
        start: system("cls");
        printBoard(board);
        int output;
        printf("\nPlayer %d, please choose a square:\n", playerTurn);
        scanf("%d", &output);
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] - '0' == output)
                {
                    goto play;
                }
            }
        }
        goto start;
        play: board[i][j] = playerSymbols[playerTurn];
        int state = checkWin(board, playerTurn);
        if (state == 1)
        {
            system("cls");
            printBoard(board);
            printf("\nPlayer %d win !", playerTurn);
            break;
        }
        else if (state == 2)
        {
            system("cls");
            printBoard(board);
            printf("\nTie !");
            break;
        }
        playerTurn = abs(playerTurn - 1);
    }
    return 0;
}

void printBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("|%c|", board[i][j]);
        }
        if (i == 2)
        {
            continue;
        }
        printf("\n---------\n");
    }
}

int checkWin(char board[3][3], int player)
{
    char playerSymbols[2] = {'X', 'O'};
    char symbol = playerSymbols[player];
    int win;
    //check rows
    for (int r = 0; r < 3; r++)
    {
        win = 1;
        for (int c = 0; c < 3; c++)
        {
            if (board[r][c] != symbol)
            {
                win = 0;
                break;
            }
        }
        if (win == 1)
        {
            return win;
        }
    }
    //check columns
    for (int c = 0; c < 3; c++)
    {
        win = 1;
        for (int r = 0; r < 3; r++)
        {
            if (board[r][c] != symbol)
            {
                win = 0;
                break;
            }
        }
        if (win == 1)
        {
            return win;
        }
    }
    //check diagonals
    win = 1;
    for (int i = 0;  i < 3; i++)
    {
        if (board[i][i] != symbol)
        {
            win = 0;
            break;
        }
    }
    if (win == 1)
    {
        return win;
    }
    win = 1;
    for (int i = 0;  i < 3; i++)
    {
        if (board[i][2-i] != symbol)
        {
            win = 0;
            break;
        }
    }
    if (win == 1)
    {
        return win;
    }
    //tie
    int tie = 2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                tie = 0;
            }
        }
    }
    if (tie != 0)
    {
        return tie;
    }
    return 0;
}