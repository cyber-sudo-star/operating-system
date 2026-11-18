#include <stdio.h>

/*
 * Experiment 7: String Operations in C
 * - Finds string length
 * - Extracts substring based on starting position and length
 */

int main()
{
    char str[100];
    int start, length, i, count = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    // Calculate length excluding newline and null terminator
    while (str[count] != '\0' && str[count] != '\n') {
        count++;
    }

    printf("Length of string: %d\n", count);

    printf("Enter Starting Position: ");
    scanf("%d", &start);

    printf("Enter Number of characters: ");
    scanf("%d", &length);

    printf("Substring: ");
    for (i = start; i < start + length && i < count; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
