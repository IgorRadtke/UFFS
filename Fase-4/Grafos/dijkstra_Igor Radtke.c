// Matricula: 2011100038

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void MostratDijkstra(int matAux[TAM][4], int n, int visit){
    printf("      vert.\t|     Visit\t|     Valor\t|    Anterior   |\n");
    for(int l = 0; l < n; l++){
        for(int c = 0; c < 4; c++){
            if(matAux[l][c] == 100){
                printf("\t100\t|");
            }
            else{
                printf("\t%d\t|", matAux[l][c]);
            }
        }
        printf("\n");
    }
}

void Dijkstra(int adj[TAM][TAM], int matAux[TAM][4], int n, int valInit){
    int l = valInit;
    matAux[l][2] = 0;
    while(l < n){
        printf("\n\n____________________ Visitando o vertice |%d| ____________________\n\n", l);
        matAux[l][1] = 1;

        for(int c = 0; c < n; c++){
            if(adj[l][c] != 0 && matAux[c][1] != 1 && (adj[l][c] + matAux[l][2]) < matAux[c][2]){
                matAux[c][2] = adj[l][c] + matAux[l][2];
                matAux[c][3] = l;
            }
        }
        MostratDijkstra(matAux, n, l); 

        int small = little(matAux, n);
        if(small == -1 || small > n){
            return;
        }
        l = small;
    }
}

int little(int matAux[TAM][4], int n){
    int small = 100;
    int posi;
    for(int l = 0; l<n; l++){
        if (matAux[l][1] != 1 && matAux[l][2] < small){
            small = matAux[l][2];
            posi = l;
        }
    }
    if(small == 100){
        return -1;
    }
    return posi;
}

int main(){
    int matAux [TAM] [4];
    for(int l = 0; l < TAM; l++){
        matAux[l][0] = l;
        matAux[l][1] = 0;
        matAux[l][2] = 100;
        matAux[l][3] = -1;
    }
    int adj[TAM][TAM] = {
        /*  A    B   C    D    E */
    /*A*/ { 0,  20,  4,   0,   23},
    /*B*/ { 20, 0,   17,  58,  0},
    /*C*/ { 4,  17,  3,   3,   15},
    /*D*/ { 0,  58,  3,   0,   0},
    /*D*/ { 23, 0,   15,  0,   0},
    };

    printf("\n_____________ Matriz _____________\n\n");

    for(int l = 0; l < TAM; l++){
        for(int c = 0; c < TAM; c++){
            printf("%d\t|", adj[l][c]);
        }
        printf("\n");
    }
    int valInit;
    printf("\nInsira o valor inicial desejado: ");
    scanf("%d", &valInit);
    Dijkstra(adj, matAux, TAM, valInit);
}