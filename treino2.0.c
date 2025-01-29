#include <stdio.h>
#include <stdlib.h>

// Função adicionar elementos na matriz
void add(int l, int c, int matriz[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Elemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para exibir uma matriz
void print(int l, int c, int matriz[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para somar duas matrizes
void somar(int l, int c, int matriz1[l][c], int matriz2[l][c], int resultado[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Função para multiplicar duas matrizes
void multiply(int l1, int c1, int l2, int c2, int matriz1[l1][c1], int matriz2[l2][c2], int resultado[l1][c2]) {
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

// Função para calcular o determinante de uma matriz 3x3
int determinat3x3(int matriz[3][3]) {
    int a = matriz[0][0], b = matriz[0][1], c = matriz[0][2];
    int d = matriz[1][0], e = matriz[1][1], f = matriz[1][2];
    int g = matriz[2][0], h = matriz[2][1], i = matriz[2][2];

    return a * e * i + b * f * g + c * d * h - c * e * g - b * d * i - a * f * h;
}

// Função para calcular o determinante de uma matriz de ordem qualquer
int determinant(int n, int matriz[n][n]) {
    if (n == 1) {
        return matriz[0][0];
    }
    if (n == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    int det = 0;
    int temp[n - 1][n - 1];

    for (int col = 0; col < n; col++) {
        int sub_i = 0;

        for (int i = 1; i < n; i++) {
            int sub_j = 0;

            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                temp[sub_i][sub_j] = matriz[i][j];
                sub_j++;
            }
            sub_i++;
        }

        int sign = (col % 2 == 0) ? 1 : -1;
        det += sign * matriz[0][col] * determinant(n - 1, temp);
    }

    return det;
}

int main() {
    int opcao;

    // Menu de opções
    printf("Escolha a operacao:\n");
    printf("1 - Soma de matrizes\n");
    printf("2 - Multiplicacao de matrizes\n");
    printf("3 - Determinante de matriz 3x3\n");
    printf("4 - Determinante de matriz qualquer ordem\n");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 3) {
        // Matriz para o determinante
        int matrizA[3][3];

        // Recebendo os valores da matriz
        printf("Digite os valores da matriz 3x3:\n");
        add(3, 3, matrizA);
        printf("\n");

        // Calculando e exibindo o determinante
        int determinante = determinat3x3(matrizA);
        printf("O determinante da matriz e: %d\n", determinante);

    } else if (opcao == 4) {
        int n;
        printf("Digite a ordem da matriz quadrada: ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Erro: Ordem da matriz deve ser positiva.\n");
            return 1;
        }

        int matriz[n][n];
        printf("Digite os valores da matriz %dx%d:\n", n, n);
        add(n, n, matriz);
        printf("\n");

        // Calculando e exibindo o determinante
        int determinante = determinant(n, matriz);
        printf("O determinante da matriz e: %d\n", determinante);
    } else if (opcao == 1 || opcao == 2) {
        // Soma e multiplicação (mesmo código anterior)
        int l1, c1, l2, c2;
        printf("Digite o numero de linhas e colunas da matriz A: ");
        scanf("%d %d", &l1, &c1);
        printf("Digite o numero de linhas e colunas da matriz B: ");
        scanf("%d %d", &l2, &c2);

        int matrizA[l1][c1], matrizB[l2][c2];

        printf("Digite os valores da matriz A:\n");
        add(l1, c1, matrizA);
        printf("Digite os valores da matriz B:\n");
        add(l2, c2, matrizB);

        if (opcao == 1) {
            if (l1 == l2 && c1 == c2) {
                int resultado[l1][c1];
                somar(l1, c1, matrizA, matrizB, resultado);
                printf("Resultado da soma:\n");
                print(l1, c1, resultado);
            } else {
                printf("Erro: As matrizes devem ter as mesmas dimensoes para somar\n");
            }
        } else if (opcao == 2) {
            if (c1 == l2) {
                int resultado[l1][c2];
                multiply(l1, c1, l2, c2, matrizA, matrizB, resultado);
                printf("Resultado da multiplicacao:\n");
                print(l1, c2, resultado);
            } else {
                printf("Erro: O numero de colunas da matriz A deve ser igual ao numero de linhas da matriz B\n");
            }
        }
    } else {
        printf("Opcao invalida\n");
    }

    return 0;
}
