#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    int *p;
    
    x = 100;
    p = &x;
    x = 100,00;
    printf("conteudo x = %f\n",x);
    printf("conteudo p = %p\n",p);
    printf("endereco x = %p\n",&x);
    
    system("pause");
}


