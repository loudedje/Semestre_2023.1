#include<stdio.h>
int main(){
    int Vetor[5];
    int i;

for(i=0; i<5; i++){// lendo os valores no teclado 
   // int val;
    printf("Entrar o valor  na posição %d: ", i);
    scanf("%d", &Vetor[i]);
    //Vetor[i]=val;
    
}
printf("\n\n");
for(i=0; i<5; i++){
    //Imprime o vetor
printf("O valore na posição %d que foi digitado: %d\n",i, Vetor[i]);

}

}