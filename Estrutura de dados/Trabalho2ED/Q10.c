#include <stdio.h>

int main() {
    float media, nota, soma;
    int matricula, count_alunos;
    
    soma = count_alunos = 0; 
    
    while (1) {
        printf("Digite a matrícula do aluno (ou 0 para sair da programar): ");
        scanf("%d", &matricula);
        if (matricula == 0) {
            break;  
        }
        soma = 0;  
        for (int i = 1; i <= 10; i++) {
            printf("Digite a nota %d do aluno %d: ", i, matricula);
            scanf("%f", &nota);
            soma += nota;
        }
        media = soma / 10;
        printf("Média do aluno %d: %.2f\n", matricula, media);
        soma += media;  
        count_alunos++; 
    }
    
    if (count_alunos > 0) {  
        float media_geral = soma / count_alunos;
        printf("Média geral da turma: %.2f\n", media_geral);
    }
    
    return 0;
}
