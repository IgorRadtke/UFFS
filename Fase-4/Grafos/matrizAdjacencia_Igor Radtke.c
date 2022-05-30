#include <stdio.h>
#include <stdlib.h>

#define TAM 4

void OrientedMatrix(int objects[TAM][TAM]) {

    int L, C = 0, i, entryGrade = 0, outputDegree = 0;
    printf("\n    ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (i = 0; i < TAM; i++) {
        printf("___");
    }
    printf("\n");
    for (L = 0; L < TAM; L++) { 

        printf("%d | ", L + 1);
        for (C = 0; C < TAM; C++) {
            printf("%d ", objects[L][C]);
            if (objects[L][C] == 1) {
                outputDegree += 1;
            }
            if (objects[C][L] == 1) {
                entryGrade += 1;
            }
        }

        printf("| Entrada(%d)", entryGrade);  
        printf(" - Saida(%d)", outputDegree);

        if (outputDegree == 0) {
            printf(" -> Sumidouro");
        }
        if (entryGrade == 0) {
            printf(" -> Fonte");
        }
        printf("\n");
        outputDegree = 0;
        entryGrade = 0;
    }
}

void UnorientedMatrix(int objects[TAM][TAM]) {

    int L, C, i, grade = 0;
    printf("\n    ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (i = 0; i < TAM; i++) {
        printf("___");
    }
    printf("\n");
    for (L = 0; L < TAM; L++){
        printf("%1.d | ", L + 1);
        for (C = 0; C < TAM; C++) {
            printf("%d ", objects[L][C]);
            if (objects[L][C] == 1){
                grade+=1;
            }
        }
        printf("| grau (%d)\n", grade);
        grade = 0;
    }
}

int main() {

    int adjacentMatrix [TAM][TAM] = {
        /*  A  B  C  D  */
    /*A*/ { 0, 1, 0, 0},
    /*B*/ { 0, 0, 1, 0},
    /*C*/ { 0, 1, 0, 1},
    /*D*/ { 0, 0, 0, 0},
    };

    int guides = 0;
    printf("\t********************\n\t| Seu grafo é:     |\n\t| 0 = Nao orientado |\n\t| 1 = Orientado     |\n\t********************\n");
    scanf("%d", &guides);

    if (guides == 0) {
        UnorientedMatrix(adjacentMatrix);
    }
    else {
        OrientedMatrix(adjacentMatrix);
    }
    printf("**************************************************\n");
    return 0;
}