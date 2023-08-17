#include "Data.h"
#include<stdio.h>
int comparar(Data O_data, Data s_data){
    if (O_data.dia == s_data.dia && O_data.mes == s_data.mes){
        printf("0");
        //return 0;
    }
    else if(O_data.dia>s_data.dia && O_data.mes>s_data.mes){
        printf("1");
        //return 1;
    }
    else {
        printf("-1");
        //return -1;
    }
}
// Data d, o d é o variavel do tipo Data
int  extraiData(Data d) {
    return d.dia;
   
   // printf("Mês %d\n", data.mes);
}
