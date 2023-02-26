#include <stdlib.h>
#include <stdio.h>

int main(){
int *p;
        p = (int *)malloc(sizeof(int));
        *p=10;
         printf("valor P = %d \n",*p);
         printf("endereco P = %d \n",p);
         free(p);
         system("pause");
        // *p=20;
         //printf("valor P = %d \n",*p);
         //printf("endereco P = %d \n",p);
         system("pause");
}




