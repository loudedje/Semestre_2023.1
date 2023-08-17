#include<stdio.h>
#include<stdlib.h>

struct no
{
    int num;
    struct no *prox;
};
typedef no No;
 
No* criar_no(){
    No* novo=(No*)malloc(sizeof(No));
    return novo;
}
No* inserir_Inicio(No* lista, int num){
    No* inserir_No=criar_no;
    inserir_No->num= num;
    if(lista==NULL){
        lista=inserir_No;
        inserir_No->prox=NULL;
    }else{
        novo->prox=lista;
        lista=inserir_No; 
    }
    return lista;
}


void imprimir(No* Lista){
    No *aux=lista;

    while(aux!=NULL){
        printf("%d",aux->num);
        aux=aux->prox;
    }
}


int main(){
    No *lista=NULL;
   lista = inserir_Inicio(lista,10);
   imprimir(lista);

}
