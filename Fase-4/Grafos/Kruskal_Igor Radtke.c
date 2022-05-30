#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

// Arresta
typedef struct _edge {
	int origem;
	int destino;
	int value;
} Edge;

// Lista de arresta
typedef struct _list_edge {
	Edge *edge;
	struct _list_edge *next;
} ListEdge;

// Grafo
typedef struct {
	ListEdge *listEdge;
} Graph;

// Dados
typedef struct {
	int root[SIZE];
	ListEdge *listEdge;
} Data;

// Iniciar grafo
Graph  *graphInit(){
	Graph *graph = malloc (sizeof(Graph));
	graph->listEdge = NULL;
	return graph;
}

// Inicia dados
Data *initData() {
  	Data *data = malloc (sizeof(Data));
	int count;

	// Percorre dados para iniciar valores
	for ( count = 0; count < SIZE; count++ ){ 
		data->root[count] = -1; // Coloca valor inicial na raiz  
  	}
	return data;
}

// Inserir arresta ordenadamente
ListEdge *edgeSorted ( ListEdge *listEdge, int origem, int destino, int value){
	
	// Cria variaveis auxiliares
	ListEdge *aux, *ant = NULL;
	ListEdge *newElement = malloc ( sizeof(ListEdge) );

	// Cria arresta
	newElement->edge = malloc ( sizeof(Edge) );
	newElement->edge->origem = origem;
	newElement->edge->destino = destino;
	newElement->edge->value = value;

	// Define proximo como null
	newElement->next = NULL;
	aux = listEdge;

	while ( aux != NULL && aux->edge->value <= value ) {
		ant = aux;
		aux = aux->next;
	}

	// Insere primeiro
	if (ant == NULL) {
		newElement->next = listEdge;
		listEdge = newElement;
	
	// Insere no meio
	} else {
		newElement->next = ant->next;
		ant->next = newElement;
	}
	return listEdge;
}

// Insere arresta
ListEdge *insertEdge (ListEdge *listEdge, Edge *edge){

	ListEdge *aux,*newElement = malloc (sizeof(ListEdge));
	newElement->edge = edge;

	if (listEdge == NULL){
		listEdge = newElement;
	}else{
		aux = listEdge;
		while ( aux->next != NULL){ 
			aux = aux->next;
		}
		aux->next = newElement;
		newElement->next = NULL;		
	}
	return listEdge;
}

// Imprimir arrestas
void printListEdge(ListEdge *head){
	ListEdge *aux = head;

	printf("Caminho até agora: ");
	while (aux != NULL){
		printf("(%d, %d), ", aux->edge->origem, aux->edge->destino);
		aux= aux->next;
	}
	printf("\n\n");
}

// Imprime dados
void printData( Data *data ) {
	int count;

	printf("indi -> |");
	for ( count = 0; count < SIZE; count++ ) {
		printf(" %d \t|", count);
	}
	printf("\n");

	printf("raiz -> |");
	for ( count = 0; count < SIZE; count++ ) {
		printf(" %d \t|", data->root[count] );
	}
	printf("\n\n");
}

// Kruskal
void kruskal( ListEdge *listEdge, Data *data ) {
	int orign, destin;
	ListEdge *aux = listEdge;

	// Percorre enquanto haver arrestas na lista
	while ( aux != NULL ){
		printf("\n******* Estado atual *******\n");
		orign = aux->edge->origem;
		destin = aux->edge->destino;

		// Caso item tiver raiz em outro vertice
		if ( data->root[orign] >= 0 ) {
			orign = data->root[orign];
		}
		if ( data->root[destin] >= 0 ) {
			destin = data->root[destin];
		}

		// Imprime qual aresta está sendo explorada
		printf("Visitando aresta: (%d, %d) - %d\n\n", aux->edge->origem, aux->edge->destino, aux->edge->value );
		if ( orign != destin ) {
			if ( data->root[orign] < data->root[destin] ) {
				// Atribui dados
				data->root[orign] += data->root[destin];
				data->root[destin] = orign;
			} else {
				data->root[destin] += data->root[orign];
				data->root[orign] = destin;
			}
			data->listEdge = insertEdge(data->listEdge, aux->edge);
		} 
		
		// Print dado e caminho
		printData(data);
		printListEdge(data->listEdge);
		aux = aux->next; // Vai para o proximo elemento
	}
}

// Faz custo minimo
void Soma( ListEdge *head) {
	ListEdge *aux = head;
	int SomaValor = 0;

	printf("Resultado:\n\t");
	while (aux != NULL){
		printf("(%d, %d), ", aux->edge->origem, aux->edge->destino);
		SomaValor += aux->edge->value;
		aux= aux->next;
	}
	printf("\n\tCusto minimo: %d\n", SomaValor);
}

int main(){
	int count;
	Graph *graph = graphInit();
	Data *data = initData();
  
	graph->listEdge = edgeSorted(graph->listEdge, 1, 5, 3);
	graph->listEdge = edgeSorted(graph->listEdge, 5, 6, 2);
	graph->listEdge = edgeSorted(graph->listEdge, 0, 1, 5);
	graph->listEdge = edgeSorted(graph->listEdge, 0, 3, 3);
	graph->listEdge = edgeSorted(graph->listEdge, 1, 3, 8);
	graph->listEdge = edgeSorted(graph->listEdge, 5, 7, 3);
	graph->listEdge = edgeSorted(graph->listEdge, 6, 7, 4);
  
	kruskal(graph->listEdge, data);
	Soma(data->listEdge);
	return 0;
}