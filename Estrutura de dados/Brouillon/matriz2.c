#include<stdio.h>

int main(){
    int matriz[4][4];
    
    int maior=0;
    int menor=matriz[0][0];
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("Digite os valores [%d][%d]: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
           if(matriz[i][j]> maior){
               maior=matriz[i][j];
           } 
           if(matriz[i][j]< menor){
               menor = matriz[i][j];
           }
            
            
        }
    }
    
    printf("O maior elemento é %d: ", maior);
    printf("o menor elemento é %d", menor);
    
    return  0;
}