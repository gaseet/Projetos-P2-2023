#include <stdio.h>

struct vetor {
    int x;
    int y;
};

int main() {

    struct vetor v[3];

    printf("Informe x do vetor 1: ");
    scanf("%d", &v[0].x);

    printf("Informe y do vetor 1: ");
    scanf("%d", &v[0].y);

    printf("Informe x do vetor 2: ");
    scanf("%d", &v[1].x);

    printf("Informe y do vetor 2: ");
    scanf("%d", &v[1].y);

    v[2].x = v[0].x + v[1].x;
    v[2].y = v[0].y + v[1].y;

    printf("Vetor R3: [%d, %d]", v[2].x, v[2].y);

    return 0;
}