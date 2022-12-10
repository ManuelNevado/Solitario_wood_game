//Here is where the bricks of the program will be

#include <stdlib.h>
#include <string.h>
#define ROW_LENGTH 9
#define COL_LENGTH 9

int offset(int i, int j);       //calculate the position in the single dimmension array
int* create_board();            //create the board where the game would be played
int game();                     //Flow of the game


int offset(int i, int j){
    return j*ROW_LENGTH+i;
}

int* create_board(){

    int* board = (int*) malloc(ROW_LENGTH*COL_LENGTH*sizeof(int));
    return board;
}

int game(){
    
    int victory = 0;

    int* board = create_board();
    
    //TODO Bucle principal

    free(board);

    return victory;
}
