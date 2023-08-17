#include<stdio.h>
int main(){
    int horas;
    float valor, salario, salarioFinal;
    

    printf("Entrar a hora do Trabalho: ");
    scanf("%d", &horas);
    printf("Entrar o valor de hora trabalhada: ");
    scanf("%f", &valor);
    if (horas <=200){
    salario = horas * valor;
    printf("O salário é:  %.2f", salario);
    }
    else if (horas>200)
    {
        salario = horas * valor;
        salarioFinal = salario + (salario * 0.05);
        printf("O salário é: %.2f", salarioFinal);
        
    }
    return 0;
}