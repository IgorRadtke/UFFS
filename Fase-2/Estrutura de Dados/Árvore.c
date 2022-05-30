#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TpNodo{
    char key;
	struct TpNodo *dir, *esq;
}TpNodo;

TpNodo *TreeRebuild(char preordemEst[], int rootIndex, int *qtdNos) {
    TpNodo *root;
    int qtdNosSubarv;

    if (rootIndex < 0) {
        return NULL;
    }

    root = malloc(sizeof(TpNodo));
    root->key = preordemEst[rootIndex];
    root->esq = NULL;
    root->dir = NULL;

    *qtdNos = 1;

    if (preordemEst[rootIndex + 1] != '0') {
        root->esq = TreeRebuild(preordemEst, rootIndex + 3, &qtdNosSubarv);
        *qtdNos += qtdNosSubarv;
    }

    if (preordemEst[rootIndex + 2] != '0') {
        root->dir = TreeRebuild(preordemEst, rootIndex + (*qtdNos * 3), &qtdNosSubarv);
        *qtdNos += qtdNosSubarv;
    }

    return root;
}

void inOrder(TpNodo *pRaiz){
    if(pRaiz != NULL){
        inOrder(pRaiz->esq);
        printf("%c", pRaiz->key);
        inOrder(pRaiz->dir);
    }
}
void afterOrder(TpNodo *pRaiz){
    if(pRaiz != NULL){
        afterOrder(pRaiz->esq);
        afterOrder(pRaiz->dir);
        printf("%c", pRaiz->key);
    }
}

TpNodo *tFree(TpNodo *root)
{
  if (root != NULL){
  tFree(root->esq);
  tFree(root->dir);
  printf("0");
  free(root);
  }
  return NULL;
}

int main() {
    int qtdNos;
    int tamPreordemEst;
    char *preordemEst = NULL;
    TpNodo *root;

    // Le a quantidade de nos da arvore binaria
    scanf("%d", &qtdNos);

    tamPreordemEst = qtdNos * 3;
    preordemEst = malloc((tamPreordemEst + 1) * sizeof(char));

    // Le o percurso em pre-ordem estendido da arvore binaria
    scanf("\n");
    fgets(preordemEst, tamPreordemEst + 1, stdin);
    preordemEst[strcspn(preordemEst, "\n")] = '\0';

    if (qtdNos > 0) {
        root = TreeRebuild(preordemEst, 0, &qtdNos);
        inOrder(root);
        printf("\n");
        afterOrder(root);
        printf("\n");
        tFree(root);
        printf("\n");
    }
    else {
        root = NULL;
    }
    return 0;
}
