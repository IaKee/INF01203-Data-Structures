#include <stdio.h>
#include <stdlib.h>

typedef struct Tpessoa{
       char nome[30];
       struct Tpessoa *elo;
}pessoa;

int main(){
pessoa *p1;
pessoa *p2;
   p1 = (pessoa*) malloc(sizeof(pessoa));
   p2 = (pessoa*) malloc(sizeof(pessoa));
   printf("nome ");
   scanf("%s",&p1->nome);
   printf("nome ");
   scanf("%s",&p2->nome);
   printf("Endereco p1: %p\n",p1);
   printf("Endereco p2: %p\n",p2);
   system("PAUSE");

   p1->elo=p2;
   printf("Endereco p1: %p\n",p1);
   printf("Endereco p2: %p\n",p2);
   system("PAUSE");
   printf("Nome  p1->nome: %s\n",p1->nome);
   printf("Nome  p2->nome: %s\n",p2->nome);
   system("PAUSE");
   printf("Endereco p1->elo: %p\n",p1->elo);
   printf("Endereco p2->elo: %p\n",p2->elo);
   system("PAUSE");

   free(p1);
   free(p2);
   system("PAUSE");
}



