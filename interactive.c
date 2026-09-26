#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "matrix.h"
#include "scheduler.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <FIFO/SJF> <job_sizes_comma_separated> \n", argv[0]);
        return 1;
    }


    int isFifo = (strcmp(argv[1], "FIFO"));

    char *input = argv[2];
    size_t len = strlen(input);

    /* Count how many numbers are present */
    int count = 1;
    for (size_t i = 0; i < len; i++) {
        if (input[i] == ',') {
            count++;
        }
    }

    /* Allocate array for the numbers */
    int *numbers = malloc(count * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    /* Parse the numbers */
    char *token = strtok(input, ",");
    int idx = 0;
    while (token != NULL && idx < count) {
        /* Skip leading whitespace */
        while (isspace((unsigned char)*token)) token++;

        char *endptr;
        numbers[idx] = strtod(token, &endptr);

        /* Basic validation */
        if (token == endptr) {
            fprintf(stderr, "Error: invalid number '%s'\n", token);
            free(numbers);
            return 1;
        }

        idx++;
        token = strtok(NULL, ",");
    }


    // Parse the inputs from the user of jobs to run in the format 100,200,400 meaning matrix multiply a 100x100 matrices, 200x200 matrices, 400x400 matrices.

    // Run jobs in the current ordering


    printf("IDX: %i", idx);
    if (isFifo) {
        return FIFO(numbers, idx);
    } else {
        return SJF(numbers, idx);
    }

    /*
    
    
    float totalTime = 0;
    for (int i = 0; i < idx; i++) {
        int number = (int)numbers[i];
        
        float elapsed = do_job(number, number, number, 0);
        totalTime += elapsed;
        printf("%dx%d matrices: %.6f seconds\n", number, number, elapsed);
    }
    
    printf("Average time: %f\n", (float)(totalTime/idx));
    */

    return 0;
}