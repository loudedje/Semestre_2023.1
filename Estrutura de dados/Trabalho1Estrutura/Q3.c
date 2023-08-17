#include<stdio.h>
int main(){
    int horaIn, horaFim;
    int resulHora;
    printf("Entrar a hora de inicio: ");
    scanf("%d",&horaIn);
    printf("Entrar a hora do Fim: ");
    scanf("%d",&horaFim);
    resulHora = horaIn + horaFim;
    if(horaIn<=horaFim){
        resulHora=horaFim-horaIn;
    }
    else{
        resulHora=24-horaIn+horaFim;
    }
    printf("A duração em Hora é %d horas.",resulHora);
    
    return 0;
    }

