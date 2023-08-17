/**
 * @file 03Tries.c
 * @author Nome_do_Aluno
 * @version 0.1
 * @date 2023-06-10
 *
 * @brief Arquivo template para Questão 03 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma estrutura de Trie para armazenar chaves em formato de
 * caractere. Inclua operações de inserção, remoção e busca completa e busca
 * parcial na estrutura do Trie.
 *      Para a busca completa, o algoritmo deve apenas informar se a chave foi
 * encontrada ou não dentro da estrutura. Para a busca parcial, o algoritmo deve
 * retornar todas as chaves armazenadas abaixo da string informada para a busca.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO 26

// Estrutura de um nó da Trie
typedef struct No {
    struct No* filhos[TAMANHO];
    bool ehFolha;
} No;

// Função para criar um novo nó da Trie
No* criarNo() {
    No* no = (No*)malloc(sizeof(No));
    if (no != NULL) {
        no->ehFolha = false;
        for (int i = 0; i < TAMANHO; i++) {
            no->filhos[i] = NULL;
        }
    }
    return no;
}

// Função para inserir uma chave na Trie
void inserir(No* raiz, const char* chave) {
    int tamanho = strlen(chave);
    No* no = raiz;
    for (int i = 0; i < tamanho; i++) {
        int indice = chave[i] - 'a';
        if (no->filhos[indice] == NULL) {
            no->filhos[indice] = criarNo();
        }
        no = no->filhos[indice];
    }
    no->ehFolha = true;
}

// Função para buscar uma chave completa na Trie
bool buscarCompleto(No* raiz, const char* chave) {
    int tamanho = strlen(chave);
    No* no = raiz;
    for (int i = 0; i < tamanho; i++) {
        int indice = chave[i] - 'a';
        if (no->filhos[indice] == NULL) {
            return false;
        }
        no = no->filhos[indice];
    }
    return (no != NULL && no->ehFolha);
}

// Função para imprimir todas as chaves abaixo de um nó
void imprimirChaves(No* no, char* prefixo, int nivel) {
    if (no->ehFolha) {
        prefixo[nivel] = '\0';
        printf("%s\n", prefixo);
    }

    for (int i = 0; i < TAMANHO; i++) {
        if (no->filhos[i] != NULL) {
            prefixo[nivel] = i + 'a';
            imprimirChaves(no->filhos[i], prefixo, nivel + 1);
        }
    }
}

// Função para buscar chaves parciais na Trie
void buscarParcial(No* raiz, const char* prefixo) {
    int tamanho = strlen(prefixo);
    No* no = raiz;
    for (int i = 0; i < tamanho; i++) {
        int indice = prefixo[i] - 'a';
        if (no->filhos[indice] == NULL) {
            printf("Nenhuma chave encontrada com o prefixo '%s'\n", prefixo);
            return;
        }
        no = no->filhos[indice];
    }
    imprimirChaves(no, (char*)prefixo, tamanho);
}

int main() {
    No* raiz = criarNo();
    char chaves[][20] = {"amy", "ann", "emma", "rob" , "roger", "robert", "bob", "emmily"};
    int quantidadeChaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < quantidadeChaves; i++) {
        inserir(raiz, chaves[i]);
    }

    printf("Chaves inseridas:\n");
    for (int i = 0; i < quantidadeChaves; i++) {
        printf("%s\n", chaves[i]);
    }

    printf("\nBusca completa:\n");
    printf("amy: %s\n", buscarCompleto(raiz, "amy") ? "Encontrado" : "Não encontrado");
    printf("john: %s\n", buscarCompleto(raiz, "john") ? "Encontrado" : "Não encontrado");

    printf("\nBusca parcial:\n");
    buscarParcial(raiz, "em");
    buscarParcial(raiz, "ro");

    return 0;
}
