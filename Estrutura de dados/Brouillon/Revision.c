#include<stdio.h>

int main(){
    const int bimestresAnnuais =4;
    const int numeroAlunos =4;

    float notasAlunos[bimestresAnnuais][numeroAlunos] = {0};
    float mediaAlunos [numeroAlunos] = {0};

    float media = 0;

    printf("Inserir as notas dos 4 alunos: ");

    for( int alunos=0; alunos<numeroAlunos; alunos++ ){
        for(int notas=0; notas< bimestresAnnuais; notas ++){
            scanf("%f", &notasAlunos[alunos][notas]);
            
        }
    }
}