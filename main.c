#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

const int rows = 9, cols = 9;

int offset(int i, int j){
    return i*cols +j;
}

bool check_live(int* mat);

char get_char(){
    char mov;
    scanf(" %c", &mov);
    return mov;
}

char get_int(){
    int n;
    scanf("%d", &n);
    return n;
}


void print_matrix(int* mat){


    for(int i=0;i < rows;i++){
        for(int j =0;j < cols;j++){
            int value = mat[offset(i,j)];
            if (value == -1) printf(" ");
            else if (value == 0) printf("_");
            else printf("x");
            
            printf(" ");
        }
        printf("\n");
    }
}

void fill_matrix_init(int *mat){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //Llenamos los cuadrados que no existen
            mat[offset(i,j)] = -1;
            mat[offset(i+6,j)] = -1;
            mat[offset(i,j+6)] = -1;
            mat[offset(i+6,j+6)] = -1;
            //Llenamos los cuadrados que si existen
            mat[offset(i+3,j)] = 1;
            mat[offset(i,j+3)] = 1;
            mat[offset(i+3,j+3)] = 1;
            mat[offset(i+6,j+3)] = 1;
            mat[offset(i+3,j+6)] =  1;
        }
    }
    //Vaciamos el centro
    mat[offset(4,4)] = 0;
}

/*
 * Los movimientos se representan de la siguiente manera
 * movimiento para arriba = w
 * movimiento para abajo =  s
 * movimiento para la izquierda = i
 * movimiento para la derecha = d
 */

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


void make_move(int* mat, int i, int j, char mov){
   if(mov == 'w'){
       mat[offset(i,j)] = 0;
       mat[offset(i,j-1)] = 0;
       mat[offset(i,j-2)] = 1;
   }else if(mov == 's'){
       mat[offset(i,j)] = 0;
       mat[offset(i,j+1)] = 0;
       mat[offset(i,j+2)] = 1;
   }
    else if(mov == 'a'){
       mat[offset(i,j)] = 0;
       mat[offset(i-1,j)] = 0;
       mat[offset(i-2,j)] = 1;
   }else if(mov == 'd'){
       mat[offset(i,j)] = 0;
       mat[offset(i+1,j)] = 0;
       mat[offset(i+2,j)] = 1;
   }
}

int menu(){
    int choice;
    printf("Select mode to run the program\n");
    printf("1- Play game\n");
    printf("2- Genetic Algorithm best Sol\n");
    printf("3- Breadth first searh\n");
    printf("4- Depth first search\n");
    printf("\nOption: ");
    choice = scanf("%d",&choice);

    return choice;
}

void game(){
    //alojamos la matriz en el sistema
    int *mat = (int*)malloc(rows*cols*sizeof(int));
    /* Hay que rellenar la matriz de la siguiente manera:
     * -1 significa que no se puede poner una ficha en esa posicion, 
     * +1 significa que hay una ficha en esa posicion
     *  0 significa que no hay una ficha en esa posicion
     *
     *            1  1  1         
     *            1  1  1         
     *            1  1  1         
     *   1  1  1  1  1  1  1  1  1
     *   1  1  1  1  0  1  1  1  1
     *   1  1  1  1  1  1  1  1  1
     *            1  1  1         
     *            1  1  1         
     *            1  1  1         
     *
     *
     * No he pintado las casillas correspondientes a los -1
     */
    
    //Se rellena la matriz
    fill_matrix_init(mat);
    print_matrix(mat);
    
    //Bucle principal de juego
    char mov;
    int x, y;
    bool live = true; 
    printf("Choose the coordinates x y: ");
    x = get_int();
    y = get_int();
    printf("Choose the move: ");
    mov = get_char();
    while(live){
        if(check_move(mat,x,y,mov)){
            make_move(mat,x,y,mov);
            print_matrix(mat);
        }else
            printf("You cannot make that move\n");
        printf("Choose the coordinates x y: ");
        x = get_int();
        y = get_int();
        printf("Choose the move: ");
        mov = get_char();
    }

    //liberamos la matriz de la memoria 
    free(mat);
    printf("Fin\n");
}

int main(){
    int choice = menu();
    if(choice == 1)
        game();
    else
        printf("Not implemented yet!\n");
    return 0;
}

