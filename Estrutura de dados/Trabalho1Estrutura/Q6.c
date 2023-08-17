#include<stdio.h>

int main(){
    int idade;
    printf("Informar a idade: ");
    scanf("%d", &idade);
    if(idade>=18 && idade <=70){
        printf("Voto obrigatorio");
    }
    else if(idade==16 || idade == 17 || idade >70){
        printf("Voto facultativo");
    }
    else
    {
        printf("Não pode votar");
    }
    return 0;
}