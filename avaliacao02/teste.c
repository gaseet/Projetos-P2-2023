#include <stdio.h>

int main() {

    int matriz [5][4] = {1};
    
    for (int i = 0; i < 5; i++) {
        for(int j = 0; i < 4; j++) {
            printf("%d", matriz[i][j]);
        }
    }

    
    return 0;
}