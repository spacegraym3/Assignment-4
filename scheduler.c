#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "matrix.h"

// Helper: compute average waiting time for a sequence of jobs
static float average_waiting_time(int* jobs, int size) {
    if (size <= 0) return 0.0f;

    long long total_wait = 0;
    long long current_time = 0;

    for (int i = 0; i < size; i++) {
        total_wait += current_time;   // waiting time of this job
        current_time += jobs[i];      // advance time by this job's burst
    }

    return (float)total_wait / size;
}

// First in first out
float FIFO(int* jobs, int size) {
    // First-In-First-Out = process jobs in the given order
    return average_waiting_time(jobs, size);
}

// Shortest job first
float SJF(int* jobs, int size) {
    if (size <= 0) return 0.0f;

    // Make a copy so we don't modify the original array
    int* sorted = malloc(size * sizeof(int));
    if (!sorted) return 0.0f;          // allocation failed

    memcpy(sorted, jobs, size * sizeof(int));

    // Sort by burst time (ascending) – simple bubble sort is fine here
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
        }
    }

    float avg = average_waiting_time(sorted, size);
    free(sorted);
    return avg;
}
