//This code is under GPLv3 License
//The purpose of this code is to simulate the Wood Solitaire game


#include "modelo.h"
#include "vista.h"
#include <unistd.h>

void help_text();
int game();             //return 1 if victory
int genetic_game();     //return 1 if victory



int main(int argc, char** argv){

    char opt = getopt(argc,argv,"gGh");

    if(opt == 'h'){
        help_text();
    }else if(opt == 'g'){
        //TODO game

    }else if(opt == 'G'){
        //TODO Genetic algorithm


    }else{
        //TODO error message
    }

    return 0;

}


void help_text(){
    vista_help_text();
}
