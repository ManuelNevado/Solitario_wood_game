#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Constantes
const int rows = 9, cols = 9;
const char moves[4] = {'w','a','s','d'};

//Estructuras de datos

struct lista_movibles{
        int* top;
        int* left;
        int* centre;
        int* right;
        int* down;
    };

    struct individuo{
        int* moves;
        int n;
    };


    struct lista_int{
        int* lista;
        int length;
    };

    struct list_bool{
        bool* lista;
        int length;
    };


    //Funciones de cabecera

    struct individuo individuo_init(){
        struct individuo in;
        in.moves = (int*) malloc(35*sizeof(int));
        in.n=0;
        return in;
    }

    int offset(int i, int j){
        return cols*i + j;
    }

    void individuo_free(struct individuo i){
        free(i.moves);
    }

    bool check_move(int* mat , int i, int j, char mov){
        if(mov == 'w' && j>1 && mat[offset(i,j-1)] == 1 && mat[offset(i,j-2)] == 0)
            return true;
        if(mov == 'a' && i>1 && mat[offset(i-1,j)] == 1 && mat[offset(i-2,j)] == 0)
            return true;
        if(mov == 's' && j<7 && mat[offset(i,j+1)] == 1 && mat[offset(i,j+2)] == 0)
            return true;
        if(mov == 'd' && i<7 && mat[offset(i+1,j)] == 1 && mat[offset(i+2,j)] == 0)
            return true;

        return false;
    }


    int* create_candidate_list(int* mat){
        
        int* lista = (int*)malloc(35*sizeof(int));

        for (int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                lista[offset(i,j)] = false;
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j =0;j<cols;j++){    
                for(int m = 0; m < 4; m++){
                    if(check_move(mat,i,j,moves[m])){
                        lista[offset(i,j)] = true;
                    }
                }
            }
        }

        return lista;
    }

    void print_matrix_candidate(int* mat){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[offset(i,j)]==1)
                    printf("x ");
                else
                    printf(". ");
            }
        printf("\n");
    }
}

bool recorre_L(int* mat, int i, int j){
    return false;
}

void locate_L(int* mat){
    int* x = (int*) malloc(35*sizeof(int));
    int* y = (int*) malloc(35*sizeof(int));
    for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if(mat[offset(i,j) == 1] && recorre_L(mat,i,j)){

            }
        }
    }
    free(x);
    free(y);
}
