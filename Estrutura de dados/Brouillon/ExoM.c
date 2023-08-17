#include<stdio.h>
int quadrado(int a){
    int resultado = a*a;
    return resultado;
}

int main(){
    int num;
printf("Entrar o Numero por favor: ");
scanf("%d", &num);

 int valor = quadrado(num);

printf("O quadrado %d é %d", num, valor);
return 0;
}