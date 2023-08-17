#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no* prox;
} No;

typedef struct Fila {
    No* ini;
    No* fim;
} Fila;

void enfileira(int dado, Fila* f) {
    No* ptr = (No*)malloc(sizeof(No));
    if (ptr == NULL) {
        printf("Erro de alocação\n");
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = NULL;
        if (f->ini == NULL) {
            f->ini = ptr;
        } else {
            f->fim->prox = ptr;
        }
        f->fim = ptr;
    }
}

int desenfileira(Fila* f) {
    No* ptr = f->ini;
    int dado;
    if (ptr != NULL) {
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if (f->ini == NULL) {
            f->fim = NULL;
        }
        return dado;
    } else {
        printf("Fila vazia\n");
        return -1;
    }
}

void imprimirFila(Fila* f) {
    No* ptr = f->ini;
    if (ptr != NULL) {
        while (ptr != NULL) {
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    } else {
        printf("Fila Vazia!\n");
    }
}

int main() {
    Fila *f;
    f = (Fila*)malloc(sizeof(Fila));

    enfileira(10, f);
    enfileira(20, f);
    enfileira(40, f);
    enfileira(29,f);
    imprimirFila(f);
    desenfileira(f);
    imprimirFila(f);

    return 0;
}
