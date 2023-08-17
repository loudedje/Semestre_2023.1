#include<stdio.h>

void funcao(int vetor[], int tamanho){
    int maior;
    int menor;

for(int i=0; i<tamanho; i++){
    if(vetor[i]>maior){
        maior=vetor[i];
    }
    if(vetor[i]<menor){
        menor=vetor[i];
    }
}
    printf("O maior elemento é ", maior);
    printf("O menor elemento é ", maior);
}
int main(){
    int a = { 1, 3, 4, 7, 8, 9};
    int tamanho [5];

    int imprimir = funcao(a,tamanho);


}