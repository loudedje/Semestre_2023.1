#include<stdio.h>
 int expo(int b, int e){
     
     if(e==0){
         return 0;
     }
     else if(e==1){
         return 1;
     }
     else{
         return b*expo(b,e-1);
     }
 }

int main(){
    int b,e;
    printf("Entrar o expoente: ");
    scanf("%d", &e);
    printf("Entrar a base: ");
    scanf("%d", &b);
    printf("%d elevado a %d é %d: " ,b,e,expo(b,e));
}