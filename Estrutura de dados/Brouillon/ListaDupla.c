#include <stdio.h>
#include <stdlib.h>

struct item {
    int id;
    struct item *anterior;
    struct item *ultimo;
};

typedef struct item Item;


Item *setItem(int id)
{
    Item *novo = (Item *) malloc(sizeof(Item));
    novo->id = id;
    novo->anterior = NULL;
    novo->ultimo = NULL;
    return novo;
}

int listaVazia(Item *head)
{
    if (head == NULL) {
        printf("Lista vazia!");
        return 1;
    } else {
        return 0;
    }
}

void imprimeLista(Item *head)
{
    Item *temp = head;
    while (temp != NULL) {
        printf(" %d ", temp->id);
        temp = temp->ultimo;
    }
    printf("\n\n");
}
Item* encontraPosicao(Item *lista, int id){
  for (Item *aux = lista->anterior; aux != NULL; aux = aux->ultimo){ 
    if(id > 0){ 
      return aux; 
    }
  }
  return NULL; 
}

void inserirElemento(Item *lista, Item *novo)
{
    Item *elemento = lista;
    if (elemento != NULL) { //
        if (elemento == lista) {
             novo->ultimo = elemento;
            elemento->anterior = novo;
            lista = novo;
        } else { //no meio 
            novo->ultimo = elemento;
            novo->anterior = elemento->anterior;
            elemento->anterior->ultimo = novo;
            elemento->anterior = novo;
        }
    } else { // não encontrou posição de inserção no meio da lista, então insere no fim
        if (lista == NULL) {
            lista = novo;
        } else {
            Item ultimo = lista;
            while (ultimo->ultimo != NULL) {
                ultimo = ultimo->ultimo;
            }
            novo->anterior = ultimo;
            ultimo->ultimo = novo;
        }
    }
}

