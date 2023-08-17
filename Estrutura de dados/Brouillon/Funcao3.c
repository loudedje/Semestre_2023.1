#include<stdio.h>

int valor(int a, int b, int c){
    if(a>b && a>c){
        printf("O primeiro é maior");
    }
    else if(b>a && b>c){
        printf("O segundo é maior");
    }
    else {
        printf("O terceiro é menor");
    }
}
int main(){
    int v1,v2,v3, maior;

    printf("Entrar o primeiro valor: ");
    scanf("%d",&v1);
    printf("Entrar o segundo valor: ");
    scanf("%d", &v2);
    printf("Entrar o terceiro valor: ");
    scanf("%d", &v3);

    maior=valor(v1,v2,v3);

    return 0;
}