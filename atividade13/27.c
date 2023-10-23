#include <stdio.h>
#include <string.h>

int main() {
    char string1[100];
    char string2[100];

    printf("Informe a primeira string: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Informe a segunda string: ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';

    char *ocorrencia = strstr(string1, string2);

    if (ocorrencia != NULL && ocorrencia == string1 + (strlen(string1) - strlen(string2))) {
        printf("A segunda string está contida no final da primeira.\n");
    } else {
        printf("A segunda string não está contida no final da primeira.\n");
    }

    return 0;
}
