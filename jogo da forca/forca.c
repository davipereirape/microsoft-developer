#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

    // variável globais
     char palavrasecreta [TAMANHO_PALAVRA];
     char chutes[26]; // quantidade do alfabeto

/**
* Realiza a abertura do jogo
**/
void abertura()
{
    printf("*****************************\n");
    printf("*        Jogo de Forca      *\n");
    printf("*****************************\n\n");
}

/**
* Solicita o novo chute do player.
*/
void chuta(int* numerochutes) // Recebe o endereço da memória da variávels
{
    char chute;
    scanf(" %c", &chute); // O Espaço ignora o ENTER
    chutes[(*numerochutes)] = chute;
    (*numerochutes)++; // Recuperar o valor da variável através do ponteiro, usando o endereço de memória passado
}

/**
* Verifica as letras chutadas e exibi-as
*/
int jachutou(char letra, int numerochutes)
{
    for (int j = 0; j < numerochutes; j++)
    {
        if (chutes[j] == letra)
        {
            return 1;
        }
    }
    return 0;
}

/**
* Verifica se achou a letra na palavra, printando a letra ou o traço de espaço vazio.
*/
void desenhaforca(int numerochutes)
{
    int erros = chuteserrados(numerochutes);
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");


    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        int achou = jachutou(palavrasecreta[i], numerochutes);

        if (achou)
            printf("%c ", palavrasecreta[i]);
        else
            printf("__ ");
    }
    printf("\n");
}

/**
* Verifica se o usuário que adicionar um nova palavra ao banco de dados do jogo.
*/
void adicionapalavra()
{
    char quer;
    printf("Voce deseja adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra que voce deseja adicionar? \n");
        scanf("%s", novapalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+");
        if (f == 0)
        {
            printf("Desculpe, banco de dados indisponível!\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET); // volta para primeira posição do arquivo;
        fprintf(f, "%d", qtd); // Atualiaza a nova quantidade de palavras no arquivo

        fseek(f, 0, SEEK_END); // Posiciona na ultima linha do arquivo
        fprintf(f, "\n%s", novapalavra); // escreve a palavra

        fclose(f);
    }
}

/**
* Escolhe a palavra
*/
void escolhepalavra()
{
    FILE* f;
    f = fopen("palavras.txt", "r");
    if (f == 0)
    {
        printf("Desculpe, banco de dados indisponível!\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d" ,&qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

/**
* Verifica se o player ganhou, acertando todas as letras da palavra
*/
int ganhou(int numerochutes)
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i], numerochutes))
        {
            return 0;
        }
    }
    return 1;
}

/**
* retonar a quantidade de chutes errados
*/
int chuteserrados(int numerochutes)
{
    int erros = 0;
    for (int i = 0; i < numerochutes; i++)
    {
        int existe = 0;
        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
        }

        if (!existe) erros++;
    }

    return erros;
}

/**
* Valida se o usuário já encerrou o seu número de chutes.
*/
int enforcou(int numerochutes)
{
    return chuteserrados(numerochutes) > 5;
}

int main ()
{
    // Para compilar usando o gcc: gcc forca.c -o forca.exe
    // Recuperando a palavra chave
    escolhepalavra();
   // palavrasecreta[9] = '\0'; // Indica para o printf até onde ele deve verificar o array de char

    // JOGO...
    abertura();
    int numerochutes = 0;
    do
    {
        desenhaforca(numerochutes);
        chuta(&numerochutes); // Passa o endereço da memória.
    }
    while (!ganhou(numerochutes) && !enforcou(numerochutes));

    if (ganhou(numerochutes))
    {
        printf("\nA palavra era **%s**\n", palavrasecreta);
        printf("Parabens, voce ganhou!\n\n");
        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

        adicionapalavra();
    }
    else
    {
        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}