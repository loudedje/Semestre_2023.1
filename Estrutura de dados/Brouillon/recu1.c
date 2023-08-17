#include<stdio.h>
int somatario(int v[], int tamanho){
    if (tamanho ==0){
        return 0;
    }
    else{
         return v[tamanho-1]+ somatario(v,tamanho-1);
    }
}

int main(){
    int n;
    printf("Entrar o vetor: ");
    scanf("%d", &n);
    int resultado = somatario(v,tamanho);
    printf(" O somatario é %d: ", resultado);
    
}