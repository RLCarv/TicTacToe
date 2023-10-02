#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

char board[3][3];
int opponent_choice = 0;
int available_moves = 9;
int replay = 1;

void choose_opponent();
void set_board();
void draw_board();
void check_moves();
void player_move();
void cpu_move();
int check_win();
void ask_replay();

void main()
{
    srand(time(0));
    while (replay != 2)
    {

        set_board(); // cleans the board

        do
        {
            system("cls");
            choose_opponent();
        } while ((opponent_choice != 1) && (opponent_choice != 2));

        if (opponent_choice == 1)
        { // against players
            while (check_win() != 1)
            {
                system("cls");
                draw_board();  // draws the board
                player_move(); // player move - depends on "available_moves" value
                check_moves(); // changes "available_moves" value
            }
        }
        else
        {
            while (check_win() != 1)
            {
                system("cls");
                draw_board(); // draws the board
                if (available_moves % 2 == 0)
                { // makes sure player always begins
                    cpu_move();
                    printf("\n\n    CPU is thinking");
                    Sleep(300);
                    printf(".");
                    Sleep(300);
                    printf(".");
                    Sleep(300);
                    printf(".\n");
                    Sleep(300);
                }
                else
                {
                    player_move(); // player moves
                }
                check_moves(); // changes "available_moves" value
            }
        }

        ask_replay(); // reset moves and opponent
    }
}

// clears the board
void set_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// draws the board
void draw_board()
{
    printf("\n-The Board-    -Reference-");
    printf("\n %c | %c | %c      1 | 2 | 3 ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---    ---|---|---");
    printf("\n %c | %c | %c      4 | 5 | 6 ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---    ---|---|---");
    printf("\n %c | %c | %c      7 | 8 | 9 ", board[2][0], board[2][1], board[2][2]);
}

// chooses 1 or 2 players
void choose_opponent()
{
    printf("\n      |------------|      ");
    printf("\n      |TIC TAC TOE!|      ");
    printf("\n      |------------|      ");
    printf("\n\n     Press (1) for 2P     ");
    printf("\n     Press (2) for CPU    ");
    printf("\n         ---> ");
    scanf("%d", &opponent_choice);
}

// checks and returns number of available moves
void check_moves()
{
    available_moves = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                available_moves--;
            }
        }
    }
}

// asks if wants to play again
void ask_replay()
{
    int local_replay = 1;
    printf("\n\n Press (1) to play again! ");
    printf("\n    Press (2) to quit!    ");
    printf("\n         ---> ");
    scanf("%d", &local_replay);
    if (local_replay == 2)
    {
        replay = 2;
    }
    else if (local_replay != 1)
    {
        ask_replay();
    }
    else
    {
        available_moves = 9; // reset moves
        opponent_choice = 0; // reset opponent
    }
}

// checks for win or draw
int check_win()
{
    int win = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') || (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ') || (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') || (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' '))
            {
                win = 1;
                system("cls");
                draw_board();
                if (available_moves % 2 == 0)
                {
                    printf("\n\n      |------------|      ");
                    printf("\n      | ~'X' wins! |      ");
                    printf("\n      |------------|      ");
                }
                else
                {
                    printf("\n\n      |------------|      ");
                    printf("\n      | ~'O' wins! |      ");
                    printf("\n      |------------|      ");
                }
                return 1;
            }
        }
    }

    if (available_moves == 0 && win == 0)
    { // when possible moves are over and no win, returns draw
        system("cls");
        draw_board();
        printf("\n\n      |------------|      ");
        printf("\n      |It's a draw!|      ");
        printf("\n      |------------|      ");
        return 1;
    }
    return 0;
}

// cpu move
// 100% random
void cpu_move()
{
    int x = 0;
    int y = 0;

    do
    {
        x = rand() % 3;
        y = rand() % 3;
    } while (board[x][y] != ' ');

    board[x][y] = 'O';
    available_moves--;
}

// input player moves
// there's probably a better way to do this using a for loop
void player_move()
{

    int move = 0;
    char player_name[] = {' '};

    if (available_moves % 2 == 0)
    { // defines which player it is
        player_name[0] = 'O';
    }
    else
    {
        player_name[0] = 'X';
    }

    printf("\n\n%c, choose next movement: ", player_name[0]);
    scanf("%d", &move); // asks for the movement from 1 to 9
    switch (move)       // will check if the move is available and break, if not, will call function again
    {
    case (1):
        if (board[0][0] == ' ')
        {
            board[0][0] = player_name[0];
            available_moves--;
        }
        break;
    case (2):
        if (board[0][1] == ' ')
        {
            board[0][1] = player_name[0];
            available_moves--;
            break;
        }
    case (3):
        if (board[0][2] == ' ')
        {
            board[0][2] = player_name[0];
            available_moves--;
        }
        break;
    case (4):
        if (board[1][0] == ' ')
        {
            board[1][0] = player_name[0];
            available_moves--;
        }
        break;
    case (5):
        if (board[1][1] == ' ')
        {
            board[1][1] = player_name[0];
            available_moves--;
        }
        break;
    case (6):
        if (board[1][2] == ' ')
        {
            board[1][2] = player_name[0];
            available_moves--;
        }
        break;
    case (7):
        if (board[2][0] == ' ')
        {
            board[2][0] = player_name[0];
            available_moves--;
        }
        break;
    case (8):
        if (board[2][1] == ' ')
        {
            board[2][1] = player_name[0];
            available_moves--;
        }
        break;
    case (9):
        if (board[2][2] == ' ')
        {
            board[2][2] = player_name[0];
            available_moves--;
        }
        break;
    default:
        player_move(); // call function again
    }
}