#include <stdio.h>
#include <stdlib.h>

// Função recursiva
int buscaBinaria(int vet[], int chave, int fim, int ini) {
    int meio;
    if (ini <= fim) {
        meio = (ini + fim) / 2;
        if (chave == vet[meio]) {
            return meio;
        } else {
            if (chave < vet[meio]) {
                return buscaBinaria(vet, chave, meio - 1, ini);
            } else {
                return buscaBinaria(vet, chave, fim, meio + 1);
            }
        }
    }
    return -1;
}

// Função Iterativa
int buscaBinariaIterativa(int vet[], int chave, int fim) {
    int ini = 0;
    int meio;
    
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (chave == vet[meio]) {
            return meio;
        } else {
            if (chave < vet[meio]) {
                fim = meio - 1;
            } else {
                ini = meio + 1;
            }
        }
    }
    return -1;
}

int main() {
    int vet[10] = {1, 3, 5, 6, 7, 8, 9, 12, 34, 44};
    int valor = 7;
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    int resultado = buscaBinaria(vet, valor, tamanho - 1, 0);
    if (resultado != -1) {
        printf("O valor buscado está na posição %d.\n", resultado);
    } else {
        printf("O valor buscado não foi encontrado.\n");
    }
    
    int chave = 5;
    int resultado1 = buscaBinariaIterativa(vet, chave, tamanho - 1);
    if (resultado1 != -1) {
        printf("A chave buscada está na posição %d.\n", resultado1);
    } else {
        printf("A chave buscada não foi encontrada.\n");
    }

    return 0;
}
