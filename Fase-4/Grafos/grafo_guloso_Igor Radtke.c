#include <stdio.h>
#include <stdlib.h>

int opt(int **matri, int l, int v, int valueDestin){
    int count = 0;
    printf("\n___________ Opcoes Disponiveis ___________\n\n");
    for(int c = 0; c < v; c++){
        if(matri[l][c] > 0){
            printf("| Vertice: %d |  Custo: %d\n", c+1, matri[l][c]);
            count++;
        }
    }
    if(matri[l][valueDestin] > 0){
        return 1;
    }
    if (count == 0){
        printf("Impossivel com o Guloso\n\n");
        return 0;
    }
    return -1;
}

int little(int **matri, int l, int v){
    int small = 20000000;
    for(int c=0; c < v; c++){
        if(matri[l][c] < small && matri[l][c] != 0 && c != l){
            small = matri[l][c];
        }
    }
    return small;
}

void guloso(int **matri, int v, int valInicio, int valueDestin){
    int l = valInicio, cost = 0, count = 0;
    while(l < v){
        if(count > v){
            printf("\nCansei! Impossivel com o guloso\n\n");
            return;
        }
        int op = opt(matri, l, v, valueDestin);
        if (op == 1){
            printf("\n___________ Opcao Escolhida ___________\n");
            cost+= matri[l][valueDestin];
            printf("| Vamos para o vertice %d | Custo: %d\n\n", valueDestin+1, cost); 
            printf("*Chegamos ao destino*\n_________________________________________");
            return;
        }
        if(op == 0){
            return;
        }
        for(int c = 0; c < v; c++){
            if(matri[l][c] == little(matri, l, v)){
                printf("\n___________ Opcao Escolhida ___________\n");
                cost+= matri[l][c];
                printf("| Indo para o vertice %d | tem o Custo: %d\n", c+1, cost);
                l = c;
                break;
            }
        }
        count++;
    }
}

int main(){
    int **Adj;
    int v;
    printf("\nInsira o tamanho do grafo: ");
    scanf("%d",&v);

    Adj = (int *) malloc(sizeof(int *)*v);
    for(int l = 0; l < v; l++){
        Adj[l] = malloc(sizeof(int)*v);
    }

    for(int l = 0; l < v; l++){
        for(int c = 0; c < v; c++){
            printf("Inira o valor %d, %d: ", l,c);
            scanf("%d", &Adj[l][c]);
        }
    }

    printf("\n___________ Matriz ___________\n");

    for(int l = 0; l < v; l++){
        for(int c = 0; c < v; c++){
            printf("%d\t|", Adj[l][c]);
        }
        printf("\n");
    }

    guloso(Adj, v, 0, v-1);   
}