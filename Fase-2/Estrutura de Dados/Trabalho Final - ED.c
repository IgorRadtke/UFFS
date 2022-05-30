#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT 10

//Struct que representa a data.
typedef struct {
  int day; 
  int month; 
  int year; 
} Date; 

// Estrutura que contém os campos dos registros da agenda
struct MREC{
  char name[30];  
  Date birth; 
  char email[40];
  char phone[15];
  struct MREC *prev;
  struct MREC *next;
}; 
typedef struct MREC Contact;


// Para pegar o email do ultimo cadastrado(faz a procura).
Contact *getAddress(char Register[10], Contact *h){  
	Contact *p=h;
	while (p!=NULL && strcmp(p->email, Register) != 0){
	    p=p->next;
  }
	if (p==NULL){
		return NULL;
	}
	return p;
}

// Permite o cadastro de um contato.
// É acrescentado o contato apos o parametro de um email. 

void insContactAfter(char ema[10], Contact **top, Contact **baix){
	Contact *novo, *aux, *v=*top;
  // faz a verificação se os email não sao igual.
  char verifica[40];
  int cont;
  printf("Insira seu email: ");
  scanf("%s", verifica);
  while(v!=NULL){
    if (strcmp(v->email, verifica)==0){
      cont=0;
    }else{
      cont=1;
    }
    v=v->next;
  }
  if (cont==0){
    printf("Esse email ja está em uso.\n");
    return;
  }
	aux=getAddress(ema,*top);
	novo=(Contact *)malloc(sizeof(Contact));
  strcpy(novo->email,verifica);
  printf("Insira seu nome: ");
  scanf("%s",novo->name);
  printf("Isira sua data de nascimento: ");
  scanf("%d/%d/%d",&novo->birth.day,&novo->birth.month,&novo->birth.year);
  printf("Insira seu telefone: ");
  scanf("%s",novo->phone);
  novo->next=NULL;
  novo->prev=NULL;
  if (*top == NULL){
    *baix=novo;
    *top=novo;
  }
  else {
    if (aux==NULL) {
      novo->next = *top;
      (*top)->prev = novo;
      *top = novo;
    }
    else {
      if (aux->next == NULL){
        *baix = novo;
        aux->next = novo;
        novo->prev = aux;
      }
      else {
        novo->prev = aux;
        novo->next = aux->next;
        aux->next->prev = novo;
        aux->next = novo;
      }  
    }
  }   
}

// Permite o cadastro de um contato no final da lista.
void insContact (Contact **top, Contact **baix){
	Contact *novo, *aux, *v=*top;
  // faz a verificação se os email não sao igual.
  char verifica[40];
  int cont;
  printf("Insira seu email: ");
  scanf("%s", verifica);
  while(v!=NULL){
    if (strcmp(v->email, verifica)==0){
      cont=0;
    }else{
      cont=1;
    }
    v=v->next;
  }
  if (cont==0){
    printf("Esse email ja está em uso.\n");
    return;
  }
	novo=(Contact *)malloc(sizeof(Contact));
  strcpy(novo->email,verifica);  
  printf("Insira seu nome: ");
  scanf("%s",novo->name);
  printf("Isira sua data de nascimento: ");
  scanf("%d/%d/%d",&novo->birth.day,&novo->birth.month,&novo->birth.year);
  printf("Insira seu telefone: ");
  scanf("%s",novo->phone);
  novo->next=NULL;
  novo->prev=NULL;
  if(*baix==NULL){
    *top=novo;
    *baix=novo;
  }
  else{
    (*baix)->next=novo;
    novo->prev=*baix;
    *baix=novo;
  } 
}


// Permite excluir um contato da agenda baseado no email

void delContact (Contact **prim,Contact **baix){
  Contact *aux = *prim;
  char mat[40];
  scanf("%s", mat);
  if (aux==NULL){
    printf("Lista Vazia!\n");
  }
  while(aux!=NULL){
    if(strcmp(aux->email, mat) == 0){
      if (aux == *prim && aux == *baix){
        free(aux);
        *prim = NULL;
        *baix = NULL;
        break;
        }
      else if (aux == *prim) {
        *prim = aux->next;
        (*prim)->prev = NULL;
        free(aux);
        break;
        }
        else if (aux == *baix) {
          *baix = aux->prev;
          (*baix)->next = NULL;
          free(aux);
          break;
        }
        else {
          aux->prev->next = aux->next;
          aux->next->prev = aux->prev;
          free(aux);
          break;
        }
      
    }aux = aux->next;
  }
}

// Lista os contatos adicionados.
void listContacts(Contact *e)
{
  Contact *aux;
  if(e==NULL){
    printf("Lista Vazia!\n");
  }else{
    for (aux=e;aux!=NULL;aux=aux->next){
      printf("Email: %s\n ",aux-> email);
      printf("Nome: %s\n ",aux->name);
      printf("Data de Nascimento: %d/%d/%d\n ",aux->birth.day,aux->birth.month, aux->birth.year);
      printf ("Telefone: %s\n", aux-> phone);
      printf("-----------------------------------\n");
    } 
  }
}

// Permite consultar um contato da agenda por nome

void queryContact(Contact **prim, Contact **baix){
	Contact *aux = *prim;
  char nom[30];
  scanf("%s", nom);
  if (aux==NULL){
    printf("Lista Vazia!\n");
    
  }
  while(aux!=NULL){
    if(strcmp(aux->name, nom) == 0){
      if (aux == *prim && aux == *baix){
        printf("%s, ",aux-> email);
        printf("%s, ",aux->name);
        printf("%d/%d/%d, ",aux->birth.day,aux->birth.month, aux->birth.year);
        printf ("%s\n", aux-> phone);
        break;
        }
      } 
   }
}  

// Permite a atualização dos dados de um contato da agenda

void upContact(Contact **prim, Contact **baix){
	Contact *aux = *prim;
  char ema[30];
  scanf("%s", ema);
  if (aux==NULL){
    printf("Lista Vazia!\n");
}
  while(aux!=NULL){
    if(strcmp(aux->email, ema) == 0){
      if (aux == *prim && aux == *baix){
        printf("Insira um novo nome: ");
        scanf("%s, ",aux->name);
        printf("Insira uma nova data de nascimento: ");
        scanf("%d/%d/%d, ", &aux->birth.day, &aux->birth.month, &aux->birth.year);
        printf("Insira um novo numero para telefone: ");
        scanf ("%s", aux-> phone);
        break;
        }
      } 
   }
}  
// Da um free no final.(digitando 10).
void freeMem(Contact **prim) {
    Contact *x=prim;
    while (x != NULL) {
        x=x->next;
        free(x);
        printf("-");
    }
    return;
}

// Programa principal
int main(){
  Contact *top=NULL, *baix=NULL;
  char email[40];
  int a=EXIT+1;
    // Contact MContact;
  while (a!=EXIT){
    printf(" ---------------\nInsira a operação desejada:\n 1- Inserir contato abaixo.\n 2- Inserir contato após determinado email.\n 3- Digitar email a ser excluido.\n 4- Para aterar seus dados.\n 5- Para consultar por nome.\n 6- Listar a agenda em ordem.\n ---------------\n");
    scanf ("%d", &a);
    switch(a){
      case 1 :       
        insContact(&top,&baix);
        break;    

      case 2 : 
        printf("Insira um email para parametro \n ");
        scanf("%s", email);
        printf("Digite os dados para cadastro \n");
        insContactAfter(email,&top,&baix); 
        break;  

      case 3 :
        printf("Insira um email para ser exluido: \n");
        delContact (&top, &baix);
        break;

      case 4 :
        upContact(&top, &baix);
        break;

      case 5 :
        printf("Insira o nome a ser consultado: ");
        queryContact(&top, &baix);
        break;

      case 6 :
        listContacts(top); 
        break;
      }
    }
    freeMem(top);
    return 0;
}
