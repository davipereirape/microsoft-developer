#include <stdio.h>
#include <stdlib.h>

int pontosgeral = 0;
int contadorvetorrank = 0;

/*
* Struct to objeto rank. 
* Responsável por controlar todos os ranks do jogo.
*/
typedef struct rank {
    int pts;
    char nome[40];
};
struct rank vetorrank[0];

/*
* Função responsável por guardar os pontos da rodada.
*/
void acumulapontos(int pontos)
{ 
    pontosgeral = pontosgeral + pontos;
    printf("\n    / __|/ __/ _ \\| '__/ _ \\  %c \n", 220);
    printf("    \\__ \\ (_| (_) | | |  __/    %d \n", pontosgeral);
    printf("    |___/\\___\\___/|_|  \\___|  %c \n\n", 223);
}

/*
* Ordena o rank
*/
void ordenarank()
{
    struct rank temp;
    int i;
    int j;
    for (i=0; i < contadorvetorrank; i++)
    {
        for(j=i+1; j < contadorvetorrank; j++)
        {
            if (vetorrank[i].pts < vetorrank[j].pts)
            {
                temp = vetorrank[i];
                vetorrank[i] = vetorrank[j];
                vetorrank[j] = temp;
            }
        }
    }
}

/*
* Exibe o rank.
*/
short exiberank()
{
    ordenarank();
    printf("Rank Geral \n");
    int i;
    for (i = 0; i < contadorvetorrank; i++)
    {
        printf("%d%cColocado: Nome: %s               Pontua%c%co: %d \n", 
            i+1, 167, vetorrank[i].nome, 135,132, vetorrank[i].pts);
    }

    int continuacao = 0;
    printf("\n");
    printf("Deseja iniciar um novo jogo? \n", 163);
    printf("(1) Sim (2) N%co \n\n", 132);
    printf("Escolha: ");
    scanf("%d", &continuacao);

    switch(continuacao) 
    {
        case 1: 
            return 1;
        default:
            return 0;
    }
}

/*
* Realiza os procedimentos de fim de jogada, operações ocorrem quando 
* o jogador erra ou falha uma partida.
*/
short fimdejogada()
{
    struct rank novorank;
    novorank.pts = pontosgeral;

    printf("Informe seu primeiro nome: ");
    scanf("%s", novorank.nome);
    printf("\n");

    //struct rank *temp = (struct rank*) realloc(&vetorrank, (sizeof(vetorrank) +1) );  
    vetorrank[contadorvetorrank] = novorank;
  
    // configura variaveis do arquivo para nova rodada.
    pontosgeral = 0;
    contadorvetorrank++;
    return exiberank();
}