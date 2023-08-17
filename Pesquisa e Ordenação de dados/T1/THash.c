#include<stdio.h>

#define M=10;

typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;


int main(){
    int a;
    printf("Entrar a chave: ");
    scanf("%d", &a);
    GerarAChave(a);
}

void inicializaTabelaHash(TabelaHash *th) {
    for(int i = 0; i < M; i++){
        th->tab[i] = NULL;
    }
}

void GerarAChave(int chave){
    return chave % M;
}
//implementar função hash





//criar vetor armazenado os itens
//tratar colisões em lista encadeada




