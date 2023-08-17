#include <stdio.h>
#include<math.h>

typedef struct {
    int p1;//primeira posi
    int p2;//segunda posi
} V2D;

V2D atribuir(V2D v, int p1, int p2);
void imprimir(V2D v);
V2D soma(V2D v1, V2D v2);
V2D subtracao(V2D v1, V2D v2);
float modulo(V2D v);
int produto_interno(V2D v1, V2D v2);

int main() {
    V2D v1, v2, w;
    
    // atribuição dos valores
    printf("Entre com o primeiro valor: ");
    scanf("%d", &v1.p1);
    printf("Entre com o segundo valor: ");
    scanf("%d", &v1.p2);
    printf("Entre com o terceiro valor: ");
    scanf("%d", &v2.p1);
    printf("Entre com o quarto valor: ");
    scanf("%d", &v2.p2);

    // impressão dos valores
    printf("v1 = ");
    imprimir(v1);
    printf("\n");
    
    printf("v2 = ");
    imprimir(v2);
    printf("\n");

    // soma entre v1 e v2
    w = soma(v1, v2);
    printf("v1 + v2 = ");
    imprimir(w);
    printf("\n");
    
    // subtração entre v1 e v2
    w = subtracao(v1, v2);
    printf("v1 - v2 = ");
    imprimir(w);
    printf("\n");
    
    // cálculo do módulo de v1
    float mod = modulo(v1);
    printf("Módulo de v1 = %.3f\n", mod);
    
    // cálculo do produto interno entre v1 e v2
    int produto = produto_interno(v1, v2);
    printf("Produto interno entre v1 e v2 = %d\n", produto);
    
    return 0;
}


V2D atribuir(V2D v, int p1, int p2) {
    v.p1 = p1;
    v.p2 = p2;
    return v;
}

void imprimir(V2D v){
    printf("<%d %d>", v.p1,v.p2);
}

V2D soma(V2D v1, V2D v2){
    V2D soma;
    soma.p1 = v1.p1 + v2.p1;
    soma.p2 = v1.p2 + v2.p2;
    return soma;
}

V2D subtracao(V2D v1, V2D v2){
    V2D sub;
    sub.p1 = v1.p1 - v2.p1;
    sub.p2 = v1.p2 - v2.p2;
    return sub;
}

float modulo(V2D v) {
    return sqrt (v.p1 * v.p1 + v.p2 * v.p2);
}

int produto_interno(V2D v1, V2D v2) {
    //return v1.p1 * v2.p1 + v1.p2 * v2.p2;
     return v1.p1*v1.p1+v2.p2*v2.p2;
}