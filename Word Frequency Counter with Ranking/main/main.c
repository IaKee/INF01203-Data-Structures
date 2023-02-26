//Projeto: Contador de frequência de palavras em um texto - Trabalho Final de estrutura de dados
//Autores (Cartao UFRGS): Giordano Souza de Paula (00308054) e Sabryna Trindade (00302133)

/*OBSERVACOES SOBRE O PROJETO*/
//-A tamanho da maior palavra utilizada no no da arvore tem 46 caracteres, sendo a maior palavra possivel da lingua portuguesa
//-O maior tamanho de arquivo possivel considerado foi de 250 caracteres
//-Mesmo com o usuario nao digitando a terminacao .txt dos arquivos, esse final é adicionado a string de forma automática

/**************************************************ANOTACOES***************************/
//-String[n_palavra][n_letras];
/**************************************************ANOTACOES***************************/

/*BIBLIOTECAS UTILIZADAS*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h> //Para ter a variavel boolean, que só pode assumir os estados de true ou false
#include <ctype.h> //Para tratamento de texto, maiusculas, minusculas, etc
#include <time.h> //Para estatisticas do tempo de execucao do programa
#include <windows.h>
#include <time.h>

/*CONSTANTES DEFINIDAS*/
#define TAM_MAX_CAMINHO 250
#define N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA 46

/********************************************************************STRUCTS UTILIZADAS******************************************************/
/*PROTOTIPACAO DAS FUNCOES UTILIZADAS*/
struct NoAVL
{ //Tipo de dado criado para armazenar um nó da arvore AVL (avlNode)
    char palavra[N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA+1]; //String para armazenar a palavra encontrada no texto, alocada para o pior caso possivel, da maior palavra
    int frequencia; //Repeticoes que a palavra desse no teve ao longo do texto
    int FB; //Fator de balanceamento da arvore AVL
    struct NoAVL *esq;
    struct NoAVL *dir;
}; typedef struct NoAVL avlNode;
struct NoRubroNegra
{ //Tipo de dado criado para armazenar um nó da arvore rubro-nebra (RBNode)
    char palavra[N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA+1];
    int frequencia; //Repeticoes que a palavra desse no teve ao longo do texto
    char cor_no; //Dimi
    struct NoRubroNegra *esq;
    struct NoRubroNegra *dir;
}; typedef struct NoRubroNegra RBNode;
/*************************************************************************FUNCOES************************************************************/
void imprime_apresentacao()
{ //Imprime o nome do trabalho com o nome dos integrantes
    printf("\t\t    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL\n");
    printf("\t\t\t INF01203 - Estruturas de Dados");
    printf("\n\t\t\t    Engenharia de Computacao\n");
    printf("\n\t\t\t\t  PROFESSORA:");
    printf("\n\t\t\t\tRenata Galante\n");
    printf("\n\t\t\t\t    ALUNOS:");
    printf("\n\t\t\t   Giordano Souza   308054\n");
    printf("\t\t\t   Sabryna Trindade 302133\n\n");
    printf("\n\n\t\t\t\tTrabalho Final\n");
    printf("\t\t Programa: Contador de Frequencias de Palavras\n\n\n\n\n\n\n\n\n");
}
int abre_arquivo(FILE **arquivo, char *path, char *open_mode)
{
    *arquivo = fopen(path, open_mode);

    if (arquivo == NULL)
        return 1;

    return 0;

}
int frequencia(char* palavra)
{
    int numero_repeticoes = 0;
    return numero_repeticoes;
}
void contador(int k1, int k2)
{ //Imprime as palavras que tem n>=k1 e n<=k2 em numero crescente de frequencia de ocorrencia, e se ambas possuirem a mesma frequencia, a ordem deve ser alfabetica

}
int compara_palavras(char palavra1[], char palavra2[])
{//Compara duas palavras, indicando 0, 1, 2 ou 404, de acordo com o resultado da comparacao
    int flag, comp;

    if(strlen(palavra1) == 0 || strlen(palavra2) == 0)
    { //Se alguma das palavras for nula (0 caracteres, retorna 404 como código de erro
        return 404;
    }

    comp = strcmp(palavra1,palavra2);

    if(comp == 0)
    {  //Retorna 0 caso as duas palavras sejam iguais
        flag = 2;
    }
    else if(comp > 0)
    { //Se a palavra2 for maior ou vier depois que a palavra1
        flag = 0;
    }
    else
    { //Se a palavra palavra1 for maior ou vier depois que a palavra2
        flag = 1;
    }

    return flag;
}
avlNode* insertAVLnode(avlNode* nodo, char *palavra)
{ //Recebe um nó ou raiz para inserir e uma palavra para inserir

    if (nodo == NULL)
    { //Se o nó indicado for vazio - significa que é a raiz da arvore - aloca um nodo e armazena a palavra indicada

        nodo = (avlNode*) malloc(sizeof(avlNode)); //Aloca um espaco de memoria para armazenar o no
        strcpy(nodo->palavra, palavra); //Armazena a string (palavra) indicada dentro da string alocada na struct
        nodo->frequencia = 1; //Inicializa o contador de frequencia da palavra como 1 (o minimo de ocorrencias é 1)
        nodo->esq = NULL; //Aponta para um endereço nulo a esquerda
        nodo->dir = NULL; //Aponta para um endereço nulo a direita
        nodo->FB = 0; //O nodo inserido é a raiz, entao seu fator de balanceamento é zero
    }
    else
        if(compara_palavras(palavra, nodo->palavra) == 0) //Se a palavra indicada vier primeiro (alfabetico) que a palavra do nodo atual
            nodo->esq = insertAVLnode(nodo->esq, palavra);
        else
            nodo->dir = insertAVLnode(nodo->dir, palavra);
    return nodo;
}
int checa_altura_AVL(avlNode *a)
{//Verifica a altura de determinado nó na arvore AVL que foi recebido por referencia
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
      return 0;
    else
    {
       Alt_Esq = checa_altura_AVL(a->esq);
       Alt_Dir = checa_altura_AVL(a->dir);
       if (Alt_Esq > Alt_Dir)
         return (1 + Alt_Esq);
       else
         return (1 + Alt_Dir);
     }
}
int calcula_FB(avlNode *a)
{ //Funcao que calcula o fator de balanceamento da arvore avl, comparando a altura dos dois galhos filhos de um nó AVL
    return (checa_altura_AVL(a->esq) - checa_altura_AVL(a->dir));
}
void move_cursor(int x, int y)
{ //Funcao que move o cursor na tela para a posicao (x, y) enviada por referencia - útil para organizacao de intereface
    COORD pos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, pos);
}
void apaga_caracteres(int x, int y, int quantidade)
{ //Apaga uma definida quantidade de caracteres a partir de definida posicao do display - útil para a organizacao de interface
    move_cursor(x, y); //Move o cursor para a posicao que foi definida
    for(int aux = 0; aux< quantidade; aux++) //Imprime a quantidade de espacos que foi definida na chamada da funcao
        printf(" ");
}
int intro_arquivo_saida_avl(FILE **arquivo_saida, avlNode* root, int tot_nodes_avl, int comparacoes_antes, clock_t tempo_avl_antes, int rotacoes_avl)
{ //Preenche o arquivo de saida com todos os dados que foram obtidos ao decorrer do programa
    fprintf (*arquivo_saida, "**********ESTATÍSTICAS DA GERAÇÃO DA ÁRVORE AVL *************\n");
    fprintf (*arquivo_saida, "Numero de nodos: %d\n", tot_nodes_avl);
    //fprintf (*arquivo_saida, "Altura: %d\n", checa_altura_AVL(root)); //Imprime a altura maxima da arvore (raiz) - APAGAR ISSO
    //fprintf (*arquivo_saida, "Fator de Balanceamento: %d\n", calcula_FB(root)); //Calcula o fator de balanceamento da raiz da arvore e o imprime

    double Tempo = ((clock() - tempo_avl_antes) * 1000.0) / CLOCKS_PER_SEC; //Calcula o tempo atual em milissegundos

    fprintf (*arquivo_saida, "O tempo de execucao nesse ponto eh de %gms (milissegundos).\n", Tempo);
    fprintf (*arquivo_saida, "Foram realizadas %d rotacoes com esse metodo.\n", rotacoes_avl);
    fprintf (*arquivo_saida, "Ate esse ponto foram realizadas %d comparacoes.\n", comparacoes_antes); //Comparacoes que foram realizadas durante o processo utilizando AVL
    fprintf (*arquivo_saida, "*************************************************************\n");
    return 0;
}
int checa_operacoes(FILE *arquivo_opera, char *operacao_F[], char *operacao_C[])
{
    int quantidade_F = 0;
    int quantidade_C = 0;
    char opera_lida;
    while(!feof(arquivo_opera))
    {
        fscanf(arquivo_opera, "%c", &opera_lida); //Le a operacao indicada (primeiro elemento)

        if(opera_lida == 'F')
        {
            fseek (arquivo_opera, sizeof(char), SEEK_CUR); //Pula um char (existe um espaco em branco entre a letra que indica a operacao e a palavra a ser operada)

            //Insere o primeiro e o segundo caractere da string como um F e um espaco em branco (quantidade_F) é para ser o numero da palavra na string
            operacao_F[quantidade_F][0] = 'F';
            operacao_F[quantidade_F][1] = ' ';


            fgets(operacao_F[quantidade_F], (N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA*sizeof(char)), arquivo_opera); //Essa funcao para ao encontrar um \n no arquivo texto

            quantidade_F++;
        }
        if(opera_lida == 'C')
        {

        }
    }


    return 0;
}
void error_texto()
{
    system("cls");
    printf("Ocorreu um erro ao abrir o arquivo com o texto!!\n");
    printf("Fechando programa! Cheque se nao existe alguma configuracao bloqueando permissoes...");
}
void error_opera()
{
    system("cls");
    printf("Ocorreu um erro ao abrir o arquivo com as operacoes!!\n");
    printf("Fechando programa! Cheque se nao existe alguma configuracao bloqueando permissoes...");
}
void error_saida()
{
    system("cls");
    printf("Ocorreu um erro ao criar um arquivo texto para a saida dos dados!!\n");
    printf("Fechando programa! Cheque se nao existe alguma configuracao bloqueando permissoes...");
}
void imprime_encerramento(double t_ini)
{ //Limpa a tela e imprime mensagem de encerramento
    clock_t t_final = clock();
    double tot = t_final - t_ini;

    system("cls");
    printf("Os arquivos texto abertos anteriormente foram fechados!\n");
    printf("O tempo total gasto no programa foi de %g milissegundos.", tot);
    system("pause");
}
/*******************************************************************PROGRAMA PRINCIPAL*******************************************************/
int main(char caminho_texto[TAM_MAX_CAMINHO], char caminho_opera[TAM_MAX_CAMINHO], char caminho_saida[TAM_MAX_CAMINHO])
{
    //Arquivos texto
    FILE *arquivo_texto = NULL; //Arquivo com o texto que sera lido e operado sobre
    FILE *arquivo_opera = NULL; //Arquivo que define que operacoes serao relizadas sobre o programa
    FILE *arquivo_saida = NULL; //Arquivo de saida, com o relatorio de execucao do programa

    //Ticks do relogio
    clock_t inicio_programa = clock();
    clock_t fim_programa;
    clock_t inicio_AVL;
    clock_t fim_AVL;
    clock_t inicio_RB;
    clock_t fim_RB;

    //Comparacoes
    int comparacoes_AVL = 0;
    int comparacoes_RB = 0;
    int rotacoes_AVL = 0;
    int rotacoes_RB = 0;
    int mudacor_RB = 0;

    //No AVL teste
    avlNode *teste;

    //Imprime a apresentacao no inicio do programa, esperando o usuariario digitar alguma coisa
    imprime_apresentacao();
    system("pause");
    system("cls");

    if(abre_arquivo(&arquivo_texto, caminho_texto, "r"))
    {
        error_texto();
        return 404;
    }
    if(abre_arquivo(&arquivo_opera, caminho_opera, "r"))
    {
        error_opera();
        return 404;
    }
    if(abre_arquivo(&arquivo_saida, caminho_saida, "wt"))
    {
        error_saida();
        return 404;
    }

    intro_arquivo_saida_avl(&arquivo_saida, teste, 6, 6, inicio_programa, 6);

    //Salva os aquivos texto e encerra o programa
    fclose(arquivo_texto);
    fclose(arquivo_opera);
    fclose(arquivo_saida);

    imprime_encerramento(inicio_programa);
    return 0;
}
