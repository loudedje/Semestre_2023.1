#include<stdio.h>

int main(){
    int vet[8];
    int menor=0;
    int maior=0;
    int i;
    
    for(i=1; i<8; i++){
        printf("Digite o numero %d: ", i);
        scanf("%d",&vet[i]);
        
        if (vet[i]>maior){
           maior=vet[i];
        }
        if(vet[i]<menor){
            menor=vet[i];
        }
    }
    printf("O maior digito é: %d\n", maior);
    printf("O menor digito é: %d", menor);
    
    return 0;
}