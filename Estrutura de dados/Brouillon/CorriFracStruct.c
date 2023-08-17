#include<stdio.h>
#include "fraction.h"

int main()
{
    Fraction f1;
    double num1, den1, nume2, den2;
   
    printf("Digite o numerador: ");
    scanf("%d",&num1);
   
    printf("Digite o denominador: ");
    scanf("%d", &den1);
    f1 = setFraction(num1, den1);
   
    Fraction f2;
   
    printf("Digite o numerador: ");
    scanf("%d",&nume2);
   
    printf("Digite o denominador: ");
    scanf("%d", &den2);
    f2 = SetFraction(nume2, den2);
   
    printf("%.2f/ %.2f x %.2lf/%.2lf\n", f1.numerador, f1.denominador, f2.numerador, f2.denominador);
   
   
    return 0;
}

