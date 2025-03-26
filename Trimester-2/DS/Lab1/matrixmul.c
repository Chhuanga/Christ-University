#include <stdio.h>
#include <time.h>

#define N 3
#define M 3

void displayRuntime(clock_t start, clock_t end) {
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
    printf("Runtime: %f seconds\n", time_taken*1000);
}

void rowSumCalculation(int matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < M; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of elements in row %d: %d\n", i+1, sum);
    }
}

void columnSumCalculation(int matrix[N][M]) {
    for (int j = 0; j < M; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += matrix[i][j];
        }
        printf("Sum of elements in column %d: %d\n", j+1, sum);
    }
}

void matrixAddition(int matrix1[N][M], int matrix2[N][M], int result[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int matrix1[N][M], int matrix2[N][M], int result[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrixMultiplication(int matrix1[N][M], int matrix2[M][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int validateInput(int *value) {
    if (scanf("%d", value) != 1) {
        while (getchar() != '\n'); 
        return 0;
    }
    return 1;
}

void inputMatrix(int matrix[N][M], const char *name) {
    printf("Enter elements of %s:\n", name);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            while (1) {
                printf("Element [%d][%d]: ", i + 1, j + 1);
                if (validateInput(&matrix[i][j])) {
                    break;
                } else {
                    printf("Invalid input. Please enter an integer.\n");
                }
            }
        }
    }
}

int main() {
    clock_t start, end;
    start = clock();
    int matrix1[N][M], matrix2[N][M], result[N][M];

    inputMatrix(matrix1, "matrix1");
    inputMatrix(matrix2, "matrix2");

    printf("Matrix1:\n");
    displayMatrix(matrix1);

    printf("Matrix2:\n");
    displayMatrix(matrix2);

    rowSumCalculation(matrix1);
    columnSumCalculation(matrix1);

    matrixAddition(matrix1, matrix2, result);
    printf("Addition Result:\n");
    displayMatrix(result);

    matrixSubtraction(matrix1, matrix2, result);
    printf("Subtraction Result:\n");
    displayMatrix(result);

    matrixMultiplication(matrix1, matrix2, result);
    printf("Multiplication Result:\n");
    displayMatrix(result);
    
    end = clock();
    displayRuntime(start, end);

    return 0;
}