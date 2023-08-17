#include <stdio.h>

int main() {
    char simbolo;
    int num1, num2, resultado;

    for (;;) {
        printf("Bem vindo ao nossa Calculadora\n");
        printf("Para adição  entre + ,multiplicação entre *, divisão entre / para substração entre - e @ para encerrar a calculadora\n");
        printf("Digite o simbolo: ");
        scanf(" %c", &simbolo);

        if (simbolo == '+') {
            printf("Digite o primeiro valor: ");
            scanf("%d", &num1);
            printf("Digite o segundo valor: ");
            scanf("%d", &num2);
            resultado = num1 + num2;
            printf("O resultado da soma de %d e %d é: %d\n", num1, num2, resultado);
        }
        else if (simbolo == '*') {
            printf("Digite o primeiro valor: ");
            scanf("%d", &num1);
            printf("Digite o segundo valor: ");
            scanf("%d", &num2);
            resultado = num1 * num2;
            printf("O resultado da multiplicação %d e %d é: %d\n", num1, num2, resultado);
        }
        else if (simbolo == '/') {
            printf("Digite o primeiro valor: ");
            scanf("%d", &num1);
            printf("Digite o segundo valor: ");
            scanf("%d", &num2);
            if (num2 == 0) {
                printf("Não é possível realizar a divisão por zero\n");
            }
            else {
                resultado = num1 / num2;
                printf("O resultado da divisão de %d e %d é: %d\n", num1, num2, resultado);
            }
        }
        else if (simbolo == '-') {
            printf("Digite o primeiro valor: ");
            scanf("%d", &num1);
            printf("Digite o segundo valor: ");
            scanf("%d", &num2);
            resultado = num1 - num2;
            printf("O resultado da substração de %d e %d é: %d\n", num1, num2, resultado);
        }
        else if (simbolo == '@') {
            printf("Encerrando a calculadora...\n");
            break;
        }
        else {
            printf("Digite um simbolo de operador válido\n");
        }
    }

    return 0;
}
