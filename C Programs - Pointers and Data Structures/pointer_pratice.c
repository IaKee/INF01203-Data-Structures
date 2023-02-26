#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count, q, *m;

   count = 100;
   m = &count;
   q = *m;
   printf("conteudo de count = %d\n", count);
   printf("conteudo de q = %d\n",q);
   printf("conteudo de m (endereco de memoria) %p\n",m); //%p para imprimir ponteiros
   printf("endereco de count \n %p\n",&count); //%p para imprimir ponteiros
   printf("m aponta para = %d\n\n",*m); //conteúdo da memória apontada por m
   system("pause");
}

