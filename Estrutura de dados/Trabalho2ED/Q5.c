#include<stdio.h>

int main(){
    int n;
    int facto =1;
     
     printf("Informe o numero por favor: ");
     scanf("%d",&n);
     if(n<0){
        printf("O numero pode ser negativo por favor entre um numero positivo");
     }
     else{
        for(int i=1; i<=n;i++){
            facto= facto*i;
        }
        printf("O factorial de %d é %d", n , facto);
     }
}