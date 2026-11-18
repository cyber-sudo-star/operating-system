#include <stdio.h>
#include <unistd.h>

/*
 * Experiment 9: I/O-Bound Process
 * Spends most of its time in sleeping / waiting state.
 * Observed via 'top' consuming negligible CPU (< 1%) and via 'pmap' for memory mapping.
 */

int main()
{
    printf("I/O-bound process started. Sleeping in loop...\n");
    while (1) {
        sleep(1);
    }
    return 0;
}
