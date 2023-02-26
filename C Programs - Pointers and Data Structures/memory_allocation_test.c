#include <stdlib.h>
#include <stdio.h>

int main(){
int *p;

        p = (int *)malloc(sizeof(int));
        *p=123;
        printf("valor P = %d \n",*p);
        printf("ponteiro P = %p \n\n",p);
        system("PAUSE");

         p = (int *)malloc(sizeof(int));
         *p=456;
         printf("valor P = %d \n",*p);
         printf("ponteiro P = %p \n\n",p);
         system("PAUSE");

        p = (int *)malloc(sizeof(int));
        *p=789;
        printf("valor P = %d \n",*p);
        printf("ponteiro P = %p \n\n",p);
        system("PAUSE");
}


