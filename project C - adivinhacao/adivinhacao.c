#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define NUMERO_TENTATIVAS 3 (DEFINE VARIÁVEL GLOBAL)
 
int main ()
{
    // Utilizado o compilador GCC
    // Imprime o cabecalho do nosso jogo
    printf(" \n");
    printf("            P                                       \n");
    printf("         P /_\\   P                                  \n");                 
    printf("        /_\\_|_|_/_\\                               \n");                  
    printf("    n_n | ||. .|| | n_n       Bem vindo ao          \n");
    printf("    |_|_|nnnn nnnn|_|_|    Jogo de Adivinhação!     \n");
    printf("   |" "  |  |_|  |"  " |                            \n");
    printf("   |_____| ' _ ' |_____|                            \n");
    printf("         \\__|_|__/                                 \n\n");
    
    // VERIFICANDO O NíVEL DO JOGO
    int nivel;
    printf("Qual o nível de dificuldade? \n");
    printf("(1) Fácil (2) Médio (3) Difícil \n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerotentativas;
    switch(nivel) 
    {
        case 1: 
            numerotentativas = 20;
            break;
        case 2:
            numerotentativas = 15;
            break;
        default:
            numerotentativas = 6;
    } // FIM NíVEL JOGO    

    // RECUPERANDO NÚMERO ALEATÓRIO.
    int segundos = time(0); // Recupera o valor total de segundos de 1970 até o momento atual.
    srand(segundos); // planta um novo número a ser usado para função rand (isto faz gerar números diferentes)
    int numerogrande = rand(); // recupera o número aleatório
    // FIM DO NÚMERO ALEATÓRIO
    
    // ORGANIZA VARIÁVEIS DO PROGRAMA
    int numerosecreto = numerogrande % 100; // coloca o número de 0 a 100,sendo o número,o resto da divisão por 100
    double pontos = 1000;
    int chute;
    int tentativas = 0;
    int acertou = 0;
    // FIM DA ORGANIZAÇÃO 

    // INICIO DO GAME
    for (int i = 1; i <= numerotentativas; i++)
    {
        printf("Tentativa %d \n", ++tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute); // Recolhe o valor digitado pelo usuário. O %d significa que é esperado um número.
        printf("Seu chute foi: %d !\n", chute);

        if (chute < 0)
        {
            printf("Você não pode chutar números negativos! \n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou)            
            break;
        else if (maior)
            printf("Seu chute foi maior que o número secreto! \n");
        else
            printf("Seu chute foi menor que o número secreto! \n");
        
        double pontosperdidos = (double) (chute - numerosecreto) / 2;
        pontos = pontos - abs(pontosperdidos); // função abs retira o sinal, trazendo apenas o número.
    }

    printf("FIM DE JOGO! \n");
    if(acertou)
    {
        printf("            OOOOOOOOOOO                         \n");
        printf("         OOOOOOOOOOOOOOOOOOO                    \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO                 \n");
        printf("    OOOOOO      OOOOO      OOOOOO               \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO             \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO            \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO           \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO           \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO           \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO            \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO             \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO              \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO               \n"); 
        printf("         OOOOOO         OOOOOO                  \n");
        printf("             OOOOOOOOOOOO                     \n\n");

        printf("Parabéns, você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.2f\n", pontos );
    }
    else 
    {
        printf("Você perdeu! Tente de novo! \n");
        printf("       \\|/ ____ \\|/       \n");
        printf("        @~/ ,. \\~@        \n");
        printf("       /_( \\__/ )_\\       \n");
        printf("          \\__U_/        \n\n");
    }
    // FIM
}  