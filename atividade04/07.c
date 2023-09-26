#include <stdio.h>
int main(){

    float n1, n2, n3;
    float media;
    printf("Informe a primeira nota do aluno: ");
    scanf("%f", &n1);
    printf("Informe a segunda nota do aluno: ");
    scanf("%f", &n2);
    printf("Informe a terceira nota do aluno: ");
    scanf("%f", &n3);
    media = (n1 + n2 + n3) / 3;
    if (media >= 7) {
        printf("O aluno está aprovado com média %.1f", media);
    } else {
        printf("O aluno está reprovado com média %.1f", media);
    }
    return 0;
}
