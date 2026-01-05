#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {


    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    int i, j;


    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int linhaH = 2, colunaH = 3;

    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
        int podeColocar = 1;

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                podeColocar = 0;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    }

    int linhaV = 5, colunaV = 6;

    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
        int podeColocar = 1;

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                podeColocar = 0;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

  
    int linhaD1 = 0, colunaD1 = 0;

    if (linhaD1 + TAM_NAVIO <= TAM_TABULEIRO &&
        colunaD1 + TAM_NAVIO <= TAM_TABULEIRO) {

        int podeColocar = 1;

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) {
                podeColocar = 0;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

 
    int linhaD2 = 0, colunaD2 = 9;

    if (linhaD2 + TAM_NAVIO <= TAM_TABULEIRO &&
        colunaD2 - (TAM_NAVIO - 1) >= 0) {

        int podeColocar = 1;

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) {
                podeColocar = 0;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }


    printf("Tabuleiro Batalha Naval:\n\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}