#include<stdio.h>

int main(){
    
int matriz[3][3];
int soma=0;

for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        printf("Entrar os elementos da matriz [%d][%d]: ",i,j);
        scanf("%d", &matriz[i][j]);
        soma=soma+matriz[i][j];
        
    }
    
}
printf("A soma da matriz é %d ", soma);

return 0;
}