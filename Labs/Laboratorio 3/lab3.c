#include "lab3.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>  //necessaria para o malloc
#include <string.h> //necessaria para o strcmp

int checa_divisibilidade(int val)
{ /* CHECA SE O NUMERO INSERIDO � PAR OU �MPAR */

    int resultado;
    if(val%2 == 0)  //TESTA SE � PAR
    {
        resultado = 0;
        return resultado;
    }
    else            //CASO CONTR�RIO � �MPAR
    {
        resultado = 1;
        return resultado;
    }

    resultado = 2;  //ISSO N�O DEVE SER EXECUTADO

    return resultado;
}
tipoNumero* cria_lista()
{ /* CRIA NOVA LISTA VAZIA */

    return NULL;
}
tipoNumero* encontraUltimo(tipoNumero* ptInicio)
{ /* ESSA FUN��O ENCONTRA E RETORNA O �LTIMO ELEMENTO DA LISTA */

    tipoNumero *aux; //ponteiro auxiliar
    aux = ptInicio;

    while (aux->prox != NULL)   //Enquanto o pr�ximo elemento n�o for o �ltimo da lista
    {
		aux = aux->prox;        /*atualiza uma posi��o a cada itera��o: ponteiro � ponteiro++
                                        at� que encontre o �ltimo elemento da lista */
    }

	return aux; // retorna a posi��o de mem�ria do �ltimo elemento da lista
}
tipoNumero* insere_elementos (tipoNumero* ptInicio, tipoNumero val)
{ /* FUN��O QUE TESTA AS CONDI��ES E INSERE OS ELEMENTOS NA LISTA CONFORME A DEFINI��O */

    tipoNumero *novo; //novo elemento
    tipoNumero *ant = NULL; //ponteiro auxiliar para a posi��o anterior
    tipoNumero *ptaux = ptInicio; //ponteiro auxiliar para percorrer a lista

    /*aloca um novo nodo */
    novo = (tipoNumero*) malloc(sizeof(tipoNumero));
    /*insere a informa��o no novo nodo*/
    novo->num= val.num;

    /*procurando a posi��o de inser��o*/
    val.flag = checa_divisibilidade(val.num); //Checa divisibilidade, alterando o valor da flag

    if (ptInicio == NULL) //Se a lista estiver vazia
    {
        ptInicio = novo;        //novo valor = primeiro elemento da lista
		ptInicio->prox = NULL;  //elemento depois de "novo" � vazio

	}
	else if(val.flag == 1) //Se for impar
    {
        novo->prox = NULL;  //elemento depois de "novo" � vazio
        encontraUltimo(ptInicio)->prox = novo;   //o pr�ximo elemento depois do ultimo da lista (NULL) recebe o novo numero
    }
    else if(val.flag == 0) //Se for par
    {
        novo->prox = ptInicio;  //elemento depois de novo recebe o primeiro elemento da lista
        ptInicio = novo;    //primeiro elemento da lista recebe o novo numero
    }
    return ptInicio;
}
void imprime(tipoNumero* ptInicio)
{ /*FUN��O PARA IMPRIMIR A LISTA*/

    tipoNumero* ptaux;
    int conte = 0;

    if (ptInicio == NULL)
    {
        puts("\n\n\t\tA lista esta vazia!!!");
    }
    else
    {
        for (ptaux = ptInicio; ptaux != NULL; ptaux = ptaux->prox)
        {
            if(ptaux->num != 0)
            { //Tira o zero da lista (visualmente)
                printf("\nNumero = %d",ptaux->num);
            }
            conte++;
        }
        printf("\n\n\t\tA lista possui %d elementos.", conte-1);
    }
}
tipoNumero* destroi(tipoNumero* ptInicio)
{ /* FUN��O PARA DESTRUIR A LISTA */

   tipoNumero *ptaux; //ponteiro auxiliar para percorrer a lista
   printf("\n\n\t\tExcluindo lista...");
   while (ptInicio != NULL)
   {
         ptaux = ptInicio;
         ptInicio = ptInicio->prox;
         free(ptaux);
   }
   free(ptInicio);
   printf("\n\t\tLista excluida!");
   return NULL;
}
//Fim do lab3.c
