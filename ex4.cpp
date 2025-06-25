#include <stdio.h>
#include <stdlib.h>

int main(void){


    FILE *arquivoMatriz = fopen("matriz.txt", "r");
    if (arquivoMatriz == NULL) {
        perror("Erro ao abrir matriz.txt");
        return 1;
    }
    int tamanho;
    if (fscanf(arquivoMatriz, "%d", &tamanho) != 1 || tamanho <= 0) {
        fprintf(stderr, "Dimensão.\n");
        fclose(arquivoMatriz);
        return 1;
    }

    int matrizA[tamanho][tamanho];
    int matrizB[tamanho][tamanho];
    int matrizResultado[tamanho][tamanho];


    for (int linha = 0; linha < tamanho; ++linha)
        for (int coluna = 0; coluna < tamanho; ++coluna)
            fscanf(arquivoMatriz, "%d", &matrizA[linha][coluna]);

    for (int linha = 0; linha < tamanho; ++linha)
        for (int coluna = 0; coluna < tamanho; ++coluna)
            fscanf(arquivoMatriz, "%d", &matrizB[linha][coluna]);

    fclose(arquivoMatriz);

    for (int linha = 0; linha < tamanho; ++linha)
        for (int coluna = 0; coluna < tamanho; ++coluna)
            matrizResultado[linha][coluna] = matrizA[linha][coluna] + matrizB[linha][coluna];

    puts("Matriz soma:");
    for (int linha = 0; linha < tamanho; ++linha) {
        for (int coluna = 0; coluna < tamanho; ++coluna)
            printf("%d ", matrizResultado[linha][coluna]);
        putchar('\n');
    }

    return (0);
}
