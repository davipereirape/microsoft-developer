#include <stdio.h>

int main () 
{
    // Para compilar usando o gcc: gcc forca.c -o forca.exe
    // Recuperando a palavra chave
    char palavrasecreta [20];
    sprintf(palavrasecreta, "MELANCIA"); 
    palavrasecreta[9] = '\0'; // Indica para o printf até onde ele deve verificar o array de char

    printf("%s\n", palavrasecreta);

    // JOGO...
    int acertou = 0;
    int enforcado = 0;
    do 
    {

    } while (!acertou && !enforcado);
}