#include <stdio.h>

int main() {
    int numero, i;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for(i=1; i<=numero; i++) {
        printf("%d", i);
        if(i == (numero / 2)) {
            printf("Metade\n");
        }
    }

    return 0;
}
