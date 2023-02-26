//Programa: Laboratorio 4 Estrutura de dados - Lista duplamente encadeada circular
//Nomes: Giordano Souza de Paula e Sabryna Trindade
//Cartoes UFRGS: 00308054

#include "lab4.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    ptLSE *ptLista = cria_lista();

    int entrada;
    do
    {
        printf("Selecione.: \n\t1-Inserir elem \n\t2-Exibir lista normal \n\t3-Exibir lista inversa\n\t4-Destruir lista \n\t0-Sair:\n");
        scanf("%d", &entrada);
        int valor;

        if(entrada==1)
        {
            printf("\nDigite um numero: ");
            scanf("%d", &valor);
            ptLista = insere(ptLista, valor);
        }
        if(entrada==2)
        {
            ExibeIni(ptLista);
        }
        if(entrada==3)
        {
            printf("\nDigite um numero para o inicio da lista: ");
            scanf("%d", &valor);
            ExibeInversoNum(ptLista, valor);
        }
        if(entrada==4)
        {
            ptLista = Destroi(ptLista);
        }
    }
    while (entrada != 0);

    Destroi(ptLista);
    return 995989452; //hehe
}


