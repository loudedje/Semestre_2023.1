#include<stdio.h>
int max(int m, int n){
    if(n==0){
        return m;
    }
    else{
        max(n, m%n);
    }
}
int main(){
    int n,m;
    printf("Entrar o n: ");
    scanf("%d", &n);
    printf("Entrar o m: ");
    scanf("%d", &m);
    
    int resu= max(n,m);
    
    printf("O MDC é: %d", resu);
}