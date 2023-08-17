#include<stdio.h>

void imprimeVetor(int *vetor, int tamanho);
void MaiorMenor(int *vetor, int tamanho);
int main(){

    int i , veto[5];

    for ( i=0; i<5;i++){
        printf("Entrar os valores: ");
        scanf("%d",&veto[i]);

        printf("\n");

        imprimeVetor(veto,i);
        MaiorMenor(veto,i);

        printf("\n");

        return 0;

    }
    /*printf("\n\n");
    for(i = 0; i < 5; i++)   // imprime o vetor
        printf("%d ", veto[i]);

    return 0;*/
}
void imprimeVetor(int *vetor, int tamanho){
    int i;
    printf("Elementos digitados: \n");
     for(i = 0; i < 5; i++)   // imprime o vetor
        printf("%d ", veto[i]);

}
void MaiorMenor(int *vetor, int tamanho){
    int i,maior =vetor[0],menor=[0];
    for(i=1;i<tamanho; i++){
        if(vetor[i]>maior){
        maior=vetor[i]
        }
        if(vetor[i]<menor){
            menor =vetor[i];
        }
    }
    printf("menor numero: %d",menor);
    printf("Meaior numerp :%d",maior);
}