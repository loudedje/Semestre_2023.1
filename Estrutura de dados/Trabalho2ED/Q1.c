#include <stdio.h>

int main() {
    int numero, i;

    printf("Digite um numero: ");//1
    scanf("%d", &numero);//1

    for(i=1; i<=numero; i++) {//n
        printf("%d\n", i);//1
        if(i == (numero / 2)) {//1
            printf("Metade\n");//1
        }
    }
    return 0;

    //A complexidade é o(n)