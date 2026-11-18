#include <stdio.h>

/*
 * Experiment 9: CPU-Bound Process
 * Executes an intensive compute loop to continuously consume CPU cycles.
 * Observed via 'top' consuming ~100% CPU.
 */

int main()
{
    printf("CPU-bound process started. Consuming CPU cycles...\n");
    volatile unsigned long long counter = 0;
    while (1) {
        counter++;
    }
    return 0;
}
