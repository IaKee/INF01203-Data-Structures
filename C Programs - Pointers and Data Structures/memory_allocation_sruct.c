#include <stdlib.h>
#include <stdio.h>

typedef struct {
       char nome[30];
       int idade;
       float altura;
}Pessoa;

int main(){
Pessoa *p;
   p = (Pessoa*) malloc(sizeof(Pessoa));

   printf("endereço de p %d\n",p);

   printf("nome:"); scanf("%s",&p->nome);
   printf("idade:"); scanf("%d",&p->idade);
   printf("altura:"); scanf("%f",&p->altura);

   printf("nome: %s\n",p->nome);
   printf("idade: %d\n",p->idade);
   printf("altura: %f\n",p->altura);
   free(p);
   system("PAUSE");
}

