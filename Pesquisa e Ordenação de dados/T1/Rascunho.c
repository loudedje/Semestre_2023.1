#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALFABETO_SIZE 26

// Estrutura de Nó da Trie
struct TrieNode {
    struct TrieNode* children[ALFABETO_SIZE];
    bool isEndOfWord;
};

// Função para criar um novo nó da Trie
struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;

    for (int i = 0; i < ALFABETO_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

// Função para inserir uma palavra na Trie
void insertWord(struct TrieNode* root, const char* word) {
    struct TrieNode* currentNode = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (currentNode->children[index] == NULL) {
            currentNode->children[index] = createNode();
        }

        currentNode = currentNode->children[index];
    }

    currentNode->isEndOfWord = true;
}

// Função para buscar uma palavra completa na Trie
bool searchWord(struct TrieNode* root, const char* word) {
    struct TrieNode* currentNode = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (currentNode->children[index] == NULL) {
            return false;
        }

        currentNode = currentNode->children[index];
    }

    return currentNode != NULL && currentNode->isEndOfWord;
}

// Função para buscar palavras parciais na Trie
void searchPartial(struct TrieNode* root, const char* prefix) {
    struct TrieNode* currentNode = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (currentNode->children[index] == NULL) {
            printf("Nenhum resultado encontrado.\n");
            return;
        }

        currentNode = currentNode->children[index];
    }

    printWords(currentNode, prefix);
}

// Função auxiliar para imprimir todas as palavras abaixo de um nó
void printWords(struct TrieNode* node, char* prefix) {
    if (node->isEndOfWord) {
        printf("%s\n", prefix);
    }

    for (int i = 0; i < ALFABETO_SIZE; i++) {
        if (node->children[i] != NULL) {
            char* newPrefix = (char*)malloc((strlen(prefix) + 2) * sizeof(char));
            strcpy(newPrefix, prefix);
            newPrefix[strlen(prefix)] = i + 'a';
            newPrefix[strlen(prefix) + 1] = '\0';
            printWords(node->children[i], newPrefix);
            free(newPrefix);
        }
    }
}

int main() {
    struct TrieNode* root = createNode();

    // Inserindo palavras na Trie
    char chaves[][20] = {"amy", "ann", "emma", "rob", "roger", "robert", "bob", "emmily"};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < numChaves; i++) {
        insertWord(root, chaves[i]);
    }

    // Exemplo de busca de palavras completas
    printf("Busca completa:\n");
    printf("amy: %s\n", searchWord(root, "amy") ? "Encontrada" : "Não encontrada");
    printf("anna: %s\n", searchWord(root, "anna") ? "Encontrada" : "Não encontrada");
    printf("robert: %s\n", searchWord(root, "robert") ? "Encontrada" : "Não encontrada");
    printf("john: %s\n", searchWord(root, "john") ? "Encontrada" : "Não encontrada");

    // Exemplo de busca de palavras parciais
    printf("\nBusca parcial (prefixo 'ro'):\n");
    searchPartial(root, "ro");

    return 0;
}
