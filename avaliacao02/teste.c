#include <stdio.h>

int main() {

    int matriz [5][4] = {1};
    int j = 0;
    int i = 0;
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d\n", matriz[i][j]);
        }
    }
    
    return 0;
}