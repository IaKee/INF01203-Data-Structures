/*DEFINICAO DE STRUCTS*/
struct numero
{
    int num;
    struct numero *prox;
    int flag;
};
typedef struct numero tipoNumero;


/*PROTOTIPACAO DE FUNCOES*/
int checa_divisibilidade(int);
tipoNumero* cria_lista();
tipoNumero* insere_elementos (tipoNumero*, tipoNumero);
void imprime(tipoNumero*);
tipoNumero* destroi(tipoNumero*);
tipoNumero* encontraUltimo(tipoNumero*);
