#include<stdio.h>
int main(){
    
    int posicao;
    printf("Entrar a posição do competidor: ");
    scanf("%d", &posicao);
    
    if(posicao>=1 && posicao<=5){
        printf("Top 5\n");
    }
    else if(posicao>=6 && posicao<=10){
        printf("Top 10\n");
    }
    else if(posicao >=11 && posicao <= 20){
        printf("Top 20\n");
    }
    else if( posicao >= 21 && posicao <= 30){
        printf("Top 30");
    }
    else {
        printf("Top 100");
    }
    return 0;
}