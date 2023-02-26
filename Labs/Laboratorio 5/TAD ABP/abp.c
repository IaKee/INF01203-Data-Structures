#include "abp.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

pNodoA* InsereArvore(pNodoA *a, int ch)
{
     if (a == NULL)
     { //Se o nodo for nulo, aloca um espaco de memoria para esse, e coloca os dois filhos como nulo
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info) //Se for menor do que o nodo analisado, percorre pela esquerda até achar um espaço nulo para criar um novo nodo
              a->esq = InsereArvore(a->esq,ch);
          else if (ch > a->info) //Se for maior do que o nodo analisado, percorre pela direita até achar um espaço nulo para criar um novo nodo
              a->dir = InsereArvore(a->dir,ch);
     return a;
}
void preFixado(pNodoA *a)
{
     if (a!= NULL)
     {
          printf("%d\n",a->info);
          preFixado(a->esq);
          preFixado(a->dir);
      }
}
void Central(pNodoA *a)
{
     if (a!= NULL)
     {
          Central(a->esq);
          printf("%d\n",a->info);
          Central(a->dir);
      }
}
void posFixado(pNodoA *a)
{
     if (a!= NULL)
     {
          posFixado(a->esq);
          posFixado(a->dir);
          printf("%d\n",a->info);
      }
}
pNodoA* consultaABP(pNodoA *a, int chave)
{
    while (a!=NULL){
          if (a->info == chave )
             return a; //achou então retorna o ponteiro para o nodo
          else
            if (a->info > chave)
               a = a->esq;
            else
               a = a->dir;
            }
            return NULL; //se não achou
}
pNodoA* consultaABP2(pNodoA *a, int chave)
{
    if (a!=NULL) {


       if (a->info == chave)
         return a;
       else
           if (a->info > chave)
                return consultaABP2(a->esq,chave);
            if (a->info < chave)
                return consultaABP2(a->dir,chave);

            else return a;
       }
       else return NULL;
}
int Altura (pNodoA *a)
{
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
        return 0;
    else
    {
        Alt_Esq = Altura (a->esq);
        Alt_Dir = Altura (a->dir);
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}
int checa_fator_balanceamento(pNodoA *a)
{
    int fator_esq;
    int fator_dir;
    int FB;

    if (a == NULL)
        return 0;

    fator_dir = Altura (a->dir);
    fator_esq = Altura (a->esq);
    FB = fator_esq - fator_dir;
    return FB;
}
int checa_AVL(pNodoA *a, int cod_ant, int FB_ant)
{ //Checa se a arvore recebida por referencia e uma AVL
    if(a == NULL)
        return 0;

    FB_ant = checa_fator_balanceamento(a); //Checa a fator de balanceamento do nodo atual

    if(FB_ant >= 2 || FB_ant <= -2)
        return 77; //Retorna o codigo de erro 77, indicando que a arvore nao e uma AVL

    if(cod_ant == 77)
        return 77; //Codigo de erro que indica que a arvore nao é uma AVL - Se encontrado pelo menos uma vez, encerra recursivamente

    cod_ant = checa_AVL(a->esq, cod_ant, FB_ant); //Repete recursivamente para toda a parte da esuqerda da arvore

    if(cod_ant == 77)
        return 77;

    cod_ant = checa_AVL(a->dir, cod_ant, FB_ant); //Repete recursivamente para toda a parte da direuta da arvore

    if(cod_ant == 77)
        return 77;

    return 0; //Retorna zero, indicando que a arvore em questao é de fato uma AVL
}
