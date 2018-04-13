#include <stdio.h>

int main(void)
{
    const int N = 2;

    int matrix_a[N][N] = {
        {1,0},
        {0,1}
    };

    int matrix_b[N][N] = {
        {12,11},
        {25,45}
    };

    int matrix_c[N][N];

    // Обычнвя матрица A
    printf("Matrix A:\n");
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            printf("|%3i", matrix_a[i][j]);
        }
        printf("|\n");
    }

    // Матрица B
    printf("Matrix B:\n");
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            printf("|%3i", matrix_b[i][j]);
        }
        printf("|\n");
    }

    // Сумма матриц A+B
    printf("A+B:\n");
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            matrix_c[i][j] = matrix_a[i][j]+matrix_b[i][j];
        }
    }

    // Матрица C
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            printf("|%3i", matrix_c[i][j]);
        }
        printf("|\n");
    }

    // Умножение матриц AxB
    printf("AxB:\n");
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            matrix_c[i][j] = 0;
            for (int r=0; r<N; ++r) {
                matrix_c[i][j] +=
                    matrix_a[i][r]*matrix_b[r][j];
            }
        }
    }

    // Матрица  C
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            printf("|%3i", matrix_c[i][j]);
        }
        printf("|\n");
    }

    // AT
    printf("AT:\n");
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            matrix_c[i][j] = matrix_b[j][i];
        }
    }

    // Вывод матрицы C
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            printf("|%3i", matrix_c[i][j]);
        }
        printf("|\n");
    }

    return 0;
}