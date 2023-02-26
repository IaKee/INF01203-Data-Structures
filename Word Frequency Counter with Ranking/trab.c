void imprime_apresentacao()
{
    printf("\t\tContador de frequencia de palavras em um texto\n");
    printf("\n\t\t     Trabalho final de Estrutura de Dados\n");
    printf("\n\t\t\t\t  PROFESSORA:");
    printf("\n\t\t\t\tRenata Galante\n");
    printf("\n\t\t\t\t   ALUNOS:");
    printf("\n\t\t\t   Giordano Souza   308054\n");
    printf("\t\t\t   Sabryna Trindade 302133\n\n");
}
int solicita_arquivos(char* caminho_texto, char* caminho_opera, int* flag_open, FILE* arquivo_texto, FILE* arquivo_operacoes, FILE* arquivo_output, unsigned long* tempo_anterior, unsigned long* tempo_atual)
{
    int aux = 0;
    //1 Se algo deu errado, zero se tudo esta ok
    if(*flag_open==1)
        printf("\nCaminho nulo encontrado!!!\nDigite o endereco, tente novamente...\n");
    if(*flag_open==2)
        printf("\nCaminho grande demais!!!\nVerifique o endereco e tente novamente...\n");
    if(*flag_open==4)
        printf("\nNao foi possivel acessar o arquivo do texto!!!\nVerifique o endereco e tente novamente...\n");
    if(*flag_open==5)
        printf("\nNao foi possivel acessar o arquivo das operacoes!!!\nVerifique o endereco e tente novamente...\n");
    if(*flag_open==6)
        printf("\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!\nVerifique o endereco e tente novamente...\n");

    printf("\nPor favor digite o nome (caminho) do arquivo com o texto a ser operado: \n-");
    gets(caminho_texto);

    printf("\nAgora digite o nome (caminho) do arquivo com as operacoes que serao realizadas:\n-");
    gets(caminho_opera);

    if(strlen(caminho_opera) == 0 || strlen(caminho_texto) == 0) //Se o nome de um dos arquivos estiver vazio...
    {
        *flag_open = 1;
        return 1;
    }
    if(strlen(caminho_opera) >=TAM_MAX_CAMINHO-4 || strlen(caminho_texto)>=TAM_MAX_CAMINHO-4) //Se o nome de um dos arquivos estiver vazio...
    {
        *flag_open = 2;
        return 2;
    }

    //Apos tratar o tamanho do caminho do arquivo, trata se esse tem o formato .txt ou nao
    coloca_formato(caminho_texto, caminho_opera);

    aux = abre_arquivo(caminho_texto, caminho_opera, arquivo_texto, arquivo_operacoes, arquivo_output, tempo_anterior, tempo_atual);
    if(aux == 4)
    {
        *flag_open = 4;
        return 4;
    }
    if(aux == 5)
    {
        *flag_open = 5;
        return 5;
    }
    if(aux == 6)
    {
        *flag_open = 6;
        return 6;
    }
    *flag_open = 0; //Se nao ocorreu nenhum erro ate aqui
    return 0;
}
void coloca_formato(char* caminho_texto, char* caminho_opera)
{
    int tem_formato_tex=0, tem_formato_opera=0;;

    for (int i=0; i<TAM_MAX_CAMINHO; i++)
    {
        if(caminho_texto[i] == '.')
        {
            if(caminho_texto[i+1] == 't')
            {
                if(caminho_texto[i+2] == 'x')
                {
                    if(caminho_texto[i+3] == 't')
                        tem_formato_tex = 1; //Se chegou ate aqui, indica que o arquivo tem um formato (.txt) no caminho indicado
                }
            }
        }
        if(caminho_opera[i] == '.')
        {
            if(caminho_opera[i+1] == 't')
            {
                if(caminho_opera[i+2] == 'x')
                {
                    if(caminho_opera[i+3] == 't')
                        tem_formato_opera = 1; //Se chegou ate aqui, indica que o arquivo tem um formato (.txt) no caminho indicado
                }
            }
        }
    }
    if(!tem_formato_tex)
        strcat(caminho_texto, ".txt");
    if(!tem_formato_opera)
        strcat(caminho_opera, ".txt");
}
int abre_arquivo(char* caminho_texto, char* caminho_opera, FILE* arquivo_texto, FILE* arquivo_operacoes, FILE* arquivo_output, unsigned long* tempo_anterior, unsigned long* tempo_atual)
{
    tempo_anterior = (unsigned long*)(clock()/CLOCKS_PER_SEC); //Calcula o tempo gasto na abertura dos arquivos
    arquivo_texto = fopen(caminho_texto, "r+");
    if(!arquivo_texto)
        return 4;
    arquivo_operacoes = fopen(caminho_opera, "r+");
    if(!arquivo_operacoes)
        return 5;
    arquivo_output = fopen("output/resultado.txt", "w+"); //Exclui o arquivo de output anterior, se existir
    if(!arquivo_output)
        return 0;
    //teste_passou();
    return 0;
}
void fecha_arquivos(FILE* arquivo_texto, FILE* arquivo_operacoes, FILE* arquivo_output)
{
    printf("Fechando arquivos texto...\n");
    fclose(arquivo_texto);
    fclose(arquivo_operacoes);
    fclose(arquivo_output);
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
/*FUNCOES COPIADAS*/
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
void apaga_caracteres(int x, int y, int quantidade)
{ //Apaga uma definida quantidade de caracteres a partir de definida posicao do display - útil para a organizacao de interface
    move_cursor(x, y); //Move o cursor para a posicao que foi definida
    for(int aux = 0; aux< quantidade; aux++) //Imprime a quantidade de espacos que foi definida na chamada da funcao
        printf(" ");
}
void move_cursor(int x, int y)
{ //Funcao que move o cursor na tela para a posicao (x, y) enviada por referencia - útil para organizacao de intereface
    COORD pos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, pos);
}
