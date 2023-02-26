#include <stdio.h>
#include <string.h>

struct jogador
{
    char nome[10];
    int idade;
    int num_passes_corretos;
    int num_gols;
    int num_faltas;
    int num_passes_errados;
    float pontuacao;

}; typedef struct jogador Atleta;
