#include <stdio.h>
#include <stdlib.h>

int main(){

int *p,*x,*y;
        p = (int *)malloc(sizeof(int)); 
        *p = 10;
        x=p;
        y=p;
        printf("conte�do p: %d\n",*p);
        *p=20;
        printf("conte�do p: %d\n",*p);
        printf("p: %p\nx: %p\ny:%p\n",p,x,y);
        system("PAUSE");
        free(p);
      
}


