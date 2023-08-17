#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //FILE* fopen(char* Arquivo, char* modo)
    FILE *fp;
    int c;
    fp = fopen("Arquivo.txt", "r");
        if (fp == NULL) {
            printf("Erro na abertura do arquivo1!");
            exit(1); // aborta o programa
        }
        while(!feof(fp)) {
            c = fgetc(fp);
            printf("%c", c);
        }
    return 0;
}


