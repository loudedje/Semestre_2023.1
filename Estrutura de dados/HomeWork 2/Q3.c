#include <stdio.h>

int main() {
    int num, soma = 0;

    printf("Informe um numero: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        soma += i;
    }

    printf("A soma dos numeros de 1 até %d é : %d", num, soma);

    return 0;
}
