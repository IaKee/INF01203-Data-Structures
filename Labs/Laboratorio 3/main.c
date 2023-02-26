#include "lab3.h"
#include <limits.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>  //necessaria para o malloc
#include <string.h> //necessaria para o strcmp

int main()
{
    tipoNumero* ptInicio;
    tipoNumero valor;

    ptInicio = cria_lista(); //Cria a lista, inicializando com um valor nulo

    do
    {
       printf("Insira um novo numero (zero encerra o processo): ");
       scanf("%d", &valor.num);

       ptInicio = insere_elementos(ptInicio, valor);
    }
    while (valor.num != 0); //Encerra a insercao de elementos se o valor digitado for um zero

    imprime(ptInicio);

    printf("\n");
    system("pause");
    printf("\n");

    ptInicio = destroi(ptInicio);

    printf("\n");
    system("pause");
    printf("\n");
    imprime(ptInicio);


    return 0;
}
