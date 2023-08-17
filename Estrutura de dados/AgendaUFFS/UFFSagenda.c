#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"UFFSagenda.h"

// Função para criar um novo evento
Evento* criarEvento(int codigo, Data data, float duracao, char descricao[100]) {
   Evento* novoEvento = (Evento*)malloc(sizeof(Evento));
   novoEvento->codigo = codigo;
   novoEvento->dataEvento = data;
   novoEvento->duracao = duracao;
   strcpy(novoEvento->descricao, descricao);
   novoEvento->esquerda = NULL;
   novoEvento->direita = NULL;
   return novoEvento;
}


// Função para incluir um evento na agenda
Evento* incluirEvento(Evento* raiz, Evento* novoEvento) {
   if (raiz == NULL) {
      return novoEvento;
   }

   if (novoEvento->dataEvento.ano < raiz->dataEvento.ano ||
       (novoEvento->dataEvento.ano == raiz->dataEvento.ano && novoEvento->dataEvento.mes < raiz->dataEvento.mes) ||
       (novoEvento->dataEvento.ano == raiz->dataEvento.ano && novoEvento->dataEvento.mes == raiz->dataEvento.mes &&
        novoEvento->dataEvento.dia < raiz->dataEvento.dia) ||
       (novoEvento->dataEvento.ano == raiz->dataEvento.ano && novoEvento->dataEvento.mes == raiz->dataEvento.mes &&
        novoEvento->dataEvento.dia == raiz->dataEvento.dia && novoEvento->dataEvento.hora < raiz->dataEvento.hora) ||
       (novoEvento->dataEvento.ano == raiz->dataEvento.ano && novoEvento->dataEvento.mes == raiz->dataEvento.mes &&
        novoEvento->dataEvento.dia == raiz->dataEvento.dia && novoEvento->dataEvento.hora == raiz->dataEvento.hora &&
        novoEvento->dataEvento.minuto < raiz->dataEvento.minuto)) {
      raiz->esquerda = incluirEvento(raiz->esquerda, novoEvento);
   } else if (novoEvento->dataEvento.ano == raiz->dataEvento.ano && novoEvento->dataEvento.mes == raiz->dataEvento.mes &&
              novoEvento->dataEvento.dia == raiz->dataEvento.dia && novoEvento->dataEvento.hora == raiz->dataEvento.hora &&
              novoEvento->dataEvento.minuto == raiz->dataEvento.minuto) {
      printf("Horário já ocupado por outro evento.\n");
      // Aqui você pode decidir como lidar com o conflito de horários, como pedir para o usuário escolher outro horário.
      //um erro"só que está aparece a mensagem de incluindo"
   } else {
      raiz->direita = incluirEvento(raiz->direita, novoEvento);
   }

   return raiz;
}

// Função para buscar um evento na agenda por data
Evento* buscarEventoPorData(Evento* raiz, Data data) {
   if (raiz == NULL || (raiz->dataEvento.ano == data.ano &&
                        raiz->dataEvento.mes == data.mes &&
                        raiz->dataEvento.dia == data.dia &&
                        raiz->dataEvento.hora == data.hora &&
                        raiz->dataEvento.minuto == data.minuto)) {
      return raiz;
   }

   if (data.ano < raiz->dataEvento.ano ||
       (data.ano == raiz->dataEvento.ano && data.mes < raiz->dataEvento.mes) ||
       (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
        data.dia < raiz->dataEvento.dia) ||
       (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
        data.dia == raiz->dataEvento.dia && data.hora < raiz->dataEvento.hora) ||
       (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
        data.dia == raiz->dataEvento.dia && data.hora == raiz->dataEvento.hora &&
        data.minuto < raiz->dataEvento.minuto)) {
      return buscarEventoPorData(raiz->esquerda, data);
   } else {
      return buscarEventoPorData(raiz->direita, data);
   }
}

// Função para buscar eventos na agenda por hora
void buscarEventosPorHora(Evento* raiz, int hora) {
   if (raiz != NULL) {
      if (raiz->dataEvento.hora == hora) {
         printf("Código: %d\n", raiz->codigo);
         printf("Data: %02d/%02d/%04d\n", raiz->dataEvento.dia, raiz->dataEvento.mes, raiz->dataEvento.ano);
         printf("Hora: %02d:%02d\n", raiz->dataEvento.hora, raiz->dataEvento.minuto);
         printf("Duração: %.2f\n", raiz->duracao);
         printf("Descrição: %s\n", raiz->descricao);
         printf("-------------------\n");
      }
      buscarEventosPorHora(raiz->esquerda, hora);
      buscarEventosPorHora(raiz->direita, hora);
   }
}

// Função para excluir um evento da agenda
Evento* excluirEvento(Evento* raiz, Data data, int hora, int minuto) {
   if (raiz == NULL) {
      return raiz;
   }

   if (data.ano < raiz->dataEvento.ano ||
       (data.ano == raiz->dataEvento.ano && data.mes < raiz->dataEvento.mes) ||
       (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
        data.dia < raiz->dataEvento.dia) ||
       (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
        data.dia == raiz->dataEvento.dia && hora < raiz->dataEvento.hora) ||
       (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
        data.dia == raiz->dataEvento.dia && hora == raiz->dataEvento.hora &&
        minuto < raiz->dataEvento.minuto)) {
      raiz->esquerda = excluirEvento(raiz->esquerda, data, hora, minuto);
   } else if (data.ano > raiz->dataEvento.ano ||
              (data.ano == raiz->dataEvento.ano && data.mes > raiz->dataEvento.mes) ||
              (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
               data.dia > raiz->dataEvento.dia) ||
              (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
               data.dia == raiz->dataEvento.dia && hora > raiz->dataEvento.hora) ||
              (data.ano == raiz->dataEvento.ano && data.mes == raiz->dataEvento.mes &&
               data.dia == raiz->dataEvento.dia && hora == raiz->dataEvento.hora &&
               minuto > raiz->dataEvento.minuto)) {
      raiz->direita = excluirEvento(raiz->direita, data, hora, minuto);
   } else {
      if (raiz->esquerda == NULL) {
         Evento* tempEvento = raiz->direita;
         free(raiz);
         return tempEvento;
      } else if (raiz->direita == NULL) {
         Evento* tempEvento = raiz->esquerda;
         free(raiz);
         return tempEvento;
      }

      Evento* tempEvento = raiz->direita;
      while (tempEvento->esquerda != NULL) {
         tempEvento = tempEvento->esquerda;
      }
      raiz->codigo = tempEvento->codigo;
      raiz->dataEvento = tempEvento->dataEvento;
      raiz->duracao = tempEvento->duracao;
      strcpy(raiz->descricao, tempEvento->descricao);
      raiz->direita = excluirEvento(raiz->direita, tempEvento->dataEvento, tempEvento->dataEvento.hora, tempEvento->dataEvento.minuto);
   }
   return raiz;
}

// Função para percorrer a árvore em ordem e listar os eventos
void percorrerEmOrdem(Evento* raiz) {
   if (raiz != NULL) {
      percorrerEmOrdem(raiz->esquerda);
      printf("Código: %d\n", raiz->codigo);
      printf("Data: %02d/%02d/%04d\n", raiz->dataEvento.dia, raiz->dataEvento.mes, raiz->dataEvento.ano);
      printf("Hora: %02d:%02d\n", raiz->dataEvento.hora, raiz->dataEvento.minuto);
      printf("Duração: %.2f\n", raiz->duracao);
      printf("Descrição: %s\n", raiz->descricao);
      printf("-------------------\n");
      percorrerEmOrdem(raiz->direita);
   }
}