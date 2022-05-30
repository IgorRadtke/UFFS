#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

#define COLOR_RESET  "\x1b[0m"
#define COLOR_RED    "\033[0;31m"
#define COLOR_GREEN  "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE   "\033[0;34m"
#define COLOR_PURPLE "\033[0;35m"
#define COLOR_CYAN   "\033[0;36m"
#define COLOR_WHITE  "\033[0;37m"


// Metodo para mudar print de cor
void printColor(int cor){
  
  switch (cor){
    case 1:
      printf(COLOR_RED "1\n" COLOR_RESET);
      break;
    case 2:
      printf(COLOR_GREEN "2\n" COLOR_RESET);
      break;
    case 3:
      printf(COLOR_BLUE "3\n" COLOR_RESET);
      break;
    case 4:
      printf(COLOR_PURPLE "4\n" COLOR_RESET);
      break;
    case 5:
      printf(COLOR_CYAN "5\n" COLOR_RESET);
      break;
    default:
      printf("default\n");
  }
}
// Forma mudar print de cor
void initColors( int cor[SIZE] ){
  int i;
  for( i = 0; i < SIZE; i++){
    cor[i] = 0;
  }
}

int getTotalCor(int cor[SIZE]){
  int i, totalCor = 0;
  for ( i = 0; i < SIZE; i++){
    
    // Caso numero da cor seja maior que o totalCor
    if (cor[i] > totalCor){
      totalCor = cor[i]; 
    }
  }
  return totalCor;
}

void printColors( int cor[SIZE] ){
  int i;
  printf("\nRESULTADO CORES: \n");
  for( i = 0; i < SIZE; i++){
    printf("%d - ", i);
    printColor(cor[i]);
  }
  printf("\nPara pintar o grafo, foi utilizado %d cores.\n", getTotalCor(cor) );
}

void corGraph( int graph[SIZE][SIZE], int cor[SIZE] ){
  int currentColor, currentAdjacentEdge, currentEdge = 0;

  // Percorre os vertices do grafo
  while( currentEdge < SIZE ){
    currentColor = 1;
    currentAdjacentEdge = 0;
    cor[currentEdge] = currentColor;
    
    // Percorre as adjacencias do vertice
    while( currentAdjacentEdge < SIZE){

      if ( graph[currentEdge][currentAdjacentEdge] ){
        if ( cor[currentAdjacentEdge] && cor[currentAdjacentEdge] == cor[currentEdge] ){
          
          // Insere nova cor 
          cor[currentEdge] = ++currentColor;
          currentAdjacentEdge = 0;
        }
      }
      currentAdjacentEdge++;
    }
    currentEdge++;
  }
}

int main(){
  int cor[SIZE];
  int graph[SIZE][SIZE] = {
    { 0, 4, 3, 8, 0, 0, 0, 0 },
    { 4, 0, 8, 0, 0, 0, 7, 0 },
    { 3, 8, 0, 0, 0, 0, 9, 0 },
    { 8, 0, 0, 0, 0, 9, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 4 },
    { 0, 0, 0, 9, 0, 0, 0, 2 },
    { 0, 7, 9, 0, 0, 0, 0, 4 },
    { 0, 0, 0, 0, 4, 2, 4, 0 },
  };

  initColors(cor);
  corGraph(graph, cor);

  // Imprime cores do grafo
  printColors(cor);
	return 0;
}