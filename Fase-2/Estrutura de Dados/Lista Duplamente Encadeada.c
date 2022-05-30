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
  struct estudante *anterior;
  struct estudante *proximo;
}; 
typedef struct estudante Estudante;

Estudante *getAddress(char registration[10], Estudante *h){  
	Estudante *p=h;
	while (p!=NULL && strcmp(p->matricula, registration) != 0){
	    p=p->proximo;
  }
	if (p==NULL){
		return NULL;
	}
	return p;
}


void printData(Data d){
  printf("%d/%d/%d, ",d.dia,d.mes,d.ano);
}

Estudante *insertMiddle(char matri[10], Estudante **head, Estudante **tail){
	Estudante *new, *aux;
	aux=getAddress(matri,*head);
	new=(Estudante *)malloc(sizeof(Estudante));
	// printf("matricula\n");
  scanf("%s",new->matricula);
  // printf("Nome\n");
  scanf("%s",new->nome);
  // printf("data\n");
  scanf("%d/%d/%d",&new->nascimento.dia,&new->nascimento.mes,&new->nascimento.ano);
  // printf("nota\n");
  scanf("%f",&new->nota);
	new->proximo=NULL;
	new->anterior=NULL;
  if (*head == NULL){
    *tail=new;
    *head=new;
  }
  else {
    if (aux==NULL) {
      new->proximo = *head;
      (*head)->anterior = new;
      *head = new;
    }
    else {
      if (aux->proximo == NULL){
        *tail = new;
        aux->proximo = new;
        new->anterior = aux;
      }
      else {
        new->anterior = aux;
        new->proximo = aux->proximo;
        aux->proximo->anterior = new;
        aux->proximo = new;
      }  
    }
  }   
  return *head;
}


// printar

void printEmployee(Estudante *e)
{
  Estudante *aux;
  if(e==NULL){
    printf("Lista Vazia!\n");
  }else{
    for (aux=e;aux!=NULL;aux=aux->proximo){
      printf("%s, ",aux->matricula);
      printf("%s, ",aux->nome);
      printData (aux-> nascimento);
      printf ("%.2f\n", aux-> nota);
    } 
  }
}

// Delete

Estudante *excluiEstudante(Estudante **prim, Estudante **tail){
	Estudante *aux = *prim;
  char matriRemov[10];
  scanf("%s\n", matriRemov);
  if (aux==NULL){
    printf("Lista Vazia!\n");
    return *prim;
  }
  while(aux!=NULL){
    if(strcmp(aux->matricula, matriRemov) == 0){
      if (aux == *prim && aux == *tail){
                free(aux);
                *prim = NULL;
                *tail = NULL;
                break;
            }
            else if (aux == *prim) {
                *prim = aux->proximo;
                (*prim)->anterior = NULL;
                free(aux);
                break;
            }
            else if (aux == *tail) {
                *tail = aux->anterior;
                (*tail)->proximo = NULL;
                free(aux);
                break;
            }
            else {
                aux->anterior->proximo = aux->proximo;
                aux->proximo->anterior = aux->anterior;
                free(aux);
                break;
            }
      
    }    aux = aux->proximo;
  }
  return *prim;
}


// Inversa

void printinverso(Estudante *e)
{
  Estudante *aux;
  if(e==NULL){
    printf("Lista Vazia!\n");
  }else{
    for (aux=e;aux!=NULL;aux=aux->anterior){
      printf("%s, ",aux->matricula);
      printf("%s, ",aux->nome);
      printData (aux-> nascimento);
      printf ("%.2f\n", aux-> nota);
    } 
  }
}

void deleteList(Estudante *p) {
  Estudante *aux;
  while (p!= NULL) {
    aux = p;
    p = p->proximo;
    free(aux);
    printf("*");
  }
}

// menu

int main(){
  Estudante *head=NULL, *tail=NULL;
  int menu; 
  char matricula[10];
  scanf("%d", &menu);
  while (menu != 0){
    if(menu==1){
      scanf("%s\n", matricula);
      head=insertMiddle(matricula,&head,&tail);
      scanf ("%d", &menu);
    }
    if(menu==2){
      head = excluiEstudante (&head, &tail);
      scanf("%d", &menu);
    }
    if(menu==3){
      printEmployee(head);
      scanf("%d", &menu);
    }
    if(menu==4){
      printinverso(tail);
      scanf("%d", &menu);
    }
    if(menu==0){
      deleteList (head);
      head = NULL;
      tail = NULL;
      printf("\n\n");
      break;
    }
  }     
}
