#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// TODO: Check that matrix has been allocated correctly
// Two dimentional array represented as one
void generate_random_matrix(int rows, int cols, int *matrix) {

    if (matrix == NULL || rows <= 0 || cols <= 0) {
        return;  // invalid input
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            matrix[r * cols + c] = rand();
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

    struct timespec t0, t1;

    do {
        int* matrix1 = malloc(sizeof(int) * rows1 * cols1);
        printf("Generating Matrices...");
        generate_random_matrix(rows1, cols1, matrix1);
        printf("Matrix 1 done\n");


        int* matrix2 = malloc(sizeof(int) * rows1 * cols2);
        generate_random_matrix(rows1, cols2, matrix2);
        printf("Matrix 2 done\n");

        int* result = malloc(sizeof(int) * rows1 * cols2);

        timespec_get(&t0, TIME_UTC); 
        multiply_matrices(
            rows1, cols1, matrix1, 
            rows1, cols2, matrix2,
            result);

        timespec_get(&t1, TIME_UTC);  // C11 feature
        //display_matrix(rows1, cols1, result);
        free(matrix1);
        free(matrix2);
        free(result);
    } while (forever);


    // nano seconds elapsed converted to fractional seconds
    float dns = (float)(t1.tv_nsec - t0.tv_nsec) / 1000000000;
    // seconds elapsed
    float ds = (float)(t1.tv_sec - t0.tv_sec);

    float total_time = dns+ds;
    return total_time;
}


