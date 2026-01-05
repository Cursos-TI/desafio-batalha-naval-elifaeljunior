#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
   
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO]   = {3, 3, 3};

    
    int linhaH = 2, colunaH = 3; 
    int linhaV = 5, colunaV = 6; 

    int i, j;

    
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }


    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
       
        int podeColocar = 1;
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podeColocar = 0;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }


    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
       
        int podeColocar = 1;
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeColocar = 0;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
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