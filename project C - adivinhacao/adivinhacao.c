#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// #define NUMERO_TENTATIVAS 3 (DEFINE VARIÁVEL GLOBAL)
 
int main ()
{
    //setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português  

    // Utilizado o compilador GCC
    // Imprime o cabecalho do nosso jogo
    printf(" \n");
    printf("            P                                       \n");
    printf("         P /_\\   P                                  \n");                 
    printf("        /_\\_|_|_/_\\                               \n");                  
    printf("    n_n | ||. .|| | n_n       Bem vindo ao          \n");
    printf("    |_|_|nnnn nnnn|_|_|    Jogo de Adivinha%c%co!     \n", 135, 132);
    printf("   |" "  |  |_|  |"  " |                            \n");
    printf("   |_____| ' _ ' |_____|                            \n");
    printf("         \\__|_|__/                                 \n\n");
    
    // VERIFICANDO O NíVEL DO JOGO
    int nivel;
    printf("Qual o n%cvel de dificuldade? \n", 163);
    printf("(1) F%ccil (2) M%cdio (3) Dif%ccil \n\n", 160, 130, 141);
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
        printf("Qual %c o seu chute? ", 130);
        scanf("%d", &chute); // Recolhe o valor digitado pelo usuário. O %d significa que é esperado um número.
        printf("Seu chute foi: %d !\n", chute);

        if (chute < 0)
        {
            printf("Você n%co pode chutar n%cmeros negativos! \n", 132, 151);
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou)            
            break;
        else if (maior)
            printf("Seu chute foi maior que o n%cmero secreto! \n", 151);
        else
            printf("Seu chute foi menor que o n%cmero secreto! \n", 151);
        
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

        printf("Parab%cns, voc%c ganhou!\n", 130, 136);
        printf("Voc%c acertou em %d tentativas!\n", 136, tentativas);
        printf("Total de pontos: %.2f\n", pontos );
    }
    else 
    {
        printf("Voc%c perdeu! Tente de novo! \n", 136);
        printf("       \\|/ ____ \\|/       \n");
        printf("        @~/ ,. \\~@        \n");
        printf("       /_( \\__/ )_\\       \n");
        printf("          \\__U_/        \n\n");
    }
    // FIM
}  