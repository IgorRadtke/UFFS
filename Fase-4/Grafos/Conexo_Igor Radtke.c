#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3

void percorre(int mat[N][N], int vet[N], int o){
  vet[o]++;
  for(int i = 0; i < N; i++){
    if(!vet[i] && mat[o][i]){
      
      percorre(mat,vet,i);
    }
  }
}

int isconexo (int mat[N][N], int o){
  int vet[N];
  for(int i = 0; i < N; i++){
    vet[i] = 0;
  }
  int count = 0;

  percorre(mat,vet, o);

  for(int i = 0; i < N; i++){
    if (vet[i])
      count++;
  }
  if (count == N)
    return 1;
  else
    return 0;
}


int main() {
    //matriz adjacencia
    int mat[N][N] = {
        /*  A   B   C  */
    /*A*/ { 0,  0,  1},
    /*B*/ { 0,  0,  1},
    /*C*/ { 1,  0,  0},
   
    };
    int origem;
    
    printf("___________________________\n");
    printf("Digite um valor inicial: ");
    scanf("%d",&origem);
    printf("\n");

    if(isconexo (mat, origem)==1)
      printf("É CONEXO");
    else
      printf("NÃO É CONEXO");
}