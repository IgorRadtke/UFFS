#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 6

//inicio lista encadeada
struct _dado{
    int Stack;
    struct _dado *before;
};
typedef struct _dado Dado;

typedef struct _pilha{
	Dado *init;
}tp_pilha;


void inicio (tp_pilha *aponta){
    aponta->init = NULL;
    return;
};

// SEQUENCIA EM PILHA
tp_pilha insert_Dado (tp_pilha order, int dado){
    Dado *Elemento;
    Elemento=(Dado *)malloc(sizeof(Dado));
    Elemento->Stack = dado;
    Elemento->before = NULL;

    if(order.init==NULL){
        order.init=Elemento;
    }
    else{
      Elemento->before = order.init;
      order.init = Elemento;
    }
    return order;
}

void printStack(tp_pilha order) {
    Dado *aux;
    printf("\nPilha == ");
    for (aux = order.init; aux != NULL; aux = aux->before) {
        printf("%d, ", aux->Stack);
    }
    printf("\n");
    printf("********************\n\n\n");
}

tp_pilha delStack(tp_pilha order) {
    Dado *aux; 
    aux = order.init->before;
    free(order.init);
    order.init = aux;
    return order;
};

//organiza DFS
void DFS(int inicio, int destino, int adj[TAM][TAM], tp_pilha order, int prev[TAM], int visit[TAM], int saida[TAM], int closed[TAM], int entry[TAM]) {
    int i = inicio;
    int count = 1;
    order = insert_Dado(order, i);
    visit[i] = 1;
    entry[i] = 1;
    while (i != destino || order.init != NULL) {
        count++;
        printStack(order);
        printf("Visit == %d\n", i);
        printf("____________________________________________________________________\n");
        printf("      vertex    |     visit     |      cost     |     saida     |    previous   |\n");

        for(int i = 0; i < TAM; i++) {
            printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|", i, closed[i],entry[i], saida[i], prev[i]);
            printf("\n");
        }
        for (int l = 0; l < TAM; l++) {
            if (adj[i][l] == 1 && closed [l] != 1) {
                if (visit[l] != 1) {
                    order = insert_Dado(order, l);
                   entry[l] = count;
                }
                visit[l] = 1;
                prev[l] = 1;
                i=l;
                break;
            }
            else if (l == TAM-1){
                closed[i]=1;
                order = delStack(order);
                i = order.init->Stack;
                saida[i] = count;
            }
        }
        if(i == destino){
            printf("__________________\n");
            printf("__CHEGADA AO DESTINO %d__\n", order.init->before->Stack);
            printf("__________________\n");
            return;
        }
    }
}

int main() {
    //matriz adjacencia
    int adj[TAM][TAM] = {
        /*  A    B    C    D    E   F*/
    /*A*/ { 0,   1,   1,   0,   0,  0},
    /*B*/ { 0,   0,   1,   0,   0,  0},
    /*C*/ { 0,   0,   0,   0,   0,  0},
    /*D*/ { 0,   0,   0,   0,   0,  1},
    /*E*/ { 0,   0,   0,   0,   0,  0},
    /*F*/ { 0,   1,   0,   0,   0,  0},
    };
    int inicio;
    int destino;
    printf("___________________________\n");
    printf("Digite um valor inicial: ");
    scanf("%d", &inicio);
    printf("\n");
    printf("Digite um valor de destino: ");
    scanf("%d", &destino);
    printf("\n");

    int prev[TAM], visit[TAM], closed[TAM], saida[TAM], entry[TAM];
    for (int i = 0; i < TAM; i++) {
        prev[i] = -1;
        visit[i] = 0;
        saida[i] = 0;
        closed[i] = 0;
        entry[i] = 0;
    }
    tp_pilha order;
    order.init = NULL;
    
    DFS(inicio, destino, adj, order, prev, visit, saida, closed, entry);
    return 0;
}