//Definicao da estrutura para a lista trabalhada
typedef struct tipoNo ptLSE;
struct tipoNo{
 int numero;
 ptLSE *prox;
 ptLSE *ant;
};

ptLSE* insere(ptLSE* ptInicio, int num);
int ExibeIni(ptLSE* ptInicio);
int ExibeInversoNum(ptLSE* ptInicio, int num);
ptLSE* Destroi(ptLSE* ptInicio);
