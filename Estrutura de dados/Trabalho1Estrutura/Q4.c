#include <stdio.h>

int main() {
    int num1, num2, num3, num4;
    int numPosi = 0, numNega = 0;

    printf("Entrar o primeiro numero: ");
    scanf("%d", &num1);
    printf("Entrar o segundo numero: ");
    scanf("%d", &num2);
    printf("Entrar o terceiro numero: ");
    scanf("%d", &num3);
    printf("Entrar o quarto numero: ");
    scanf("%d", &num4);

    if (num1 >= 0) {
        numPosi++;
    } else {
        numNega++;
    }
    if (num2 >= 0) {
        numPosi++;
    } else {
        numNega++;
    }
    if (num3 >= 0) {
        numPosi++;
    } else {
        numNega++;
    }
    if (num4 >= 0) {
        numPosi++;
    } else {
        numNega++;
    }

    printf("Digitou %d (+) e %d (-)", numPosi, numNega);

    return 0;
}
