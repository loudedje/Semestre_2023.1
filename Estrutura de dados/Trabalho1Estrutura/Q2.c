#include<stdio.h>


int main(){

    int opcao;
    float preco,precoFim;
    printf("Entrar o preço: ");
    scanf("%f", &preco);
    printf("Entrar a opcao de pagamento\n");
    printf("1- À Vista\n");
    printf("2- A prazo\n");
    scanf("%d", &opcao);
    if(opcao == 1){
         precoFim = preco-(preco*0.05);
        printf("O preço Final (à Vista): R$ %.2f",precoFim);
    }
    
    else if( opcao ==2){
        float precoFim = preco + (preco*0.1);
        printf("O preço Final (a Prazo): R$ %.2f", precoFim);
    }
    else{
        printf("Forma invalida\n");
    }
    return 0;
}