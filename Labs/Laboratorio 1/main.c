#include "futebol.h"
#define N_JOGADORES 2

int main()
{
    int a;
    Atleta Jogador[N_JOGADORES];

    atribui_dados(N_JOGADORES, &Jogador);
    eh_o_bom(N_JOGADORES, &Jogador);
    exibe_estatistica(N_JOGADORES, &Jogador);
    printf("\n\nN aperta enter ae vlw");
    scanf("%d", &a);

    return 0;
}
