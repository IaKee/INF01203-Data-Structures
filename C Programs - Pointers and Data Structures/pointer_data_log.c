#include <stdlib.h>
#include <stdio.h>

int main()
{
        int x, *p;

        x = 10;
        *p = x;

        printf("conteudo de x = %d \n",x);
        printf("endereco de x = %p \n",&x);
        printf("endereco de p = %p \n",p);
        printf("conteudo de p = %d \n",*p);
        
        system("pause");
}




