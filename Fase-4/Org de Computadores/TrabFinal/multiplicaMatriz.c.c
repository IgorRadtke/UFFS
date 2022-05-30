#include <stdio.h>

#define DIM 12

void matrix_mult(int matrixA[][DIM], int matrixB[][DIM], int matrixC[][DIM], int linhaA, int colunaA );

int main() {
    int matrizA[DIM][DIM], matrizB[DIM][DIM], matrizC[DIM][DIM];
    int linhaA, colunaA;
    int i,j;

    linhaA = DIM-1; 
    colunaA = DIM;

    for(i = 0; i < linhaA; i++){
        for(j = 0; j < colunaA; j++){
            matrizA[i][j] = i+j;
            matrizB[j][i] = i-j;            
        }
    }

    matrix_mult(matrizA, matrizB, matrizC, linhaA, colunaA);

    return 0;
}


void matrix_mult(int matrixA[][DIM], int matrixB[][DIM], int matrixC[][DIM], int linhaA, int colunaA ){
    for (int i = 0; i < linhaA; i++) {
        for (int j = 0; j < colunaA; j++) { 
            int aux = 0;
            for (int k = 0; k < colunaA; k++) {
                aux += matrixA[i][k] * matrixB[k][j];
            }

            matrixC[i][j] = aux;
            printf("[%d][%d] = %d\t", i, j, matrixC[i][j]);
        }
        printf("\n");
    }
}