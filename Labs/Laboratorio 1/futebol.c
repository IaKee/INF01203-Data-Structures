#include "futebol.h"

void atribui_dados(int num_jogadores, Atleta* player)
{

    for(int index=0; index<num_jogadores; index++)
    {
        printf("Digite o nome do jogador %d: ", index+1); //Jogador[i]
        scanf("%s", player[index].nome);
        printf("Digite a idade do jogador %d:", index+1); //Jogador[i]
        scanf("%d", &player[index].idade);
        printf("Digite o numero de gols do jogador %d: ", index+1); //Jogador[i]
        scanf("%d", &player[index].num_gols);
        printf("Digite o numero de faltas do jogador %d: ", index+1); //Jogador[i]
        scanf("%d", &player[index].num_faltas);
        printf("Digite o numero de passes errados do jogador %d: ", index+1); //Jogador[i]
        scanf("%d", &player[index].num_passes_errados);
        printf("Digite o numero de passes corretos do jogador %d: ", index+1); //Jogador[i]
        scanf("%d", &player[index].num_passes_corretos);
    }

}

void exibe_estatistica(int num_jogadores, Atleta* player)
{
    system("cls"); //Limpa a tela, para nao ficar com muitas informacoes

    printf("Dados dos jogadores: \n\n");
    printf("Nome     Idade  Num Gols  Num Faltas  Passes errados  Passes Certos  Hab\n");

    for(int index=0; index<num_jogadores; index++)
    {
        printf("\n%s", player[index].nome);
        espaco(11-strlen(player[index].nome));
        printf("%d       %d           %d            %d               %d", player[index].idade, player[index].num_gols, player[index].num_faltas, player[index].num_passes_errados, player[index].num_passes_corretos);
        if(player[index].pontuacao > 50.0)
        {
            printf("     BOM!");
        }
        else
        {
            printf("       RUIM!");
        }
    }
    printf("\n\n");
}

void eh_o_bom(int num_jogadores, Atleta* player)
{   //Calcula a pontuacao de cada jogador e exibe na tela
    for(int index=0; index<num_jogadores; index++)
    {
        if(player[index].idade < 26)
        {
            player[index].pontuacao+=20;
        }
        if(player[index].idade > 33)
        {
            player[index].pontuacao+=10;
        }
        if(player[index].idade > 26 || player[index].idade < 33)
        {
            player[index].pontuacao+=30;
        }
        player[index].pontuacao+=(player[index].num_passes_corretos*0.1);
        player[index].pontuacao+=(player[index].num_passes_errados*-0.25);
        player[index].pontuacao+=(player[index].num_gols);
        player[index].pontuacao+=(player[index].num_faltas*-0.25);
    }
}

void espaco(int qtd)
{ //Funcao que da espacos na tela
    for(int i=0; i<qtd; i++)
        printf(" ");
}
