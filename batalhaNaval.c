#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int i, j;

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;

    tabuleiro[5][6] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][6] = NAVIO;


    int cone[TAM_HAB][TAM_HAB];

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }


    int cruz[TAM_HAB][TAM_HAB];

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }


    int octaedro[TAM_HAB][TAM_HAB];

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    int origemConeL = 1, origemConeC = 1;

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            int l = origemConeL + i;
            int c = origemConeC + j;

            if (l < TAM_TABULEIRO && c < TAM_TABULEIRO && cone[i][j] == 1) {
                if (tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = HABILIDADE;
            }
        }
    }


    int origemCruzL = 5, origemCruzC = 2;

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            int l = origemCruzL + i - TAM_HAB / 2;
            int c = origemCruzC + j - TAM_HAB / 2;

            if (l >= 0 && c >= 0 && l < TAM_TABULEIRO && c < TAM_TABULEIRO && cruz[i][j] == 1) {
                if (tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = HABILIDADE;
            }
        }
    }

    int origemOctL = 6, origemOctC = 6;

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            int l = origemOctL + i - TAM_HAB / 2;
            int c = origemOctC + j - TAM_HAB / 2;

            if (l >= 0 && c >= 0 && l < TAM_TABULEIRO && c < TAM_TABULEIRO && octaedro[i][j] == 1) {
                if (tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = HABILIDADE;
            }
        }
    }

    printf("Tabuleiro com Habilidades:\n\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}