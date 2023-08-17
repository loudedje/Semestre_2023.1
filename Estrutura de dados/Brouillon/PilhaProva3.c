#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

void CriarPilha(Pilha *p) {
    p->topo = NULL;
}

void empilhar(int dado, Pilha *p) {
    No *ptr;
    ptr = (No*)malloc(sizeof(No));
    if (ptr != NULL) {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;

    } else {
        printf("Erro de alocação");
        return;
    }
}

int desempilhar(Pilha *p) {
    No *ptr = p->topo;
    int dado;
    if (ptr == NULL) {
        printf("Pilha Vazia");
    } else {
        p->topo = ptr->prox;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
    return -1; // Retornar um valor padrão em caso de erro
}

void imprimirPilha(Pilha *p) {
    No *ptr = p->topo;
    if (ptr == NULL) {
        printf("Pilha Vazia");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
    }
}

int main() {
    Pilha *p1 = (Pilha*)malloc(sizeof(Pilha));
    if (p1 == NULL) {
        printf("Erro de alocação");
    } else {
        CriarPilha(p1);
        empilhar(10, p1);
        empilhar(30, p1);
        empilhar(16, p1);
        imprimirPilha(p1);
        printf("\n\n");
        printf("desempilhar\n");
         desempilhar(p1);
         desempilhar(p1);
         desempilhar(p1);
        imprimirPilha(p1);
    }

    return 0;
}
