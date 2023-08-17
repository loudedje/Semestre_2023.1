#include<stdio.h>
int main(){
    int num1, num2, soma=0, i=1;

    printf("Informe o primeiro: ");
    scanf("%d", &num1);
    printf("Informe o segundo: ");
    scanf("%d", &num2);
    while (i<=num2){
        soma += num1;
        //0= 0+3
        if(i<num2){
            printf("%d + ", num1);
        }
        else{
            printf("%d ", num1);
            i+=1;
            printf("= %d",soma);
        }
        i += 1; 
    }
}
