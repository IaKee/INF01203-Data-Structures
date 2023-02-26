//Tipo de dado para a ABP
struct TNodoA{
        int info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};typedef struct TNodoA pNodoA; //Renomeia "struct TNodoA", para "pNodoA"

//Tipo de dado para a LSE
struct TX
{
    int info;
    struct TX *p1;
}; typedef struct TX TipoLSE; //Renomeia "struct TX", para "TipoLSE"


pNodoA* InsereArvore(pNodoA *a, int ch);
void preFixado(pNodoA *a);
void posFixado(pNodoA *a);
void Central(pNodoA *a);
pNodoA* consultaABP(pNodoA *a, int chave);
pNodoA* consultaABP2(pNodoA *a, int chave);


