#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1

typedef struct {
    int day, month, year;
} date;

struct aluno {
    char matricula[10];
    char nome[20];
    date birth;
    float nota;
    struct aluno *next;
};
typedef struct aluno Aluno;

Aluno* incluirElemento(Aluno *head) {
    int day, month, year;

    Aluno *new = (Aluno *) malloc(sizeof(Aluno));
    
    scanf("%s", new->matricula);
    scanf("%s", new->nome);
    scanf("%d/%d/%d", &day, &month, &year);
    new->birth.day = day;
    new->birth.month = month;
    new->birth.year = year;
    scanf("%f", &new->nota);
    
    new->next = head;
    return new;
}

Aluno* DeleteElemento(Aluno* first, char matricula[]) {
    Aluno *aux = first, *previous = NULL;
    while (aux != NULL) {
        if (strcmp(aux->matricula, matricula) == 0) {
            if (aux == first) {
                first = first->next;
                free(aux);
            } else {
                previous->next = aux->next;
                free(aux);
            }
            break;
        }
        previous = aux;
        aux = aux->next;
    }
    return first;
}

void ImprimirInOrdem(Aluno *first) {
    Aluno *aux;
    for (aux = first; aux != NULL; aux = aux->next) {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->birth.day, aux->birth.month, aux->birth.year, aux->nota);
    }
}

void imprimeDecrescente(Aluno *first) {
    if (first == NULL) {
        return;
    }
    imprimeDecrescente(first->next);
    printf("%s, %s, %d/%d/%d, %.2f\n", first->matricula, first->nome, first->birth.day, first->birth.month, first->birth.year, first->nota);
}

int countElements(Aluno *first) {
    int count = 0;
    while (first != NULL) {
        count++;
        first = first->next;
    }
    return count;
}

void Exit(Aluno *first) {
    Aluno *aux;
    while (first != NULL) {
        aux = first->next;
        free(first);
        first = aux;
    }
}

int counMatricula(Aluno *first, const char matricula[10]){
    Aluno *aux;
    int count = 0;
    for(aux = first; aux != NULL; aux = aux->next){
        if(strcmp(aux->matricula, matricula) == 0)
            count++;
    }
    return count;
}

Aluno *New(Aluno *first, Aluno *aux){
    if(first != NULL)
        aux = first;
    while (aux != NULL)
    {
        if(aux->next == NULL)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

int main() {
    int option;
    char matricula[10];

    Aluno *first = NULL;
    Aluno *aux = NULL;

    for (;;) {
        scanf("%d", &option);

        switch (option) {
            case 0:
                Exit(first);
                printf("\nMemória desalocada.\n");
                return 0;
                break;
            case 1:
                first = incluirElemento(first);
                printf("Elemento incluído.\n");
                break;

            case 2:
                if (!countElements(first)) {
                    printf("Lista vazia\n");
                } else {
                    printf("Digite a matrícula do aluno a ser deletado: ");
                    scanf("%s", matricula);
                    for(int i = counMatricula(first, matricula); i > 0; i--){
                        first = DeleteElemento(first, matricula);
                        aux = New(first, aux);
                    }
                }
                break;

            case 3:
                if (!countElements(first)) {
                    printf("Lista vazia\n");
                } else {
                    printf("Imprimindo em ordem crescente:\n");
                    ImprimirInOrdem(first);
                }
                break;

            case 4:
                if (!countElements(first)) {
                    printf("Lista vazia\n");
                } else {
                    printf("Imprimindo em ordem decrescente:\n");
                    imprimeDecrescente(first);
                }
                break;

            case 5:
                if 
                {
                    printf("Lista Vazia\n");
                    }(countElements(first)) {

                } else {
                    printf("Lista Vazia\n");
                }
                break;
        } 
    }
    return 0;
}
