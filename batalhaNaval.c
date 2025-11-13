#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3  // Tamanho fixo dos navios

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAM][TAM];

    // Declaração dos navios (apenas para representar o tamanho de cada um)
    int navio1[TAM_NAVIO];
    int navio2[TAM_NAVIO];

    // Inicializa os navios (não é obrigatório, mas ajuda a visualizar)
    for (int i = 0; i < TAM_NAVIO; i++) {
        navio1[i] = 3;
        navio2[i] = 3;
    }

    // Inicializa o tabuleiro com 0 (representando água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ----------------------------
    // POSICIONAMENTO DOS NAVIOS
    // ----------------------------

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linha_navio1 = 2; // navio horizontal começa na linha 2
    int coluna_navio1 = 4;

    int linha_navio2 = 5; // navio vertical começa na linha 5
    int coluna_navio2 = 7;

    // Validação simples: garantir que o navio horizontal cabe no tabuleiro
    if (coluna_navio1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha_navio1][coluna_navio1 + i] = 3;
        }
    } else {
        printf("Erro: o navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Validação simples: garantir que o navio vertical cabe no tabuleiro
    if (linha_navio2 + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_navio2 + i][coluna_navio2] == 3) {
                sobreposicao = 1; // já existe navio nessa posição
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_navio2 + i][coluna_navio2] = 3;
            }
        } else {
            printf("Erro: navios se sobrepõem!\n");
            return 1;
        }
    } else {
        printf("Erro: o navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // ----------------------------
    // EXIBIÇÃO DO TABULEIRO
    // ----------------------------
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
