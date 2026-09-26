#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "matrix.h"

/* Comparison function for qsort */
int compare(const void *a, const void *b) {
    int diff = *(const int *)a - *(const int *)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

void print(int* jobs, int size) {
    if (size <= 0) return;
    /* Print the sorted result for debugging */
    for (int i = 0; i < size; i++) {
        
        /* Print integers without decimal point when possible */
        printf("%i", (int)jobs[i]);

        if (i < size - 1) {
            printf(",");
        }
    }
    printf("\n");
}
// First in first out
float FIFO(int* jobs, int size) {
    print(jobs, size);

    float totalTime = 0;
    for (int i = 0; i < size; i++) {
        int number = (int)jobs[i];
        
        float elapsed = do_job(number, number, number, 0);
        totalTime += elapsed;
        printf("%dx%d matrices: %.6f seconds\n", number, number, elapsed);
    }
    printf("Average time: %f\n", (float)(totalTime/size));
    return totalTime;
}

// Shortest job first
float SJF(int* jobs, int size) {

    /* Sort the numbers for shortest job first */
    qsort(jobs, size, sizeof(int), compare);
    return FIFO(jobs, size);
}
