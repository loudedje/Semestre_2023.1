#include <stdio.h>

typedef struct{
   
    double numerador;
    double denominador;
   
} Fraction;

Fraction setFraction(double nume, double deno);
Fraction multFraction(Fraction f1, Fraction f2);

int main()
{
    Fraction f1, f2, f3;
    double num1, den1, nume2, den2;
   
    printf("Digite o numerador: ");
    scanf("%lf",&num1);
   
    printf("Digite o denominador: ");
    scanf("%lf", &den1);
    f1 = setFraction(num1, den1);
   
    printf("Digite o numerador: ");
    scanf("%lf",&nume2);
   
    printf("Digite o denominador: ");
    scanf("%lf", &den2);
    f2 = setFraction(nume2, den2);
   
    f3 = multFraction(f1,f2);
   
    printf("%.2f/ %.2f x %.2lf/%.2lf\n", f1.numerador, f1.denominador, f2.numerador, f2.denominador);
    printf("resultado = %.2lf/ %.2lf\n", f3.numerador, f3.denominador);
   
    return 0;
}

Fraction setFraction(double nume, double deno){
    Fraction fract = {nume, deno};
   
    return fract;
}




Fraction multFraction(Fraction f1, Fraction f2){
    Fraction result = {f1.numerador * f2.numerador, f1.denominador*f2.denominador};
    return result;
}