/**
 * @file 02Hash.c
 * @author Nome_do_Aluno Loude Djema Sime
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Questão 02 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma tabela hash contendo 13 posições. O índice das chaves
 *  deve ser gerado utilizando a fórmula k mod M, onde k é a chave e M a
 *  quantidade de chaves. Resolva as colisões utilizando uma Lista Encadeada.
 *  Inclua operações de inserção, remoção e busca da chave nesta tabela hash,
 *  informando se a chave foi encontrada ou não.  Atenção: os elementos da
 *  lista encadeada não precisam estar ordenados/em ordem.
 *
 *      Utilize os vetores comentados no código para realizar seus testes.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 13

typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct {
    Elemento *tab[TAMANHO];
} TabelaHash;

// Função para calcular o hash
int calculaHash(int valor) {
    return valor % TAMANHO;
}

// Inicializa a tabela hash
void inicializaTabelaHash(TabelaHash *th) {
    for (int i = 0; i < TAMANHO; i++) {
        th->tab[i] = NULL;
    }
}

// Insere um elemento na tabela hash
void insereTabelaHash(TabelaHash *th, int valor) {
    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->proximo = NULL;
    int posicao = calculaHash(valor);

    if (th->tab[posicao] == NULL) { // Posição ainda vazia
        th->tab[posicao] = novo;
    } else { // Já há elementos vinculados à posição
        Elemento *aux = th->tab[posicao];
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo; // Insere ao final
    }
}

// Busca uma chave na tabela hash
void busca(TabelaHash *th, int chave) {
    int posicao = calculaHash(chave);
    if (th->tab[posicao] == NULL) {
        printf("\nChave de busca %d nao encontrada", chave); // Nenhum elemento vinculado à posição
    } else {
        Elemento *aux;
        for (aux = th->tab[posicao]; aux != NULL; aux = aux->proximo) {
            if (chave == aux->valor) {
                printf("\nChave de busca %d encontrada", chave);
                return;
            }
        }
        printf("\nChave de busca %d nao encontrada", chave); // Percorreu todos os vinculados à posição e não encontrou
    }
}

// Remove um elemento da tabela hash
void removeElemento(TabelaHash *th, int chave) {
    int posicao = calculaHash(chave);
    if (th->tab[posicao] == NULL) {
        printf("\nChave de busca %d nao encontrada", chave);
    } else {
        Elemento *aux, *anterior = NULL;
        for (aux = th->tab[posicao]; aux != NULL; aux = aux->proximo) {
            if (aux->valor == chave) {
                if (anterior == NULL) { // Verifica se é o primeiro
                    th->tab[posicao] = th->tab[posicao]->proximo; // Atualiza vetor com o novo primeiro
                } else {
                    anterior->proximo = aux->proximo; // Anterior aponta para o próximo de aux
                }
                free(aux); // Apaga o aux
                return;
            }
            anterior = aux; // Controla o anterior
        }
        printf("\nChave de busca %d nao encontrada", chave); // Percorreu todos os vinculados à posição e não encontrou
    }
}

// Função para imprimir a tabela hash
void imprimir(TabelaHash *th) {
    printf("TABELA HASH:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("[%d]: ", i);
        Elemento *aux = th->tab[i];
        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n");
    }
}

int main() {
    TabelaHash th;
    inicializaTabelaHash(&th);

    int chaves1[] = {7, 13, 33, 12, 5, 1, 0};
    int chaves2[] = {5, 6, 9, 19, 24, 32, 41, 42, 43, 58};
    int chaves3[] = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};
    int num_chaves1 = sizeof(chaves1) / sizeof(chaves1[0]);
    //int num_chaves2 = sizeof(chaves2) / sizeof(chaves2[0]);
    //int num_chaves3 = sizeof(chaves3) / sizeof(chaves3[0]);

    // Inserção dos elementos
    for (int i = 0; i < num_chaves1; i++) {
        insereTabelaHash(&th, chaves1[i]);
    }

    // Impressão da tabela hash
    printf("Tabela chave 2");
    imprimir(&th);

    // Busca de uma chave
    int busca_chave = 12;
    busca(&th, busca_chave);

    // Remoção de uma chave
    int remove_chave = 33;
    removeElemento(&th, remove_chave);
    printf("Elemento %d removido da tabela hash.\n", remove_chave);

    // Impressão da tabela hash atualizada
    printf("\nTabela atualizada \n");
    printf("\n\n");
    imprimir(&th);
   
   
   int num_chaves2 = sizeof(chaves2) / sizeof(chaves2[0]);
    for (int i = 0; i < num_chaves2; i++) {
        insereTabelaHash(&th, chaves2[i]);
    }
    printf("\n\n");
   // printf("Djema");
    // Impressão da tabela hash
    imprimir(&th);

    // Busca de uma chave
    int key = 32;
    busca(&th,key);

    // Remoção de uma chave
    int remove_key = 58;
    removeElemento(&th, remove_key);
    printf("Elemento %d removido da tabela hash.\n", remove_key);

    // Impressão da tabela hash atualizada
    printf("\nTabela atualizada\n");
    printf("\n\n");
    imprimir(&th);
   
   int num_chaves3 = sizeof(chaves3) / sizeof(chaves3[0]);
    for (int i = 0; i < num_chaves3; i++) {
        insereTabelaHash(&th, chaves3[i]);
    }
    printf("\n\n");
   // printf("Djema");
    // Impressão da tabela hash
    imprimir(&th);

    // Busca de uma chave
    int clef = 178;
    busca(&th,clef);

    // Remoção de uma chave
    int remove_k = 356;
    removeElemento(&th, remove_k);
    printf("Elemento %d removido da tabela hash.\n", remove_key);

    // Impressão da tabela hash atualizada
    printf("\nTabela atualizada\n");
    printf("\n\n");
    imprimir(&th);
   
   
    return 0;
    
}