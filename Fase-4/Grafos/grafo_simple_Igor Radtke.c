#include<stdio.h>
#include<stdlib.h>

/*
 Vertex linked list
*/
struct _vertex {
    int value;
    int entrada;
    int saida;
    struct _vertex *next;
};
typedef struct _vertex Vertex;

/*
 Edge linked list
*/

struct _edge {
    Vertex *s;
    Vertex *d;
    struct _edge *next;
};
typedef struct _edge Edge;

typedef struct {
    int oriented;
    Vertex *vertexes; //primeiro elemento da lista de vértices
    Edge *edges; //primeiro elemento da lista de arestas
} Graph;

Vertex *insertVertex(Vertex *head, int value){
    Vertex *new = malloc (sizeof(Vertex));
    new->entrada = 0;
    new->saida = 0;
    new->value = value;
    new->next = head;
    return new;
}

//Exemplo de print
void printGraphNotOriented( Graph *graph){
    Vertex *auxV;
    Edge *auxE;
    printf("\n********* Vertexes ************\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
       printf("\t %d --- (%d) \n", auxV->value, (auxV->entrada + auxV->saida));
    }
    
    printf("\n\n********* Edges ************\n");
    if (graph->edges == NULL)
      printf("No edges!");
    else
        for (auxE = graph->edges; auxE!=NULL; auxE=auxE->next) 
            printf("\t (%d, %d)", auxE->s->value, auxE->d->value);
        
    printf("\n");
}

//Exemplo de print
void printGraphOriented( Graph *graph){
    Vertex *auxV;
    Edge *auxE;
    printf("\n********* Vertexes ************\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        printf("\t %d s(%d) d(%d),\n", auxV->value, auxV->saida, auxV->entrada);
    }
    
    printf("\n\n********* Edges ************\n");
    if (graph->edges == NULL)
      printf("No edges!");
    else
        for (auxE = graph->edges; auxE!=NULL; auxE=auxE->next){ 
            printf("\t (%d, %d)", auxE->s->value, auxE->d->value);
        }
    printf("\n\n********* Vertices Fonte ************\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        if (auxV->entrada == 0){
            printf("\t %d", auxV->value);
        }    
    }
    printf("\n\n********* Vertices Sumidouro ************\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        if (auxV->saida == 0){
            printf("\t %d", auxV->value);
        }  
    }     
    printf("\n");
}

Edge *insertEdge(Graph *graph ,int v_origem, int v_destino){
    Edge *newE = malloc (sizeof(Edge));
    Vertex *auxV;
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next){
        if (auxV->value == v_origem){
            auxV->saida ++;
            newE->s = auxV;
        }
        if (auxV->value == v_destino){
            auxV->entrada ++;
            newE->d = auxV;
        }
        newE->next = graph->edges;
    }
    return newE;
}
    // Buscar a Origem e o Destino na lista de Vértices. 
       //Devem ser os mesmo que estão na lista de vértices, não podem ser criados.

//Não orientado:
// -- Listar todos os vertices com os respectivos graus.

//Grafo orientado:
// -- Listar os graus de entrada e saida para cada um dos vértices.
// -- Listar todos os vértices que são sumidouro
// -- Listar todos os vértices que são fonte

Graph *newGraph(){
    Graph *new = malloc (sizeof(Graph));
    
    new->oriented = 0; //não orientado
    new->oriented = 1; // orientado
    
    new->edges = NULL;
    new->vertexes = NULL;
    return new;
}

int main(){
    
    Graph *g1 = newGraph();
    printf("\t-------------\n\t Seu grafo e: \n\t 0 = Nao orientado\n\t 1 = Orientado\n\t-------------\n");
    scanf ("%d", &g1->oriented);

    g1->vertexes = insertVertex(g1->vertexes, 1);
    g1->vertexes = insertVertex(g1->vertexes, 2);
    g1->vertexes = insertVertex(g1->vertexes, 3);
    g1->vertexes = insertVertex(g1->vertexes, 4);
    g1->vertexes = insertVertex(g1->vertexes, 5); 

    g1->edges = insertEdge(g1, 5, 1); 
    g1->edges = insertEdge(g1, 1, 4);
    g1->edges = insertEdge(g1, 4, 3);
    g1->edges = insertEdge(g1, 3, 2);

    if (g1->oriented == 0){
        printGraphNotOriented(g1);}
    if (g1->oriented == 1){
        printGraphOriented(g1);} 

    return 0;
}