#include<stdio.h>
int Num(int a, int b){
    if(a>b){
        return a;
        //printf("O primeiro é maior");
    }
    else{
        return b;
        //printf("O segundo é maior");
    }

}
int main(){
    int v1,v2, maior;
    printf("Entrar o primeiro numero: ");
    scanf("%d",&v1);
    printf("Entrar o segundo numero: ");
    scanf("%d",&v2);

    maior = Num(v1,v2);
    printf("O maior elemento %d", maior);
    return 0;
}