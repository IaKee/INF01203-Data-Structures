#include <stdlib.h>
#include <stdio.h>

int main(){
int *p;
int i;
        p = (int *)malloc(sizeof(int));
        i=100;
        *p= i;
        printf(" conteudo i: %d\n conteudo p: %d\n endereco i: p %d\n endereco p: p %d\n",i, *p,(int)&i,(int)p);
        system("PAUSE");
        i=40;
        printf(" conteudo i: %d\n conteudo p: %d\n endereco i: p %d\n endereco p: p %d\n",i, *p,(int)&i,(int)p);
        system("PAUSE");
        p= &i;
        printf(" conteudo i: %d\n conteudo p: %d\n endereco i: p %d\n endereco p: p %d\n",i, *p,(int)&i,(int)p);
        system("PAUSE");
        i=55;
        printf(" conteudo i: %d\n conteudo p: %d\n endereco i: p %d\n endereco p: p %d\n",i, *p,(int)&i,(int)p);
        system("PAUSE");
        free(p);
}
