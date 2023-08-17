#include <stdio.h>
#include <string.h>

int carateres(char *a){
    return strlen(a);
}

int main(){
    char nome[100];
    int ca;

    printf("Digite um nome: ");
    scanf("%s", nome);

    ca = carateres(nome);
    printf("O nome tem %d caracteres\n", ca);

    return 0;
}
