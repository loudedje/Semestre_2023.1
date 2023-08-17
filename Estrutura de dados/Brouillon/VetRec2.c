#include<stdio.h>

int main(){
   // int  tamanho=5;
    int vet[5];
    double media =0;
    int i;
    
    for(i=0; i<5; i++){
        printf("Digite os numeros %d: ",i);
        scanf("%d", &vet[i]);
    }
    for( i=0; i<5; i++){
        printf("Os valores digitados: %d\n ", vet[i]);
        media+=vet[i];
     }
        media= media/5;
        printf("A media dos valores é %.2lf: ", media);

    return 0;
    
}