#include "abp.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Funcao renomeada - (era OqueSera)
void preencheLSE(pNodoA *a,  TipoLSE **y)
{
    //Insere os valores da Arvore em uma lista simplismente encadeada
    //De forma que a lista comeca a ser preenchida da direita para a esquerda, de baixo para cima (como se fosse decrescente, mas nao é)
    //Recebe como referencia o endereco de memoria de um nodo (pNodoA)
    TipoLSE *p;

    if (a != NULL)
    {
        p = (TipoLSE*) malloc(sizeof(TipoLSE));
        p->info =  a->info;
        p->p1 = *y;
        *y = p;
        preencheLSE(a->esq, y);
        preencheLSE(a->dir, y);
    }
}

int main()
{
    pNodoA *arv = NULL; //Ponteiro para a raiz da arvore binaria de pesquisa - Inicializa como nulo - por nao ter nenhum valor
    pNodoA *procurado = NULL;
    int opcao_menu, dado_ABP, elemento_procura, FB_elemento_procura, aux;

    while(opcao_menu != 0)
    {
        system("cls");
        printf("Digite o que deseja-se que seja feito:\n");
        printf("\t1 - Inserir novos elementos na ABP\n");
        printf("\t2 - Imprimir ABP em ordem crescente\n");
        printf("\t3 - Imprimir ABP em LSE 'decrescente' - Funcao oQueSera\n");
        printf("\t4 - Imprimir ABP da esquerda para a direita\n");
        printf("\t5 - Verificar se a arvore eh AVL\n");
        printf("\t6 - Verificar se a arvore eh Rubro-Negra\n");
        printf("\t7 - Verificar fator de um elemento\n");
        printf("\t0 - Fechar o programa\n");
        printf("\n\tOpcao digitada: ");
        scanf("%d", &opcao_menu);

        switch (opcao_menu)
        {
            case 1:
            system("cls");
            printf("A opcao escolhida foi 1 - (voltara intanteneamente para o menu apos o enter)");
            printf("\n\nInsira um valor inteiro para ser inserido na ABP: ");
            scanf("%d", &dado_ABP);
            arv = InsereArvore(arv, dado_ABP);
            break;

            case 2:
            //Imprime a arvore em ordem crescente, comecando pelo ultimo elemento da esquerda (menor do que o no indicado), e subindo os niveis
            system("cls"); //Limpa a tela antes de imprimir
            printf("Arvore impressa em ordem crescente:\n"); //Linha em branco
            Central(arv);
            printf("\n"); //Espaco em branco
            system("pause");
            break;

            case 3:
            system("cls"); //Limpa a tela antes de imprimir

            //Testando a funcao que imprime a arvore, do menor numero para o maior, de baixo para cima
            TipoLSE *l=NULL, *aux=l;
            preencheLSE(arv,&l);
            if (l==NULL)
                puts("\nA lista simplismente encadeada encontrada eh nula, houve um erro");

            //Imprime a Lista simplismente encadeada
            printf("Lista simplismente encadeada gerada a partir da arvore 'decrescente':\n");
            printf("\n"); //Espaco em branco
            for (aux = l; aux!=NULL; aux=aux->p1)
                printf("%d ",aux->info);
            printf("\n"); //Espaco em branco
            system("pause");
            break;

            case 4:
            //Imprime a arvore, da raiz para as folhas, da esquerda para a direita
            system("cls");
            printf("Arvore impressa da raiz para as folhas, da esquerda para a direita:\n");
            preFixado(arv);
            printf("\n"); //Espaco em branco
            system("pause");
            break;

            case 5:
            system("cls");
            printf("A arvore em questao ");
            aux = checa_AVL(arv);
            if(aux == 77)
            {
                printf("nao eh uma AVL.\n");
            }
            else
            {
                printf("eh uma AVL!\n");
            }
            system("pause");
            break;

            case 6:
            break;

            case 7:
            system("cls");
            printf("Digite um elemento da ABP para testar o fator de balanceamento:\n");
            printf("\nElemento a ser procurado: ");
            //O fator de balanceamento é a diferenca de altura entre cada nodo
            scanf("%d", &elemento_procura);

            procurado = NULL; //Reseta o endereco de memoria apontado por "procurado" para que esse seja nulo
            procurado = consultaABP(arv, elemento_procura);

            if(procurado != NULL) //Se continuar nulo
                {
                    FB_elemento_procura = checa_fator_balanceamento(procurado);
                    printf("\n\nO FB do nodo indicado eh: %d\n\n", FB_elemento_procura);
                }
            else
                printf("\nElemento invalido! Cheque a digitacao e tente novamente!\n\n");

            system("pause");
            break;

            case 0:
            break;

            default:
            system("cls");
            printf("O valor digitado anteriormente foi invalido, tente novamente...\n\n");
            system("pause");
        }

    }
    printf("\nPrograma terminado!\n\n");
    system("pause");
    return 12345678;
}
