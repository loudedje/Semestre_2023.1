#include<stdio.h>

int main(){
    int vetor[10];
    for(int i=0; i<10; i++){
        printf("Por favor Digite os numeros %d:  ",i );
        scanf("%d", &vetor[i]);
        
    }
    for( int i=9; i>=0;i--){
        printf("\nOs numeros em ordem inversas são %d:\n ",vetor[i]);
    }
    return 0;
    
}