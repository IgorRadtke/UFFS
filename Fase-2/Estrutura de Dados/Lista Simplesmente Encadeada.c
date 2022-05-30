#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// data
typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

// cadastrar

struct estudante{
  char matricula[10];
  char nome[40];
  Data nascimento;  
  float nota;
  struct estudante *next;
}; 
typedef struct estudante Estudante;

void printData(Data d)
{
  printf("%d/%d/%d, ",d.dia,d.mes,d.ano);
}

Estudante *getLast(Estudante *p)
{
  Estudante *aux=p;
  for (aux=p;aux->next!=NULL;aux=aux->next);
  return aux;
}

Estudante *getEmployee(Estudante *e)
{
  Estudante *p, *aux;
  p=(Estudante *)malloc(sizeof(Estudante));
  // printf("matricula\n");
  scanf("%s",p->matricula);
  // printf("Nome\n");
  scanf("%s",p->nome);
  // printf("data\n");
  scanf("%d/%d/%d",&p-> nascimento.dia, &p-> nascimento.mes, &p-> nascimento.ano);
  // printf("nota\n");
  scanf("%f",&p->nota);
  p->next=NULL;
  if (e==NULL)
     e=p;
  else
  {
    aux=getLast(e);
    aux-> next=p;
  }
  return e;
}


// printar

void printEmployee(Estudante *e)
{
  Estudante *aux;
  for (aux=e;aux!=NULL;aux=aux->next)
  {
    printf("%s, ",aux->matricula);
    printf("%s, ",aux->nome);
    printData (aux-> nascimento);
    printf ("%.2f\n", aux-> nota);
  }
}

// Delete

Estudante *excluiEstudante(Estudante *prim, char excluiMatri[10]){
	Estudante *aux, *ant = NULL;

	for(aux = prim; aux != NULL; aux=aux->next){
		if (strcmp(aux->matricula,excluiMatri)==0){
			if (prim == aux){
				prim = aux->next;
			}else{
				ant->next = aux->next;
			}
			free(aux);
		}
		ant = aux;
	}
	return prim;
}



// Inversa

void print_inversa(Estudante *chama){
  if(chama != NULL){
    print_inversa(chama->next);
    printf("%s, ",chama->matricula);
    printf("%s, ",chama->nome);
    printData (chama-> nascimento);
    printf ("%.2f\n", chama-> nota);
  }
}


// menu

int main(){
  Estudante *primeiro = NULL;
  int menu; 
  int tamanho;
  tamanho = 0;
  scanf("%d", &menu);
  while (menu != 0){
    if(menu==1){
      primeiro = getEmployee (primeiro);
      tamanho = tamanho +1;
      scanf ("%d", &menu);
    }
    if(menu==2){
      if(tamanho == 0){
        printf("Lista Vazia!");
        scanf("%d", &menu);
      }
      else{
        char exclui[10];
        scanf("%s", exclui);
        primeiro = excluiEstudante(primeiro, exclui);
        tamanho = tamanho-1;
        scanf("%d", &menu);
      }
    }
    if(menu==3){
      if(tamanho == 0){
        printf("Lista Vazia!\n");
        scanf("%d", &menu);
      }
      else {
        printEmployee(primeiro);
        scanf("%d", &menu);
      }
    }
    if(menu==4){
      if(tamanho == 0){
        printf("Lista Vazia\n");
        scanf("%d", &menu);
      }
      else{
        print_inversa(primeiro);
        scanf("%d", &menu);
      }
    }
    if(menu==5){
      printf("%d\n", tamanho);
      scanf("%d", &menu);
    }
  
    if(menu==0){
      int x;
      for(x=0;x<tamanho;x++){
        printf("-");
      }
    break;
    }
  }     
}