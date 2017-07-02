#include <stdio.h>
#include <stdlib.h>
#include "tratapontos.h"

int main ()
{
    short statusgame = 1;
    while (statusgame)
    {
        int qtdpontos;
        printf(" \n");
        printf("Fez quantos pontos? ");
        scanf("%d", &qtdpontos);
        acumulapontos(qtdpontos); // DEVE SER CHAMADO PARA GUARDAR OS PONTOS

        // Verifica se a partida acabou
        short perdeu;
        printf("Perdeu? (1) sim (2) Nao: \n");
        scanf("%d", &perdeu);

        if (perdeu == 1)
        {
            statusgame = fimdejogada(); // DEVE SER CHAMADO QUANDO O JOGADOR PERDER 
        } 
    }
}