#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXELE 20
#define OVERFLOW 5

typedef struct{
    int id;
    char nome[41];
    double salario;
    int idade;
}funcionario;

int hash(int idade){
   int posi;
   posi = idade%MAXELE;
   return posi;
}

void inserir(funcionario f, funcionario *tab){
   int posi, i;
   printf("Insira Id: ");
   scanf("%d", &f.id);
   printf("Insira Nome: ");
   scanf("%s", f.nome);
   printf("Insira salario: ");
   scanf("%lf", &f.salario);
   printf("Insira idade: ");
   scanf("%d", &f.idade);
   posi = hash(f.idade);
   if (tab[posi].idade == -1){
        tab[posi] = f;
   }
    else {
        for (i=MAXELE;i<MAXELE+OVERFLOW;i++){ 
		    if (tab[i].idade == -1){
		        tab[i] = f;
                return;
            }
        }   
        printf("Lista Overflow esta cheia!!!\n");
	}
} 

void printar(funcionario *tab){
   int i;
   for(i = 0; i < MAXELE+OVERFLOW; i++){
      if(tab[i].idade != -1) {
         printf("%d = %d, %s, %lf, %d\n", i, tab[i].id, tab[i].nome, tab[i].salario, tab[i].idade);
         if (i == 19) {
         printf("Overflow!\n");
         }
      }
      else{
         printf("%d = -1\n", i);
         if (i == 19) {
         printf("Overflow!\n");
         }
      }  
   }  
}

int main(){
   funcionario f;
   funcionario table[MAXELE+OVERFLOW];
   int menu, i;
   for (i=0;i<MAXELE+OVERFLOW;i++){
      table[i].idade=-1;
   }
   printf("\nInsira:\n\t 1  Para Cadastro\n\t 2  Para Mostrar Cadastros \n");
   scanf("%d", &menu);
   while (menu != 0){
      if(menu == 1){
         inserir(f, table);
         printf("\n\t Insira:\n\t 1 cadastrar\n\t 2 Mostrar Cadastros \n");
         scanf("%d", &menu);
      }
      if(menu == 2){
         printar(table);
         printf("\n\t Insira:\n\t 1 cadastrar\n\t 2 Mostrar Cadastros \n");
         scanf("%d", &menu);
      }   
   }
   return 0;
}