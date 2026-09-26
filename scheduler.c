#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "matrix.h"

// First in first out
float FIFO(int* jobs, int size) {
    if (size <= 0) return 0.0f;

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
    return FIFO(jobs, size);
    /*
    if (size <= 0) return 0.0f;

    float totalTime = 0;
    for (int i = 0; i < size; i++) {
        int number = (int)jobs[i];
        
        float elapsed = do_job(number, number, number, 0);
        totalTime += elapsed;
        printf("%dx%d matrices: %.6f seconds\n", number, number, elapsed);
    }
    printf("Average time: %f\n", (float)(totalTime/size));
    return totalTime;
    */
}
