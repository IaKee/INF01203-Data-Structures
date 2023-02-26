#define N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA 46

/*PROTOTIPACAO DAS FUNCOES UTILIZADAS*/

struct NoAVL
{
    char palavra[N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA+1]; //String para armazenar a palavra encontrada no texto, alocada para o pior caso possivel, da maior palavra
    int frequencia; //Repeticoes que a palavra desse no teve ao longo do texto
    int FB; //Fator de balanceamento da arvore AVL
    struct NoAVL *esq;
    struct NoAVL *dir;
}; typedef struct NoAVL avlNode;

struct NoRubroNegra
{
    char palavra[N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA+1];
    int frequencia; //Repeticoes que a palavra desse no teve ao longo do texto
    char cor_no; //Dimi
    struct NoRubroNegra *esq;
    struct NoRubroNegra *dir;
}; typedef struct NoRubroNegra RBNode;




