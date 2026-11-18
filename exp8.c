#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
 * Experiment 8: Memory Allocation and Monitoring
 * Allocates requested Megabytes of memory, touches pages,
 * and intercepts SIGINT (Ctrl+C) to safely free memory.
 */

void *ptr = NULL;

void handle_sigint(int sig)
{
    printf("\nSignal Interrupt Detected.\n");
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
        printf("Memory released.\n");
    }
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <memory_in_MB>\n", argv[0]);
        return 1;
    }

    int mb = atoi(argv[1]);
    if (mb <= 0) {
        printf("Please specify a valid positive number of MB.\n");
        return 1;
    }

    size_t bytes = (size_t)mb * 1024 * 1024;
    ptr = malloc(bytes);

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Touch memory to ensure physical page allocation (Resident Set Size - RSS)
    char *cptr = (char *)ptr;
    for (size_t i = 0; i < bytes; i += 4096) {
        cptr[i] = 1;
    }

    printf("Memory allocated Successfully (%d MB).\n", mb);
    printf("Press Ctrl+C to release memory and exit.\n");

    signal(SIGINT, handle_sigint);

    // Keep process alive so memory can be observed using 'free -h' and 'ps aux'
    while (1) {
        sleep(1);
    }

    return 0;
}
