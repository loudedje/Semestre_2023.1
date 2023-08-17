#include <stdio.h>

int main() {
    int numeros[20];
    int i = 0;
    int num;

    while (1) {
        printf("Entre um numero : ");
        scanf("%d", &num);
        if (num <= 0) {
            break;
        }
        numeros[i] = num;
        i++;
    }

    int contagem = 0;
    for (int j = 0; j < i; j++) {
        if (numeros[j] >= 10 && numeros[j] <= 20) {
            contagem++;
        }
    }

    float resultado = (float) contagem / i * 100;
    printf("%% entre 10 e 20: %.2f%%\n", resultado);

    return 0;
}

