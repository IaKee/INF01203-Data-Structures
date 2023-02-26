#include "lab3.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>  //necessaria para o malloc
#include <string.h> //necessaria para o strcmp

int checa_divisibilidade(int val)
{ /* CHECA SE O NUMERO INSERIDO É PAR OU ÍMPAR */

    int resultado;
    if(val%2 == 0)  //TESTA SE É PAR
    {
        resultado = 0;
        return resultado;
    }
    else            //CASO CONTRÁRIO É ÍMPAR
    {
        resultado = 1;
        return resultado;
    }

    resultado = 2;  //ISSO NÃO DEVE SER EXECUTADO

    return resultado;
}
tipoNumero* cria_lista()
{ /* CRIA NOVA LISTA VAZIA */

    return NULL;
}
tipoNumero* encontraUltimo(tipoNumero* ptInicio)
{ /* ESSA FUNÇÃO ENCONTRA E RETORNA O ÚLTIMO ELEMENTO DA LISTA */

    tipoNumero *aux; //ponteiro auxiliar
    aux = ptInicio;

    while (aux->prox != NULL)   //Enquanto o próximo elemento não for o último da lista
    {
		aux = aux->prox;        /*atualiza uma posição a cada iteração: ponteiro é ponteiro++
                                        até que encontre o último elemento da lista */
    }

	return aux; // retorna a posição de memória do último elemento da lista
}
tipoNumero* insere_elementos (tipoNumero* ptInicio, tipoNumero val)
{ /* FUNÇÃO QUE TESTA AS CONDIÇÕES E INSERE OS ELEMENTOS NA LISTA CONFORME A DEFINIÇÃO */

    tipoNumero *novo; //novo elemento
    tipoNumero *ant = NULL; //ponteiro auxiliar para a posição anterior
    tipoNumero *ptaux = ptInicio; //ponteiro auxiliar para percorrer a lista

    /*aloca um novo nodo */
    novo = (tipoNumero*) malloc(sizeof(tipoNumero));
    /*insere a informação no novo nodo*/
    novo->num= val.num;

    /*procurando a posição de inserção*/
    val.flag = checa_divisibilidade(val.num); //Checa divisibilidade, alterando o valor da flag

    if (ptInicio == NULL) //Se a lista estiver vazia
    {
        ptInicio = novo;        //novo valor = primeiro elemento da lista
		ptInicio->prox = NULL;  //elemento depois de "novo" é vazio

	}
	else if(val.flag == 1) //Se for impar
    {
        novo->prox = NULL;  //elemento depois de "novo" é vazio
        encontraUltimo(ptInicio)->prox = novo;   //o próximo elemento depois do ultimo da lista (NULL) recebe o novo numero
    }
    else if(val.flag == 0) //Se for par
    {
        novo->prox = ptInicio;  //elemento depois de novo recebe o primeiro elemento da lista
        ptInicio = novo;    //primeiro elemento da lista recebe o novo numero
    }
    return ptInicio;
}
void imprime(tipoNumero* ptInicio)
{ /*FUNÇÃO PARA IMPRIMIR A LISTA*/

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
{ /* FUNÇÃO PARA DESTRUIR A LISTA */

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
