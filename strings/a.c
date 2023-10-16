#include <stdio.h>

int main() {
    
    char nome[3][10] = 
    {
        {"Teste"},
        {"Teste2"},
        {"Teste3"}
    };
    
    for (int i = 0; i < 3; i++) {
        printf("%s\n", nome[i]);
    }

    return 0;
}
