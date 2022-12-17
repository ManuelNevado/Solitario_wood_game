/*
 * the view of the will be impemented by console in this version
 */

#include <stdio.h>
#include "common_headers.h"

void vista_help_text(){

    printf("The format for executing this program is by selecting the mode, which are the following:\n");
    printf("\t-h\tto display this command\n");
    printf("\t-g\tto play the game as you would irl\n");
    printf("\t-G\tto use genetics algorithms to solve the game\n");

}

void show_board(int* board){
    //Self explanotory
    
    for(int i=0;i<ROW_LENGTH;i++){
        printf("%d\t",i);
        for(int j=0;j<COL_LENGTH;j++){
            char show;
            if(board[matriz(i,j)] == 0) show = '_';
            else if(board[matriz(i,j)] == 1) show = 'x';
            else show = ' ';
            printf(" %d ",show);
        }
        printf("\n");
    }
    printf(" ");
    for(int i=0;i<ROW_LENGTH;i++)
        printf(" %d ",i);
}
