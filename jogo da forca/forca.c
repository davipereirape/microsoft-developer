#include <stdio.h>
#include <string.h>

int main () 
{
    // Para compilar usando o gcc: gcc forca.c -o forca.exe
    // Recuperando a palavra chave
    char palavrasecreta [20];
    sprintf(palavrasecreta, "MELANCIA"); 
    palavrasecreta[9] = '\0'; // Indica para o printf até onde ele deve verificar o array de char


    // JOGO...
    char chutes[26]; // quantidade do alfabeto
    int tentativas = 0, acertou = 0, enforcado = 0;
    do 
    {
        // Verifica se achou a letra na palavra, printando a letra ou o traço de espaço vazio.
        for (int i = 0; i < strlen(palavrasecreta); i++)
        {
            int achou = 0;
            for (int j = 0; j < tentativas; j++)
            {
                if (chutes[j] == palavrasecreta[i])
                {
                    achou = 1;
                    break;
                }
            }
            if (achou) 
                printf("%c ", palavrasecreta[i]);
            else
                printf("__ ");  
        }
        printf("\n");

        char chute; 
        scanf(" %c", &chute); // O Espaço ignora o ENTER
        chutes[tentativas] = chute;
        tentativas++;

    } while (!acertou && !enforcado);
}