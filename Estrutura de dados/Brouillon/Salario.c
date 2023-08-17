#include<stdio.h>

//assinatura da função salario corrigida
double salario(double horas, double valor);

int main(){
    float a, b,resultado;
    printf("Entrar a Hora de Trabalha: \n");
    scanf("%f", &a);
    printf("Entrar o valor trabalha\n");
    scanf("%f",&b);
    resultado = salario(a,b);
    printf("O salario é: %.2f", resultado);
    
    return 0;
}

//tipo de retorno da função salario corrigido para double
double salario(double horas, double valor){
    double salario_final = horas * valor;
    if(horas > 200)
        salario_final = salario_final * 1.5;
    return salario_final;
}