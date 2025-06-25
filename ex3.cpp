#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarCartelaBingo(FILE *arqSaida)
{
    for (int linha = 0; linha < 5; ++linha) { /*Coluna B */
        fprintf(arqSaida, "%d, ", (rand() % 15) + 1);

        /*Coluna I */
        fprintf(arqSaida, "%d, ", (rand() % 15) + 16);

        /* Coluna N */
        if (linha == 2)
            fprintf(arqSaida, "FREE, ");
        else
            fprintf(arqSaida, "%d, ", (rand() % 15) + 31);

        /* Coluna G */
        fprintf(arqSaida, "%d, ", (rand() % 15) + 46);

        /* Coluna O */
        fprintf(arqSaida, "%d\n", (rand() % 15) + 61);
    }
}

int main(void)
{
    /* Números aleatórios usando o relógio do sistema */
    srand((unsigned) time(NULL));

    /* Abre arquivo CSV */
    FILE *arqSaida = fopen("cartelas.csv", "w");
    if (arqSaida == NULL) {
        perror("Erro ao criar cartelas.csv");
        return 1;
    }

    /* Solicita a quantidade de cartelas */
    int totalCartelas;
    printf("Digite a quantidade de cartelas: ");
    if (scanf("%d", &totalCartelas) != 1 || totalCartelas <= 0) {
        fprintf(stderr, "Quantidade inválida.\n");
        fclose(arqSaida);
        return 1;
    }

    fprintf(arqSaida, "B, I, N, G, O\n");

    /* Gera as cartelas */
    for (int c = 0; c < totalCartelas; ++c)
        gerarCartelaBingo(arqSaida);

    fclose(arqSaida);
    puts("Cartelas geradas em \"cartelas.csv\".");

    return (0);
}
