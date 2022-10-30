#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int rows = 9, cols = 9;

int offset(int i, int j){
    return i*cols +j;
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

void aplicar_movimiento(int* mat, int i, int j, char mov){
    
}

int main(){
    //alojamos la matriz en el sistema
    int *mat = (int*)malloc(rows*cols*sizeof(int));
    printf("Matriz alojada en el sistema\n");
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
    printf("Matriz rellenada\n");
    print_matrix(mat);

    //liberamos la matriz de la memoria 
    free(mat);
    printf("Fin\n");
    return 0;
}
