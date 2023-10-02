/*
TO DO:
    Need to create statements to find winner
    Add a reset command
    Find a way to display in a window and clear terminal
    Maybe use buttons
    Maybe create simple AI (The player always go first)
    Post on git hub
    Profit?
*/
#include <stdio.h>


char board[3][3];
int opponent_choice = 0;
int available_moves = 9;

const char PLAYER_1 =  'X';
const char PLAYER_2 =  'O';
//const char SUPER_AI =  'O';

void choose_opponent();
void set_board();
void draw_board();
void check_moves();
void player_move();
void check_win();

void main(){
    
    while(!(opponent_choice == 1)){ // would use it to creat AI
        choose_opponent();
    }
    
    set_board(); //cleans the board
    
    while (available_moves != 0){
        draw_board(); //draws the board
        printf("%d", available_moves);
        player_move(); //player move - depends on "available_moves" value
        check_moves(); //changes "available_moves" value
        check_win(); //returns nothing, winner or draw - depends on "available_moves"
    }


}

//clears the board
void set_board(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

//draws the board
void draw_board(){
    printf("\n-The Board-    -Reference-");
    printf("\n %c | %c | %c      1 | 2 | 3 ", board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---    ---|---|---");
    printf("\n %c | %c | %c      4 | 5 | 6 ", board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---    ---|---|---");
    printf("\n %c | %c | %c      7 | 8 | 9 ", board[2][0],board[2][1],board[2][2]);
}

//chooses 1 or 2 players
void choose_opponent(){
    printf("\n-- TIC TAC TOE --");
    printf("\n\nPress (1) to play: ");
    scanf("%d",&opponent_choice);
}

//checks and returns number of available moves
void check_moves(){
    available_moves = 9;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j ++){
            if (board[i][j] != ' '){
                available_moves--;
            }
        }
    }
}

//checks for win or draw
void check_win(){
    int win = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j ++){
            if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
            || (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
            || (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
            || (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' ')){
                win = 1;
                draw_board();
                if (available_moves % 2 == 0) {
                    printf("\n\n'X' wins!");
                } else {
                    printf("\n\n'O' wins!");
                }                
                available_moves = 0;
                break;
            }
        }
    }

    if (available_moves == 0 && win == 0){  //when possible moves are over and no win, returns draw
        draw_board(); //shows final board
        printf("\n\nIt's a draw!");
    }
}


//input player moves
//there's probably a better way to do this using a for loop
void player_move(){
    int move = 0;

    printf("\n Choose next movement: ");
    scanf("%d", &move); //asks for the movement from 1 to 9

    switch (move) //will check if the move is available and break, if not, will call function again
    { 
    case(1) : if (board[0][0] == ' '){ 
        if (available_moves % 2 == 0) {
            board[0][0] = 'O';
        } else {
            board[0][0] = 'X';
        }
        break;
    }
    case(2) : if (board[0][1] == ' '){ 
        if (available_moves % 2 == 0) {
            board[0][1] = 'O';
        } else {
            board[0][1] = 'X';
        }
        break;
    }
    case(3) : if (board[0][2] == ' '){ 
        if (available_moves % 2 == 0) {
            board[0][2] = 'O';
        } else {
            board[0][2] = 'X';
        }
        break;
    }
    case(4) : if (board[1][0] == ' '){ 
        if (available_moves % 2 == 0) {
            board[1][0] = 'O';
        } else {
            board[1][0] = 'X';
        }
        break;
    }
    case(5) : if (board[1][1] == ' '){ 
        if (available_moves % 2 == 0) {
            board[1][1] = 'O';
        } else {
            board[1][1] = 'X';
        }
        break;
    }
    case(6) : if (board[1][2] == ' '){ 
        if (available_moves % 2 == 0) {
            board[1][2] = 'O';
        } else {
            board[1][2] = 'X';
        }
        break;
    }
    case(7) : if (board[2][0] == ' '){ 
        if (available_moves % 2 == 0) {
            board[2][0] = 'O';
        } else {
            board[2][0] = 'X';
        }
        break;
    }
    case(8) : if (board[2][1] == ' '){ 
        if (available_moves % 2 == 0) {
            board[2][1] = 'O';
        } else {
            board[2][1] = 'X';
        }
        break;
    }
    case(9) : if (board[2][2] == ' '){ 
        if (available_moves % 2 == 0) {
            board[2][2] = 'O';
        } else {
            board[2][2] = 'X';
        }
        break;
    }
    default:
        player_move(); //call function again
    }
}