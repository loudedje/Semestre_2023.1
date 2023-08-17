#include<stdio.h>
#include<string.h>

typedef struct {
    char nome[100];
    int idade;
    float nota;
    int turma;
}Aluno;

int main(){
    Aluno Aluno;
    printf("Digite o nome do Aluno: ");
    scanf("%s", &Aluno.nome);
    printf("Digite a idade do Aluno: ");
    scanf("%d", &Aluno.idade);
    printf("Digite a nota do aluno: ");
    scanf("%f", &Aluno.nota);
    printf("Digite a turma: ");
    scanf("%d", &Aluno.turma);
    
    printf("O nome: %s\nIdade: %d\nNota: %f\nTurma: %d\n",Aluno.nome,Aluno.idade,Aluno.nota,Aluno.turma);
    return 0;
}