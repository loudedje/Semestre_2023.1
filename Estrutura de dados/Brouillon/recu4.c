#include <stdio.h>

int mim(int vet[], int tamanho) {
    int menor = vet[0]; 
    if(tamanho==1){ // com base 1
        return vet[0];
    }
    
    
    else{
        //int menor = vet[0]; 
        for (int i = 0; i < tamanho; i++) { //função recu
         if (vet[i] < menor) {
            menor = vet[i];
        }
    }
    return menor;
}
}

int main() {
    int vet[3] = {1, 5, 3};
    int tamanho = 3;
    int resultado = mim(vet, tamanho);
    printf("O menor elemento é %d", resultado);
    return 0;
}
