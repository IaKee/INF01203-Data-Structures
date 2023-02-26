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
#include <ctype.h> //Para tratamento de texto, maiusculas, minusculas, etc
#include <time.h> //Para estatisticas do tempo de execucao do programa
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

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
    int red; //Dimi
    struct NoRubroNegra *esq;
    struct NoRubroNegra *dir;
    struct NoRubroNegra *pai;
}; typedef struct NoRubroNegra RBNode;
static RBNode* NodoNULL = NULL;
/*************************************************************************FUNCOES************************************************************/
void teste_passou()
{
    printf("\n\n\n\nPassou por aqui!\n\n\n");
    system("pause");

}
void imprime_apresentacao()
{
    system("cls");
    printf("\t\t    UNIVERSIDADE FEDEREL DO RIO GRANDE DO SUL\n");
    printf("\t\t\t INF01203 - Estruturas de Dados");
    printf("\n\t\t\t    Engenharia de Computação\n");
    printf("\n\t\t\t\t  PROFESSORA:");
    printf("\n\t\t\t\tRenata Galante\n");
    printf("\n\t\t\t\t    ALUNOS:");
    printf("\n\t\t\t   Giordano Souza   308054\n");
    printf("\t\t\t   Sabryna Trindade 302133\n\n");
    printf("\n\n\t\t\t\tTrabalho Final\n");
    printf("\t\t Programa: Contador de Frequência de Palavras\n\n\n\n\n\n\n\n\n");
}
void imprime_encerramento()
{
    //system("cls");
    printf("\n\n\nEncerrando programa...\n");
    printf("Fechando arquivos!\n\n\n\n\n");
}
int abre_arquivo(FILE **arquivo, char *path, char *open_mode)
{
    *arquivo = fopen(path, open_mode);

    if (arquivo == NULL)
        return 1;

    return 0;

}
int contador (FILE* arquivo, avlNode *arvore, int k1, int k2)
{ //Imprime as palavras que tem n>=k1 e n<=k2 em numero crescente de frequencia de ocorrencia, e se ambas possuirem a mesma frequencia, a ordem deve ser alfabetica

    if(arvore == NULL)
        return 0;

    for(int a=k2; a>=k1; a--)
    {
        //printf("\nNumero atual a: %d");
        if(arvore->frequencia == a)
        {
            fprintf (arquivo, "%s %d\n", arvore->palavra, arvore->frequencia);
        }
        contador(arquivo, arvore->esq, a, a);
        contador(arquivo, arvore->dir, a, a);
    }
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
    {  //Retorna 2 caso as duas palavras sejam iguais
        flag = 2;
    }
    else if(comp > 0)
    { //Se a palavra2 for maior ou vier depois que a palavra1 (palavra 2 vem depois que a palavra 1)
        flag = 0;
    }
    else
    { //Se a palavra palavra1 for maior ou vier depois que a palavra2 (palavra2 vem antes que a palavra1)
        flag = 1;
    }

    return flag;
}
avlNode* rotacao_direita(avlNode *pt, int *num_avl, int *compara_avl, int *rota_avl) /**************************************VER ISSO!!!!!*****************************************/
{
    //Aloca um ponteiro auxiliar para a rotacao
    avlNode* ptu;

    *rota_avl += 1;

    ptu = pt->esq;
    pt->esq = ptu->dir;
    ptu->dir = pt;
    pt->FB = 0;
    pt = ptu;

    return pt;
}
avlNode* rotacao_esquerda(avlNode *pt, int *num_avl, int *compara_avl, int *rota_avl) /**************************************VER ISSO!!!!!*****************************************/
{
    //Aloca um ponteiro auxiliar para a rotacao
    avlNode* ptu;

    *rota_avl += 1;

    ptu = pt->dir;
    pt->dir = ptu->esq;
    ptu->esq = pt;
    pt->FB = 0;
    pt = ptu;

    return pt;
}
avlNode* rotacao_dupla_esquerda (avlNode* root, int *num_avl, int *compara_avl, int *rota_avl) /**************************************VER ISSO!!!!!*****mas acho que ta certo************************************/
{
    //Aloca dois ponteiros auxiliares para a rotacao
    avlNode *ptu;
    avlNode *ptv;

    *rota_avl += 1;

    ptu = root->dir;
    ptv = ptu->esq;

    ptu->esq = ptv->dir;
    ptv->dir = ptu;

    root->dir = ptv->esq;
    ptv->esq = root;

    if (ptv->FB == -1)
        root->FB = 1;
    else
        root->FB = 0;

    if (ptv->FB == 1)
        ptu->FB = -1;
    else
        ptu->FB = 0;

   root = ptv;

   return root;
}
avlNode* rotacao_dupla_direita (avlNode* pt, int *num_avl, int *compara_avl, int *rota_avl) /**************************************VER ISSO!!!!!***mas acho que ta certo**************************************/
{ //Rotacao dupla direita para arvores AVL (importada de um exemplo)
    //Aloca dois ponteiros auxiliares para a rotacao
    avlNode *ptu;
    avlNode *ptv;

    *rota_avl += 1;

    ptu = pt->esq;
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    pt->esq = ptv->dir;
    ptv->dir = pt;

    if (ptv->FB == 1)
        pt->FB = -1;
    else
        pt->FB = 0;

    if (ptv->FB == -1)
        ptu->FB = 1;
    else
        ptu->FB = 0;

   pt = ptv;

   return pt;
}
avlNode* Caso1 (avlNode* root, int *ok, int *num_avl, int *compara_avl, int *rota_avl) /**************************************VER ISSO!!!!!*****mas acho que funciona****************************************/
{
   avlNode *ptu;

	ptu = root->esq;
	if (ptu->FB == 1)
    {
        printf("Fazendo rotacao direita na palavra %s.\n", root->palavra);
        root = rotacao_direita(root, num_avl, compara_avl, rota_avl);
     }
    else
    {
        printf("Fazendo rotacao dupla direita na palavra %s.\n", root->palavra);
        root = rotacao_dupla_direita(root, num_avl, compara_avl, rota_avl);
    }

    root->FB = 0;
	*ok = 0;
	return root;
}
avlNode* Caso2 (avlNode *root, int *ok, int *num_avl, int *compara_avl, int *rota_avl) /**************************************VER ISSO!!!!!*****mas acho que funciona************************************/
{
    avlNode *ptu;

	ptu = root->dir;
	if (ptu->FB == -1)
    {
       printf("Fazendo rotacao esquerda na palavra %s.\n", root->palavra);
       root = rotacao_esquerda(root, num_avl, compara_avl, rota_avl);
    }
    else
    {
       printf("Fazendo rotacao dupla esquerda na palavra %s.\n", root->palavra);
       root = rotacao_dupla_esquerda(root, num_avl, compara_avl, rota_avl);
    }
	root->FB = 0;
	*ok = 0;
	return root;
}
int checa_altura_AVL(avlNode *a) /**************************************VER ISSO!!!!!*****************************************/
{//Verifica a altura de determinado nó na arvore AVL que foi recebido por referencia
    int Alt_Esq, Alt_Dir;

    if (a == NULL)
        return 0; //Se o no indicado for nulo, retorna zero
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
int checa_AVL(avlNode *a) /**************************************VER ISSO!!!!!*****************************************/
{ //Retorna se a arvore é uma AVL ou nao
    int alt_esq, alt_dir;

    if (a != NULL)
    {
        teste_passou();
        alt_esq = checa_altura_AVL(a->esq);
        alt_dir = checa_altura_AVL(a->dir);

        return ((alt_esq - alt_dir <2) && (alt_dir - alt_esq <2) && (checa_AVL(a->esq)) && (checa_AVL(a->dir)));
    }
    else
        return 1;
}
avlNode* insertAVL(avlNode *root, char *palavra, int *ok, int *num_avl, int *compara_AVL, int *rota_avl) /**************************************VER ISSO!!!!!*****(isso provavelmente ta ok...)************************************/
{ //Insere um no na arvore AVL, onde root é a raiz da arvore, e a palavra é uma palavra obtida do texto

    *compara_AVL += 1;
    if (root == NULL)
    { //Se o no indicado for nulo, aloca um nodo na memoria, que vira uma nova raiz
        root = (avlNode*) malloc(sizeof(avlNode));
        strcpy(root->palavra, palavra);
        root->esq = NULL;
        root->dir = NULL;
        root->FB = 0;
        root->frequencia = 1;
	    *ok = 1;
	    *num_avl += 1; //Incrementa o numero total de nodos da arvore
    }
    else
    {
        *compara_AVL += 1;
        if (compara_palavras(root->palavra, palavra) == 1) //Se a palavra indicada vier antes da palavra do nodo
        { //Se a palavra indicada deve ir a ESQUERDA

            root->esq = insertAVL(root->esq, palavra, ok, num_avl, compara_AVL, rota_avl);
            *compara_AVL += 1;
            if (*ok)
            {
                *compara_AVL += 1;
                switch (root->FB)
                {
                    case -1:    root->FB = 0;
                                *ok = 0;
                                break;

                    case  0:    root->FB = 1;
                                break;

                    case  1:    root = Caso1(root, ok, num_avl, compara_AVL, rota_avl);
                                break;
                }
            }
        }
        else
        {
            *compara_AVL += 1;
            if (compara_palavras(root->palavra, palavra) == 0)
            { //Se a palavra indicada deve ir a DIREITA
                root->dir = insertAVL(root->dir, palavra, ok, num_avl, compara_AVL, rota_avl);
                *compara_AVL += 1;
                if (*ok)
                {
                    switch (root->FB)
                    {
                        case  1:    root->FB = 0;
                                    *ok = 0;
                                    break;

                        case  0:    root->FB = -1;
                                    break;

                        case -1:    root = Caso2(root, ok, num_avl, compara_AVL, rota_avl);
                                    break;
                    }
                }
            }
            else
            {
                *compara_AVL += 1;
                if (compara_palavras(root->palavra, palavra) == 2)
                { //Caso a palavra indicada seja igual a palavra encontrada na arvore
                    root->frequencia += 1; //Incrementa
                }
            }
        }
    }

    return root;
}
int calcula_FB(avlNode *a)
{ //Funcao que calcula o fator de balanceamento da arvore avl, comparando a altura dos dois galhos filhos de um nó AVL
    if(a != NULL)
        return (checa_altura_AVL(a->esq) - checa_altura_AVL(a->dir));
    else
        return 0;
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
int intro_arquivo_saida_avl(FILE **arquivo_saida, avlNode *aux, int tot_nodes_avl, int comparacoes_antes, clock_t tempo_avl_antes, int rotacoes_avl)
{ //Preenche o arquivo de saida com todos os dados que foram obtidos ao decorrer do programa

    fprintf (*arquivo_saida, "**********ESTATÍSTICAS DA GERAÇÃO DA ÁRVORE AVL *************\n");
    fprintf (*arquivo_saida, "Número de nodos: %d\n", tot_nodes_avl);

    //Calcula e imprime a altura da arvore
    int alturaAVL = checa_altura_AVL(&*aux);
    if(alturaAVL != -1)
        fprintf (*arquivo_saida, "Altura: %d\n", alturaAVL); //Imprime a altura maxima da arvore (raiz) - APAGAR ISSO
    else
        fprintf (*arquivo_saida, "Ocorreu um erro ao calcular a altura da árvore a partir da raiz dessa!!!\n");

    //Calcula e imprime o FB
    int fator_balanceamento = calcula_FB(&*aux);
    if (fator_balanceamento != -1)
        fprintf (*arquivo_saida, "Fator de Balanceamento: %d\n", fator_balanceamento); //Calcula o fator de balanceamento da raiz da arvore e o imprime
    else
        fprintf(*arquivo_saida, "Ocorreu um erro ao calcular o fator de balanceamento da árvore a partir da raiz dessa!!!\n");

    //Calcula e imprime o tempo (antes da execucao)
    double Tempo = ((clock() - tempo_avl_antes) * 1000.0) / CLOCKS_PER_SEC; //Calcula o tempo atual em milissegundos
    fprintf (*arquivo_saida, "O tempo de execução nesse ponto é de %gms (milissegundos).\n", Tempo);

    fprintf (*arquivo_saida, "Foram realizadas %d rotações com esse método.\n", rotacoes_avl);
    fprintf (*arquivo_saida, "Até esse ponto foram realizadas %d comparações.\n", comparacoes_antes); //Comparacoes que foram realizadas durante o processo utilizando AVL
    fprintf (*arquivo_saida, "*************************************************************");
    return 0;
}
int checa_linhas(FILE **arquivo)
{ //Retorna a quantidade de linhas encontradas em um arquivo
    char caractere_lido;
    int numero_linhas = 0;

    fseek(*arquivo, 0, SEEK_SET); //Move o cursor para a primeira posicao do arquivo texto

    for (caractere_lido = getc(*arquivo); caractere_lido != EOF; caractere_lido = getc(*arquivo)) //Le caracteres ate chegar no final do arquivo
    {
        if (caractere_lido == '\n')
        {
            numero_linhas += 1;
        }
    }

    numero_linhas++; //Talvez uma das linhas nao tenha um \n...

    fseek(*arquivo, 0, SEEK_SET); //Move o cursor para a primeira posicao do arquivo texto

    return numero_linhas;
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
void Desenha(avlNode *a , int nivel)
{ //Imprime um rascunho da arvore AVL
    int x;
    if (a !=NULL)
    {
        for (x=1; x<=nivel; x++)
            printf("=");

        printf("%s(%d) FB= %d\n", a->palavra, a->frequencia, calcula_FB(a));

        if (a->esq != NULL)
            Desenha(a->esq, (nivel+1));
        if (a->dir != NULL)
            Desenha(a->dir, (nivel+1));
    }
}
int get_operacao (FILE **arquivo_opera, int aux1, int aux2, int aux3, char matrizF[aux3][aux1], char matrizC[aux3][aux2], int *noperaF, int *noperaC)
{ //Le o arquivo de operacoes, inserindo na matriz somente a parte util de cada linha (PRECISA QUE COMPILADOR SEJA COMPATIVEL COM C99!!!!!!!!!!!!!!!!!!!!!!

    /*PEGA OS DADOS ASSIM Ó
    matrizF ...
        lua
        a
        bola

    matrizC ...
        2 10*/

    //fseek(*arquivo_opera, sizeof(char), SEEK_CUR); //Pula os dois primeiros caracteres de cada linha

    int caractere_n = 0;
    int palavra_F_n = 1;
    int palavra_C_n = 0;

    char clido = 'x'; //Char lido, o inicializa como x (o programa nao vai considerar esse caractere)
    char string[100001];

    rewind(*arquivo_opera);

    printf("\n");

    while(!feof(*arquivo_opera))
    { //Até encontrar o final do arquivo...

        fgets(string, 100000, *arquivo_opera);

        if(string[0] == 'F')
        {
            *noperaF += 1;
            strcpy(matrizF[palavra_F_n], string);
            strcat(matrizC[palavra_F_n], "");
            //printf("\nA palavra inserida eh %s", matrizF[palavra_F_n]);
            palavra_F_n += 1;
        }
        else
            if(string[0] == 'C')
            {
                *noperaC += 1;
                for(int p = 2; p<aux1+3; p++)
                {
                    matrizC[palavra_C_n][p-2] = string[p];
                }
                palavra_F_n += 1;
            }
    }
    return 0;
}
int le_texto_avl (FILE **arquivo_texto, avlNode **raiz, int maiorpalavra, int *ok, int *num_avl, int *compara_AVL, int *rota_avl)
{ //Recebe o arquivo texto a raiz da arvore, e vai inserindo as palavras

    //Variaveis dessa funcao
    int index_palavra = 0;
    char comparador;
    char *word;
    char separador[]= {" ,.&*%\?!;/-'@\"$#=><()][}{:\n\t"};
    char linha[100001]; //O maior tamanho de linha possivel, sempre

    printf("\n");

    while (!feof(*arquivo_texto))
    {
        fgets(linha, 100000, *arquivo_texto);
        word = strtok (linha, separador); //Consideral qualquer caractere indicado na string separador como um separador de palavras

        while (word != NULL)
        {
            //printf("Palavra a ser inserida: '%s'. \n", strlwr(word));
            //printf("\n");
            word = strtok (NULL, separador);

            if(word != NULL) //Verifica se chegou no fim da linha (/n) no buffer, se estiver, ignora essa operacao
                *raiz = insertAVL(*raiz, strlwr(word), ok, num_avl, compara_AVL, rota_avl);
        }
     }
     return 0;

}
int frequencia(char* palavra, avlNode *raiz)
{
    int flag = 0;


    if(raiz == NULL)
    {
        return 0;
    }

    int direcao = compara_palavras(palavra, raiz->palavra);

    if(direcao == 2)
    { //Se a palavra atual for igual a palavra indicada
        flag = raiz->frequencia;
        return flag;
    }
    else
    { //Se a palavra indicada estiver a direita do nó indicado
        if(direcao == 1)
        {
            flag = frequencia(palavra, raiz->dir);
            if(flag > 0)
                return flag;
        }
        else
        {
            if(direcao == 0)
            { //Se a palavra indicada estiver a esquerda do nó indicado
                flag = frequencia(palavra, raiz->esq);
                if(flag > 0)
                    return flag;
            }
        }

    }
    return 0;
}
int fim_arquivo_saida_AVL(FILE **arquivo_saida, avlNode *aux, int tot_nodes_avl, int comparacoes, clock_t t_antes, clock_t *tempo_avl_depois, int rotacoes_avl, int operaF, int operaC,
                        int aux1, int aux2, int aux3, char matrizF[aux3][aux1], char matrizC[aux3][aux2])
{
    int iaaa = 0; //Indice da string F
    int b = 0;
    int numba = 0;
    char stringcomp[90];
    char tratada[90];

    //A OPERACAO DA MATRIZ F COMEÇA NA matrizF[1]!!!
    fprintf (*arquivo_saida, "\n");
    for (int cr = 1; cr < (operaF+1); cr++)
    {
        fprintf (*arquivo_saida, "%s", matrizF[cr]);
        iaaa = strlen(matrizF[cr]);

        while(matrizF[cr][b+2] != '\0')
        {
            if(matrizF[cr][b+2] != '\0' || matrizF[cr][b+2] != '\n')
            {
                fprintf (*arquivo_saida, "%c", matrizF[cr][b+2]);
                stringcomp[b] = matrizF[cr][b+2];
            }


            b++;
        }
        fseek(*arquivo_saida, -2*sizeof(char), SEEK_CUR);
        stringcomp[b-1] = '\0';

        sprintf(tratada, "%s", stringcomp);

        numba = frequencia(tratada, aux);
        fprintf (*arquivo_saida, " %d ocorrências\n**************************\n", numba);
        iaaa = 0; //Reseta
        b = 0;

    }
    //Intervalo definido por c
    int num1 = 0;
    int num2 = 0;
    char numero[100];
    char other[100];
    int indf = 0;
    int indg = 0;

    for(int qr=0; qr<operaC; qr++)
    {
        fprintf (*arquivo_saida, "C %s", matrizC[qr]);
        while(matrizC[qr][indf] != ' ' && matrizC[qr][indf] != '\0' && matrizC[qr][indf] != '\n')
        {
            numero[indf] = matrizC[qr][indf];
            indf++;
        }
        numero[indf+1] = '\0';
        num1 = atoi(numero);
        //printf("\n\n\nO numero 1 eh: %d", num1);
        indf++;
        while(matrizC[qr][indf] != ' ' && matrizC[qr][indf] != '\0' && matrizC[qr][indf] != '\n')
        {
            other[indg] = matrizC[qr][indf];
            indf++;
            indg++;
        }
        other[indg+1] = '\0';
        num2 = atoi(other);
        //printf("\n\n\nO numero 2 eh: %d", num2);
    }
    fprintf (*arquivo_saida, "\n");
    contador(*arquivo_saida, aux, num1, num2); //Imprime a operacao C

    //Imprime dados de geracao da arvore avl
    double Tempo = ((clock()-t_antes) * 1000.0) / CLOCKS_PER_SEC; //Calcula o tempo atual em milissegundos
    fprintf (*arquivo_saida, "\nTempo gasto no processo com a arvore AVL: %gms.\n", Tempo);
    fprintf (*arquivo_saida, "Comparacoes relizadas com a arvore AVL: %d.\n\n", comparacoes);

    return 0;

}
int ContaNodos(avlNode *root)
{
    if(root)
        return 1 + ContaNodos(root->esq) + ContaNodos(root->dir);
    else
        return 0;
}
int intro_arquivo_saida_rb(FILE **arquivo_saida, RBNode *aux, int tot_nodes_rb, int comparacoes_antes, clock_t tempo_rb_antes, int rotacoes_rb)
{ //Preenche o arquivo de saida com todos os dados que foram obtidos ao decorrer do programa

    fprintf (*arquivo_saida, "********** ESTATÍSTICAS DA GERAÇÃO DA ÁRVORE RUBRO-NEGRA *************\n");
    fprintf (*arquivo_saida, "antes dos nós serem inseridos na árvore\n");
    fprintf (*arquivo_saida, "Número de nodos: 0\n");

    fprintf (*arquivo_saida, "Altura: 0\n"); //Imprime a altura maxima da arvore (raiz) - APAGAR ISSO


    fprintf (*arquivo_saida, "Fator de Balanceamento: 0\n");

    double Tempo = (clock() * 1000.0) / CLOCKS_PER_SEC; //Calcula o tempo atual em milissegundos
    fprintf (*arquivo_saida, "O tempo de execução nesse ponto é de %gms (milissegundos).\n", Tempo);

    fprintf (*arquivo_saida, "Foram realizadas %0 rotações com esse método.\n");
    fprintf (*arquivo_saida, "Até esse ponto foram realizadas %0 comparações.\n"); //Comparacoes que foram realizadas durante o processo utilizando AVL
    fprintf (*arquivo_saida, "*************************************************************");
    return 0;
}
void DesenhaRB(RBNode* t , int nivel)
{
    int x;

    if (t !=NodoNULL)
    {
        for (x=1; x<=nivel; x++)
            printf("=");
        if(t->red)
            printf("%s Red\n", t->palavra);
        else
            printf("%s Black\n", t->palavra);
        if (t->esq != NodoNULL)
            DesenhaRB(t->esq, (nivel+1));
        if (t->dir != NodoNULL)
            DesenhaRB(t->dir, (nivel+1));
 }
 else printf("Arvore Vazia\n");
}
RBNode* Maior(RBNode* t)
{
    while (t != NodoNULL)
        t = t->dir;
    return t->pai;
}
RBNode* Menor(RBNode* t)
{
    while (t != NodoNULL)
        t = t->esq;
    return t->pai;
}
RBNode* RotacaoSimplesEsq(RBNode* t)
{
    RBNode* aux;

    aux = t->dir;
    t->dir = aux->esq;
    aux->esq = t;

    return aux;   /* nova raiz */
}
RBNode* RotacaoSimplesDir(RBNode* t)
{
    RBNode* aux;

    aux = t->esq;
    t->esq = aux->dir;
    aux->dir = t;

    return aux;  /* nova raiz */
}
RBNode* VerificaRN(RBNode* t, char *palavra)
{
    RBNode* x = t;
    RBNode* p = x->pai;
    RBNode* v = p->pai;

    while(compara_palavras(x->palavra, palavra) != 2)  /* desce na árvore */
    {
        v = p; p = x;
        if(compara_palavras(x->palavra, palavra) == 1) //Se for menor
            x = x->esq;
        else //Se for maior
            x = x->dir;
    }
    // x contêm o novo e p o pai do novo.

  /* if(p->red == 0) - caso 1
     insere vermelho mas já tá então não precisa modificar.
  */
  // caso 2
    if(p->red)
    {
        if( v != NodoNULL) // pai não é raiz
        {
            if(compara_palavras(p->palavra, v->palavra) == 0) // p é filho a esquerda - o da
            {
                // Caso 2.1
                if(v->dir->red) // tio é vermelho
                {
                    v->dir->red =0; // tio vira preto
                    if(p->red)
                        p->red = 0; // troca a cor do pai
                    else
                        p->red = 1;

                    if(v->pai == NodoNULL) // avô é raiz
                    {
                        p->dir->red = 0;
                        p->red = 0;
                        v->red = 0;
                    }
                }
                else
                {
                    if((compara_palavras(x->palavra, p->palavra) == 0) && (compara_palavras(p->palavra, v->palavra) == 0)) // Caso 2.2(A)
                    {
                        // rotacao a direita
                        RotacaoSimplesDir(v);
                        if(p->red)
                            p->red = 0; // troca a cor do pai
                        else
                            p->red = 1;

                        if(v->red)
                            v->red = 0; // troca a cor do vo
                        else
                            v->red = 1;
                    }
                    else
                    {
                        if((compara_palavras(x->palavra, p->palavra) == 1) && (compara_palavras(p->palavra, v->palavra) == 1)) // Caso 2.2(B)
                        {
                            RotacaoSimplesEsq(v);
                            if(p->red)
                                p->red = 0; // troca a cor do pai
                            else
                                p->red = 1;

                            if(v->red)
                                v->red = 0; // troca a cor do vo
                            else
                                v->red = 1;
                        }
                        else
                        {
                            if(compara_palavras(p->palavra, v->palavra) == 0)  // Caso 2.2(C)
                            {
                                RotacaoSimplesEsq(p);
                                RotacaoSimplesDir(v); // rotacao Dupla a direita

                                if(x->red)
                                    x->red = 0; // troca a cor do novo
                                else
                                    x->red = 1;

                                if(v->red)
                                    v->red = 0; // troca a cor do vo
                                else
                                    v->red = 1;
                            }
                            else        // Caso 2.2(D)
                            {
                                RotacaoSimplesDir(p);
                                RotacaoSimplesEsq(v); // rotacao Dupla a esquerda

                                if(x->red)
                                    x->red = 0; // troca a cor do novo
                                else
                                    x->red = 1;

                                if(v->red)
                                    v->red = 0; // troca a cor do vo
                                else
                                    v->red = 1;
                            }
                        }
                    }
                }
            }
            else
            {
                // Caso 2.1
                if(v->esq->red) // tio é vermelho
                {
                    v->esq->red =0; // tio vira preto
                    if(p->red)
                        p->red = 0; // troca a cor do pai
                    else
                        p->red = 1;

                    if(v->pai == NodoNULL) // avô é raiz
                    {
                        p->dir->red = 0;
                        p->red = 0;
                        v->red = 0;
                    }
                }
                else
                {
                    if((compara_palavras(x->palavra, p->palavra) == 0) && (compara_palavras(p->palavra, v->palavra) == 0)) // Caso 2.2(A)
                    {
                        // rotacao a direita
                        RotacaoSimplesDir(v);

                        if(p->red)
                            p->red = 0; // troca a cor do pai
                        else
                            p->red = 1;

                        if(v->red)
                            v->red = 0; // troca a cor do vo
                        else
                            v->red = 1;
                    }
                    else
                    {
                        if((compara_palavras(x->palavra, p->palavra) == 1) && (compara_palavras(p->palavra, v->palavra) == 1)) // Caso 2.2(B)
                        {
                            RotacaoSimplesEsq(v); // --- aqui

                            if(p->red)
                                p->red = 0; // troca a cor do pai
                            else
                                p->red = 1;

                            if(v->red)
                                v->red = 0; // troca a cor do vo
                            else
                                v->red = 1;
                        }
                        else
                        {
                            if(compara_palavras(p->palavra, v->palavra) == 0)  // Caso 2.2(C)
                            {
                                RotacaoSimplesEsq(p);
                                RotacaoSimplesDir(v); // rotacao Dupla a direita

                                if(x->red)
                                    x->red = 0; // troca a cor do novo
                                else
                                    x->red = 1;
                                if(v->red)
                                    v->red = 0; // troca a cor do vo
                                else
                                    v->red = 1;
                            }
                            else // Caso 2.2(D)
                            {
                                RotacaoSimplesDir(p);
                                RotacaoSimplesEsq(v); // rotacao Dupla a esquerda

                                if(x->red)
                                    x->red = 0; // troca a cor do novo
                                else
                                    x->red = 1;

                                if(v->red)
                                    v->red = 0; // troca a cor do vo
                                else
                                    v->red = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    t->red = 0;
    x->red = 1;

    return t;
}
/*RBNode* Insere(RBNode* t, char *palavra)
{
    RBNode* x = t;

    if(t == NULL)
    {
        // alocação de espaço
        NodoNULL = (RBNode*) malloc(sizeof(RBNode));

        x = (RBNode*) malloc(sizeof(RBNode));

        //inicializações
        // NULL
        NodoNULL->red = 0; // null é preto;
        NodoNULL->esq = NodoNULL;
        NodoNULL->dir = NodoNULL;
        NodoNULL->pai = NodoNULL;

        // Raiz
        x->key = key;
        x->esq = x->dir = NodoNULL;
        x->red = 0;
        x->pai = NodoNULL;
        return x;
    }

    RBNode* p= x->pai; // pai
    RBNode* v= p->pai; // vo


    while(x != NodoNULL)  //desce na árvore
    {
        v = p; p = x;

        if( key < x->key )
            x = x->esq;
        else
            x = x->dir;
    }

    if(x != NodoNULL)
        return t; // Nodo Ja Existe

    x = (RNtree*) malloc(sizeof(RNtree));
    x->key = key;
    x->esq = x->dir = NodoNULL;
    x->pai = p;
    x->red = 1;

    if( key < p->key)
        p->esq = x;
    else
        p->dir = x;

    // Nodo Foi Inserido mas pode ter modificado as regras então temos que verificar.
    return VerificaRN(t, key);
}*/

/*******************************************************************PROGRAMA PRINCIPAL*******************************************************/
int main(int argc, char *argv[])
{
    //Muda a configuracao de região para imprimir e tratar corretamente os caracteres acentuados
    setlocale(LC_ALL, "");

    //Arquivos texto
    FILE *arquivo_texto = NULL; //Arquivo com o texto que sera lido e operado sobre
    FILE *arquivo_opera = NULL; //Arquivo que define que operacoes serao relizadas sobre o programa
    FILE *arquivo_saida = NULL; //Arquivo de saida, com o relatorio de execucao do programa

    //Ticks do relogio
    clock_t inicio_programa = clock();
    clock_t fim_programa;
    clock_t pre_avl;
    clock_t inicio_AVL;
    clock_t fim_AVL;
    clock_t inicio_RB;
    clock_t fim_RB;

    //Dados das arvores
    int comparacoes_AVL = 0;
    int comparacoes_RB = 0;
    int rotacoes_AVL = 0;
    int rotacoes_RB = 0;
    int mudacor_RB = 0;
    int tot_nodos_avl = 0;
    int tot_nodos_rb = 0;
    int altura_avl = 0;
    int altura_rb = 0;

    //Numero de operacoes
    int noperacoesF = 0;
    int noperacoesC = 0;

    //Arvore AVL
    int aux;
    avlNode *raiz_avl = NULL; //Precisa iniciar alocando como null!!!

    //Arvore RB
    int rb;
    int rot;
    RBNode *raiz_RB = NULL;

    //Algumas palavras para testar
    //raiz_RB = InsereRN(raiz_RB, "feijao", &rb, &rot);
    system("pause");

    //Imprime a apresentacao no inicio do programa, esperando o usuariario digitar alguma coisa
    imprime_apresentacao();
    system("pause");

    system("cls");
    printf("O nome do arquivo executavel atual eh: %s.exe \n", argv[0]);
    printf("O caminho do arquivo texto é: %s\n", argv[1]);
    printf("O caminho do arquivo de operações é: %s\n", argv[2]);
    printf("O caminho do arquivo de saida é: %s\n", argv[3]);

    if(abre_arquivo(&arquivo_texto, argv[1], "r"))
    { //Abre o arquivo texto
        error_texto();
        return 404;
    }
    if(abre_arquivo(&arquivo_opera, argv[2], "r"))
    { //Abre o arquivo de operacoes
        error_opera();
        return 404;
    }
    if(abre_arquivo(&arquivo_saida, argv[3], "wt"))
    { //Abre o arquivo de saida
        error_saida();
        return 404;
    }


    //Aloca matrizes de string com as operacoes solicitadas, com as dimensoes alocadas de forma dinamica de acordo com o numero de linhas do arquivo texto apontado
    int tot_linhas_op = checa_linhas(&arquivo_opera);

    char operacoesF[tot_linhas_op][N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA];
    char operacoesC[tot_linhas_op][8];

    //Pega as operacoes do arquivo de operacoes, para que essas sejam operadas mais tarde
    get_operacao(&arquivo_opera, N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA, 8, tot_linhas_op, operacoesF, operacoesC, &noperacoesF, &noperacoesC);

    //Informacoes sobre o programa - (antes)
    printf("\nO tamanho da matriz operacoesF é de %d bytes.\n", sizeof(operacoesF));
    printf("O tamanho da matriz operacoesC é de %d bytes.\n", sizeof(operacoesC));
    printf("\nO numero de linhas do arquivo texto é: %d.\n", checa_linhas(&arquivo_texto));
    printf("O numero de linhas do arquivo opera é: %d.\n\n", checa_linhas(&arquivo_opera));
    printf("Operacoes F solicitadas: %d.\n", noperacoesF);
    printf("Operacoes C solicitadas: %d.\n\n", noperacoesC);

    /***************************INICIO DO PROCESSO COM A ARVORE AVL****************************************/
    printf("\n**************Inicio do processo utilizando o método AVL*****************\n\n");
    printf("O número atual de nodos na árvore AVL é: %d\n", tot_nodos_avl);
    printf("A altura atual da arvore AVL é: %d.\n", checa_altura_AVL(raiz_avl));


    //Pega o texto inteiro e vai inserindo palavra por palavra na arvore
    inicio_AVL = clock(); //Tempo que o processo avl iniciou (ler do arquivo e inserir em uma arvore avl)
    le_texto_avl(&arquivo_texto, &raiz_avl, N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA, &aux, &tot_nodos_avl, &comparacoes_AVL, &rotacoes_AVL);

    //Informacoes sobre o programa - (depois)
    printf("\nO total de nodos é: %d\n", ContaNodos(raiz_avl)); //Alterei aqui
    altura_avl = checa_altura_AVL(raiz_avl);
    printf("A altura máxima da árvore eh: %d.\n", altura_avl);
    printf("Rotações realizadas na árvore AVL: %d.", rotacoes_AVL);

    //Desenha a arvore avl
    //printf("\n\n\n");
    //Desenha(raiz_avl, 1);
    intro_arquivo_saida_avl(&arquivo_saida, raiz_avl, tot_nodos_avl, comparacoes_AVL, inicio_programa, rotacoes_AVL);

    fim_arquivo_saida_AVL(&arquivo_saida, raiz_avl, tot_nodos_avl, comparacoes_AVL, inicio_AVL, &fim_AVL, rotacoes_AVL, noperacoesF, noperacoesC, N_LETRAS_MAIOR_PALAVRA_LINGUA_PORTUGUESA, 8, tot_linhas_op, operacoesF, operacoesC);

    printf("\n\n**************Fim do processo utilizando o método AVL*****************\n\n");


    /***************************INICIO DO PROCESSO COM A ARVORE RB****************************************/
    printf("\n**************Inicio do processo utilizando o método RB*****************\n\n");
    pre_avl = clock();
    intro_arquivo_saida_rb(&arquivo_saida, raiz_RB, tot_nodos_rb, comparacoes_RB, pre_avl, rotacoes_RB);

    printf("\n**************Fim do processo utilizando o método RB*****************\n\n");
    DesenhaRB(raiz_RB, 1);
    //Encerra o programa, fechando os arquivos e exibindo uma mensagem de encerramento
    imprime_encerramento();
    fclose(arquivo_texto);
    fclose(arquivo_opera);
    fclose(arquivo_saida);
    system("pause");

    return 0;
}
