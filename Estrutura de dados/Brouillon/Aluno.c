#include<stdio.h>

int main(){
    double notas[2][3];
    double medias[2]
    //Entrada
    for( int i=0; i<2; i++){
        printf("Digite a nota do %d aluno\n", i+1);//Linhas
        for(int j=0; j<3; j++){
            printf("Entrar as notas dos alunos: ");//Colunas
            scanf("%lf", &notas[i][j]);
        }
    }
   // printf("As notas dos alunos é ", notas[i][j]);
   for (i=0;i<2;i++)
   media[i]=calculaMedia(notas[i][j]);
   double maior =medias[0];            
            if(media[0]>media[1])
            {   
             printf("A media do primeiro estudante é maior\n");
            }
            else
            printf("A media do segundo é maior\n");
    double calculaMedia(double*notas, int quantidades){
        int i:
        double soma = 0.0;
        for(i=o;i<quantidade; i++){
            soma= soma+notas[i];
            return soma/(double) quantidade;
        }
    }
   return 0;
}


    