#include <stdio.h>

int main() {
    float salario = 0;
    int numFilho = 0;
    int i = 0;
    float total_salario = 0;
    int total_filho = 0;
    
    while (1) { 
        printf("Informe o Salario (ou -1 para sair): ");
        scanf("%f", &salario);
        if (salario == -1) {
            break; 
        }
        printf("Informe a quantidade de filhos: ");
        scanf("%d", &numFilho);
        
        total_salario += salario; 
        total_filho += numFilho;
        
        i++; 
           }
    
    if (i > 0) { 
        float media_salario = total_salario / i; 
        float media_filho = (float)total_filho / i;
        
        printf("A media dos Salarios é:  %.2f\n", media_salario);
        printf("A media dos Filhos é:  %.1f\n", media_filho);
    }
    
    return 0;
}
