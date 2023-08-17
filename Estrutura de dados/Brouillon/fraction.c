#include "fraction.h"

Fraction setFraction(double nume, double deno){
    Fraction fract = {nume, deno};
   
    return fract;
}

Fraction MultFraction(Fraction f1, Fraction f2){
    Fraction result = {f1.numerador * f2.denominador, f1.denominador*f2.denominador};
    return result;
}


//para compilar primeiro o arquivo do main  - o fraction C Obs: deve ser no terminal 
