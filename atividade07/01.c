#include <stdio.h>

int main () {

    char c = 'a';
    char *pc = &c;

    printf("O endereço de \"C\" é: %p.\nO valor guardado por \"C\" é: %c\n", pc, c);
    printf("O valor armazenado por \"PC\" é: %p.\nO valor guardado no endereço apontado por \"PC\" é: %c\n", pc, *pc);
    printf("O endereço de \"PC\" é: %p", &pc);

    return 0;
}
