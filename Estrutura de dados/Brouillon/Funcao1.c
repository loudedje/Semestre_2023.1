#include<stdio.h>


//assinatura
int Soma(int a,int b);

int Soma(int a,int b)
{
    int resultado = a+b;
    return resultado;
}


int main(){
    int v1, v2, a;
    printf("Entrar o primeiro numero: ");
    scanf("%d", &v1);
    printf("Entrar o segundo numero: ");
    scanf("%d",&v2);
    a=Soma(v1,v2);
    printf("Resultado = %d\n", a);

    return 0;
}
//int Soma(int a,int b)
