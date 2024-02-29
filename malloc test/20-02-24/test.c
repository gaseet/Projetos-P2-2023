#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dynamically allocate memory for an integer variable
    int *test = (int *)malloc(sizeof(int));

    if (test == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assign a value to the dynamically allocated variable
    *test = 10;

    // Print the value of the dynamically allocated variable
    printf("The value of test is: %d\n", *test);

    // Free the dynamically allocated memory
    free(test);

    return 0;
}
