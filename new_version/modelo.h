//Here is where the bricks of the program will be

#include <stdlib.h>
#include <string.h>
#include "common_headers.h"

int* create_board();            //create the board where the game would be played
int game();                     //Flow of the game

int* create_board(){
    /*
     *      _ _ _ 1 1 1 _ _ _
     *      _ _ _ 1 1 1 _ _ _
     *      _ _ _ 1 1 1 _ _ _
     *      1 1 1 1 1 1 1 1 1
     *      1 1 1 1 0 1 1 1 1
     *      1 1 1 1 1 1 1 1 1
     *      _ _ _ 1 1 1 _ _ _
     *      _ _ _ 1 1 1 _ _ _
     *      _ _ _ 1 1 1 _ _ _
     *
     */

    int* board = (int*) malloc(ROW_LENGTH*COL_LENGTH*sizeof(int));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //first row of 3x3 squares
            board[matriz(i,j)] = -1;
            board[matriz(i+3,j)] = 1;
            board[matriz(i+6,j)] = -1;
            //second row of 3x3
            board[matriz(i,j+3)] = 1;
            board[matriz(i+3,j+3)] = 1;
            board[matriz(i+6,j+3)] = 1;
            //third row of 3x3
            board[matriz(i,j+6)] = -1;
            board[matriz(i+3,j+6)] = 1;
            board[matriz(i+6,j+6)] = -1;
        }
    }
    
    //The center gets emptied
    board[matriz(4,4)] = 0;

    return board;
}

int game(){
    
    int victory = 0;

    int* board = create_board();
    
    //TODO Bucle principal

    free(board);

    return victory;
}
