#include "lab4.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>  //necessaria para o malloc

ptLSE* insere(ptLSE* ptInicio, int num){

ptLSE *novo;        // novo elemento
ptLSE *novo_ant;    // auxiliar para inserir num-1
ptLSE *novo_prox;   // auxiliar para inserir num+1
ptLSE *ptAux;       // auxiliar para percorrer a lista

    novo = (ptLSE*)malloc(sizeof(ptLSE));

    novo->numero = num;
    ptAux = ptInicio;

    if (ptInicio == NULL)
    {          // Se a lista estiver vazia
        ptInicio = novo;            // novo valor = primeiro elemento da lista
		ptInicio->prox = ptInicio;  // elemento final da lista aponta para o primeiro
		ptInicio->ant = ptInicio;   // elemento anterior ao inicio da lista aponta para o ultimo
	}
    else
    {
        while((ptAux->prox->numero != ptInicio->numero) || (ptAux->numero != num))
        {
            //printf("executou");
            ptAux = ptAux->prox;
        }
    }

    if(ptAux->numero != num)
    { /* SE O NUMERO N�O FOR ENCONTRADO ELE VAI SER INSERIDO NO INICIO DA LISTA */
        //printf("executou");
        ptInicio->ant->prox = novo;      // O �ltimo elemento da lista ter� como seu pr�ximo elemento o novo in�cio
        novo->ant = ptInicio->ant;       // o anterior do novo in�cio ser� o anterior do antigo in�cio da lista
        novo->prox = ptInicio;           // o novo in�cio ter� como sucessor o antigo in�cio
        ptInicio->ant = novo;            // o antigo in�cio ter� como seu antecessor o novo in�cio
        ptInicio = novo;                 // o ptLista apontar� para o novo in�cio
    }
    else
    {
        novo_ant = (ptLSE*)malloc(sizeof(ptLSE));   /* os ponteiros auxiliares s� ir�o */
        novo_prox = (ptLSE*)malloc(sizeof(ptLSE));  /*  ser alocados caso necess�rio   */

        novo_ant = ptAux->prox;
        novo_prox = ptAux->ant;

        novo_prox->prox = ptAux->prox->prox;
        novo_ant->ant = ptAux->ant->ant;
        novo_ant->numero = num+1;
        novo_prox->numero = num - 1;
    }

    return ptInicio;

}
/*****************************************************************/
int ExibeIni(ptLSE* ptInicio)
{
    ptLSE* ptaux;


    if (ptInicio == NULL)
    { //Se o ponteiro do inicio for nulo
        puts("\n\n\t\tO ponteiro que aponta para o inicio da lista esta vazio!!!");
    }
    else
    {
        for (ptaux = ptInicio; ptaux != NULL; ptaux = ptaux->prox)
        { //Percorre a lista do inicio ao fim, at� que o ultimo nodo nao exista
            printf("\nNumero = %d",ptaux->numero);
        }
    }

    return 0;
}
/*******************************************************************/
int ExibeInversoNum(ptLSE* ptInicio, int num)
{
    ptLSE* ptaux;


    if (ptInicio == NULL)
    { //Se o ponteiro do inicio for nulo
        puts("\n\n\t\tO ponteiro que aponta para o inicio da lista esta vazio!!!");
    }
    else
    {
        for (ptaux = ptInicio; ptaux != NULL; ptaux = ptaux->ant)
        { //Percorre a lista do inicio ao fim, at� que o ultimo nodo nao exista
            printf("\nNumero = %d",ptaux->numero);
        }
    }

    return 0;
}
/*******************************************************************/
ptLSE* Destroi(ptLSE* ptInicio)
{ //Desaloca o espaco de memoria correspondente a LCDE
    ptLSE* ptaux;
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
/***********************************************************************/
ptLSE* cria_lista(){ /* CRIA NOVA LISTA VAZIA */
    return NULL;
}
/***********************************************************************/
