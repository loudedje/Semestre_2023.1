/**
 * @file 03Tries.c
 * @brief Arquivo template para Questão 03 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma estrutura de Trie para armazenar chaves em formato de
 * caractere. Inclua operações de inserção, remoção e busca completa e busca
 * parcial na estrutura do Trie.
 *      Para a busca completa, o algoritmo deve apenas informar se a chave foi
 * encontrada ou não dentro da estrutura. Para a busca parcial, o algoritmo deve
 * retornar todas as chaves armazenadas abaixo da string informada para a busca.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_ARRAY(a) sizeof(a) / sizeof(a[0])
#define TAMANHO_ALFABETO 26
#define CHAR_PARA_INDICE(c) ((int)c - (int)'a')

// Estrutura de um nó da trie
struct NoTrie {
    struct NoTrie *filhos[TAMANHO_ALFABETO];
    bool isEndOfWord;
};

typedef struct NoTrie No;

No *criarNo() {
    No *temp = (No *)malloc(sizeof(No));
    if (temp) {
        temp->isEndOfWord = false;
        for (int i = 0; i < TAMANHO_ALFABETO; i++)
            temp->filhos[i] = NULL;
    }
    return temp;
}

void inserir(No *raiz, char *palavra) {
    int indice;
    No *atual = raiz;
    for (int i = 0; i < strlen(palavra); i++) {
        indice = CHAR_PARA_INDICE(palavra[i]);
        if (!atual->filhos[indice])
            atual->filhos[indice] = criarNo();
        atual = atual->filhos[indice];
    }
    atual->isEndOfWord = true;
}

bool buscar(No *raiz, char *palavra) {
    int indice;
    No *atual = raiz;
    for (int i = 0; i < strlen(palavra); i++) {
        indice = CHAR_PARA_INDICE(palavra[i]);
        if (!atual->filhos[indice])
            return false;
        atual = atual->filhos[indice];
    }
    return atual != NULL && atual->isEndOfWord;
}

bool temFilhos(No *atual) {
    for (int i = 0; i < TAMANHO_ALFABETO; i++)
        if (atual->filhos[i])
            return true;
    return false;
}

bool excluir(No *atual, char *str) {
    if (atual == NULL)
        return false;

    if (*str) {
        if (atual != NULL && atual->filhos[CHAR_PARA_INDICE(*str)] != NULL &&
            excluir(atual->filhos[CHAR_PARA_INDICE(*str)], str + 1) &&
            atual->isEndOfWord == 0) {
            if (!temFilhos(atual)) {
                free(atual);
                atual = NULL;
                return true;
            } else {
                return false;
            }
        }
    }
    if (*str == '\0' && atual->isEndOfWord) {
        if (!temFilhos(atual)) {
            free(atual);
            atual = NULL;
            return true;
        } else {
            atual->isEndOfWord = false;
            return false;
        }
    }
    return false;
}

void percorrerUtil(No *raiz, char buffer[], int profundidade) {
    if (raiz->isEndOfWord) {
        buffer[profundidade] = '\0';
        printf("%s\n", buffer);
    }
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (raiz->filhos[i]) {
            buffer[profundidade] = i + 'a';
            percorrerUtil(raiz->filhos[i], buffer, profundidade + 1);
        }
    }
}

void percorrerTrie(No *raiz) {
    char buffer[50]; // Aumentei o tamanho do buffer
    percorrerUtil(raiz, buffer, 0);
}

void buscaParcialUtil(No *raiz, char *prefixo, char buffer[], int profundidade) {
    if (raiz->isEndOfWord) {
        buffer[profundidade] = '\0';
        printf("%s%s\n", prefixo, buffer);
    }
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (raiz->filhos[i]) {
            buffer[profundidade] = i + 'a';
            buscaParcialUtil(raiz->filhos[i], prefixo, buffer, profundidade + 1);
        }
    }
}

void buscaParcial(No *raiz, char *prefixo) {
    No *atual = raiz;
    int indice;
    char buffer[50]; // Aumentei o tamanho do buffer

    // Navega até o último caractere do prefixo
    for (int i = 0; i < strlen(prefixo); i++) {
        indice = CHAR_PARA_INDICE(prefixo[i]);
        if (!atual->filhos[indice])
            return;
        atual = atual->filhos[indice];
    }

    // Realiza a busca parcial a partir do nó atual
    buscaParcialUtil(atual, prefixo, buffer, 0);
}

int main() {
    char palavras[][20] = {"amy", "ann", "emma", "rob", "roger", "robert", "bob", "emmily"};

    No *raiz = criarNo();

    // Construir trie
    for (int i = 0; i < TAMANHO_ARRAY(palavras); i++)
        inserir(raiz, palavras[i]);

    printf("\nPalavras na trie:\n");
    percorrerTrie(raiz);


    // Busca parcial
    printf("\nBusca parcial com palavra commeça com  ro:\n");
    buscaParcial(raiz, "ro");
    printf("\nBusca parcial com palavra commeça com  em:\n");
    buscaParcial(raiz, "em");
    
    
    excluir(raiz, "rob");

    printf("\n\nNova trie :\n");
    percorrerTrie(raiz);

    return 0;
}
