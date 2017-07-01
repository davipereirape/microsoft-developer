#include <stdio.h>

#define NUMERO_TENTATIVAS 3
 
int main ()
{
    // Utilizado o compilador GCC
    // Imprime o cabecalho do nosso jogo
    printf("***********************************\n");
    printf("* Bem vindo ao jogo de adivinhação.*\n");
    printf("***********************************\n");

    int numerosecreto = 42;
    int chute;
    int tentativas = 1;

    while (1)
    {
        printf("Tentativa %d \n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute); // Recolhe o valor digitado pelo usuário. O %d significa que é esperado um número.
        printf("Seu chute foi: %d !\n", chute);

        if (chute < 0)
        {
            printf("Você não pode chutar números negativos! \n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou)
        {
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
            break;
        }
        else if (maior)
        {
            printf("Seu chute foi maior que o número secreto! \n");
        }
        else
        {
            printf("Seu chute foi menor que o número secreto! \n");
        }
        tentativas++;
    }
    printf("FIM DE JOGO! \n");
    printf("Você acertou em %d tentativas!", tentativas);
}  