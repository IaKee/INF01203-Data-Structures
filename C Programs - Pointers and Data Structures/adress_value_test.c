#include <stdio.h>
#include <stdlib.h>

int main(){
        int a, *p1,*p2;
        a = 10;
        p1 = &a;
        p2 = p1;
        printf("a = %d \n",a);
        printf("*p1 = %d \n *p2 = %d \n \n",*p1, *p2);
        printf("p1 = %p \n p2 = %p \n &a = %p \n",p1, p2, &a);
        system("PAUSE");
        *p1 = 20;
         a = 30;
        *p2 = 40;
        printf("a = %d \n",a);
        printf("*p1 = %d \n *p2 = %d \n \n",*p1, *p2);
        printf("p1 = %p \n p2 = %p \n &a = %p \n",p1, p2, &a);
        system("PAUSE");
}



