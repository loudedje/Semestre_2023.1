#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//# define  TAM_NOME 20

struct funcionario{
    int id;
    char nome[30];
    double salario;
    struct funcionario *next;
};
typedef struct funcionario Funcionario;

int main(){
    Funcionario *head = (Funcionario *)malloc(sizeof(Funcionario));
    head->next=NULL;
    Funcionario *first;
   first=(Funcionario*)malloc(sizeof(Funcionario));
    first->id=1;;
    //first->id;
    strcpy(first->nome, "Djema");
    first->salario= 3000;
    first->next=NULL;

    if(head->next==NULL){
        printf("Lista está vazia!");
    }
    else{
        printf("Lista com Elemento.");
    }


   
        Funcionario *aux= head;
        int count=0;
        
        while(aux->next !=NULL){
            int count++;
            aux=aux->next;
        }
        printf("Numero de itens na lista %d\n",count);
         
    
    






}