#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 60

struct _site{
    char nome[TAM];
    struct _site *next;
};
typedef struct _site Site;

typedef struct _pilha{
	Site *head;
    Site *tail;
}tp_pilha;


void inicio (tp_pilha *aponta){
    aponta->head = NULL;
    aponta->tail = NULL;
    return;
};

// SEQUENCIA EM PILHA
tp_pilha insert_site (tp_pilha pilha,char S[TAM]){
    Site *Elemento;
    Elemento=(Site *)malloc(sizeof(Site));
    strcpy (Elemento->nome,S);
    Elemento->next=NULL;
    if(pilha.tail==NULL){
        pilha.head=Elemento;
        pilha.tail=Elemento;
    }
    else{
        Elemento->next=pilha.tail;
        pilha.tail=Elemento;
    }
    return pilha;
}

// DELETA
tp_pilha DeletDaPilha(tp_pilha Verify){
    Site *delet;
    delet=Verify.tail;
    if(Verify.tail!= NULL){
        printf("%s\n",Verify.tail->nome);
        Verify.tail = Verify.tail->next;
        free(delet);
    }else{
        printf("Vazio\n");
    }
    return Verify;
}



int main(){
    tp_pilha cria;
    inicio(&cria);
    char site[TAM];
    scanf("%s", site);
    while (strcmp(site,"E")!=0){
        if(strcmp(site,"B")==0){
            cria=DeletDaPilha(cria);
            scanf("%s",site);
        }else{
            cria=insert_site(cria,site);
            scanf("%s",site);
        }
    }
    Site *info;
    if(cria.tail==NULL){
        printf("!");
    }else{
        while (cria.tail!=NULL){
            info=cria.tail;
            cria.tail=cria.tail->next;
            free (info);
            printf("@");
        }
    }
    printf("\n");
}



