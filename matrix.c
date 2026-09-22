#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_random_matrix(int rows, int cols, int *matrix) {
    if (matrix == NULL || rows <= 0 || cols <= 0) {
        return;  // invalid input
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i * cols + j] = rand();
        }
    }
}

void multiply_matrices(int rows1, int cols1, int *matrix1,
                       int rows2, int cols2, int *matrix2,
                       int *result) {
    // Check dimension compatibility
    if (cols1 != rows2 || matrix1 == NULL || matrix2 == NULL || result == NULL) {
        return;
    }

    int rows_result = rows1;
    int cols_result = cols2;

    for (int i = 0; i < rows_result; i++) {
        for (int j = 0; j < cols_result; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                // matrix1[i][k] * matrix2[k][j]
                sum += matrix1[i * cols1 + k] * matrix2[k * cols2 + j];
            }
            result[i * cols_result + j] = sum;
        }
    }
   
}

void display_matrix(int rows, int cols, int *matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

float do_job(int rows1, int cols1, int cols2, int forever) {

   
}


