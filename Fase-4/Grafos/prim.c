#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define INFINITE 100

// Arresta
typedef struct edge {
	int origem;
	int destino;
	int valor;
} Edge;

// Lista de arresta
typedef struct list_edge {
	Edge *edge;
	struct list_edge *next;
} ListEdge;

// Define estrutura para armazenar dados 
struct data {
  int visit[SIZE];
  int valor[SIZE];
  int anter[SIZE];
  ListEdge *list_edge;
};
typedef struct data Data;

Data *initData( int vertInicial ) {
  Data *data = malloc (sizeof(Data));
  int i;
  
  // Atribui valores
  for (i = 0; i < SIZE; i++){
    data->visit[i] = 0;
    data->anter[i] = -1;
    if ( i == vertInicial ){
      data->valor[i] = 0;
    } else {
      data->valor[i] = INFINITE;
    }
  }
	return data;
}

void printData( Data *data ) {
  int i;
  //Inclui Valores
  printf("Vert.\t| Vis.\t| Valor\t| Anterior\n");
  for (i = 0; i < SIZE; i++){
    printf("\t%d\t|   %d\t|  %d\t|  %d\n", i, data->visit[i], data->valor[i], data->anter[i]);
  }
  printf("}\n\n ");
}

// Inserir arresta
ListEdge *insertEdge (ListEdge *list_edge, int origem, int destino, int valor){
	ListEdge *aux,*newElement = malloc (sizeof(ListEdge));
  newElement->edge = malloc (sizeof(Edge));
  newElement->edge->origem = origem;
  newElement->edge->destino = destino;
  newElement->edge->valor = valor;

	if (list_edge == NULL){
		list_edge = newElement;
	}else{
		aux = list_edge;
		while ( aux->next != NULL){ 
			aux = aux->next;
		}
		aux->next = newElement;
		newElement->next = NULL;		
	}
	return list_edge;
}

// Prim
void prim( int graph[SIZE][SIZE], Data *data, int curVert ) {
  int i, somaVal, nextVertex, valorMin, origem, destino; 
  while ( !data->visit[curVert] ){
    printf("-----------Estado atual----------- {\n");
    // Init variavel loop
    valorMin = INFINITE;
    data->visit[curVert] = 1;
    printf("\t Visitando: %d\n", curVert);
    
    for (i = 0; i < SIZE; i++) {
      somaVal = graph[curVert][i];

      // Verefica se a soma é menor que o valor presente
      if ( somaVal < data->valor[i] && graph[curVert][i] != 0 ){
        // Atualiza valores
        data->valor[i] = somaVal;
        data->anter[i] = curVert;
        data->list_edge = insertEdge( data->list_edge, curVert, i, graph[i][curVert] );
      }
    }

    printData(data);
    for (i = 0; i < SIZE; i++) {

      if (data->valor[i] < valorMin && !data->visit[i]){
        nextVertex = i;
        valorMin = data->valor[i];
      }
    }
    curVert = nextVertex;
  }
}

// Soma do caminho
void Soma( ListEdge *head) {
	ListEdge *aux = head;
	int somaVal = 0;

	printf("Resultado:\n\t");
	while (aux != NULL){
		printf("(%d, %d), ", aux->edge->origem, aux->edge->destino);
		// Acrescenta valor
		somaVal += aux->edge->valor;
		aux= aux->next;
	}
	printf("\n\tSoma: %d\n", somaVal);
}

int main(){

  int vertInicial;
  int graph[SIZE][SIZE] = {
    { 0, 1, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 3, 4 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 3, 0, 0, 0 },
    { 0, 0, 4, 0, 0, 0 },
  };

  printf("informe o vertice inicial: ");
  scanf("%d", &vertInicial);
  
  Data *data = initData(vertInicial);
  // Chama Dijkstra
  prim(graph, data, vertInicial);
  Soma(data->list_edge);
  
	return 0;
}