#include <stdio.h>
#include <string.h>

int main() {
    char c[50];
    printf("c: ");
    fgets(c, sizeof(c), stdin);

    // Use strtok to find and replace newline character
    char *newline = strtok(c, "\n");
    if (newline != NULL) {
        printf("Modified c: %s\n", c);
    } else {
        printf("No newline character found in the string.\n");
    }

    return 0;
}
