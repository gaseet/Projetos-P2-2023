#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *p_c = (char *)malloc(100000000000000000);
    printf("%p", p_c);
    free(p_c);
    p_c = NULL;
    return 0;
}