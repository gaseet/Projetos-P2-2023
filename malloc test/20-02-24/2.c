#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearMemory(char **ptr, size_t size) {
    if (ptr != NULL) {
        memset(*ptr, 0, size);  
        free(*ptr);
        *ptr = NULL;
    }
}

int main() {
    char *password = malloc(20);
    strcpy(password, "sensitive data");

    printf("%s\n", password);

    clearMemory(&password, strlen(password));

    if (password == NULL) {
        printf("Memory has been successfully cleared.\n");
    } else {
        printf("Memory has not been cleared.\n");
    }

    return 0;
}
