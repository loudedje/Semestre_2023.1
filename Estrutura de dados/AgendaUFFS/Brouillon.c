#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

// Definição das estruturas de data e evento
struct Data {
   int dia;
   int mes;
   int ano;
   int hora;
   int minuto;
};

typedef struct Data Data;

struct Evento {
   int codigo;
   Data dataEvento;
   float duracao;
   char descricao[100];
   struct Evento *esquerda;
   struct Evento *direita;
};

typedef struct Evento Evento;
//Assinatura
Evento* criarEvento(int codigo, Data data, float duracao, char descricao[100]);
Evento* incluirEvento(Evento* raiz, Evento* novoEvento);
Evento* buscarEventoPorData(Evento* raiz, Data data);
void buscarEventosPorHora(Evento* raiz, int hora);
Evento* excluirEvento(Evento* raiz, Data data, int hora, int minuto);
void percorrerEmOrdem(Evento* raiz);


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

// Função principal do programa
int main() {

   setlocale(LC_ALL, "pt_BR.UTF-8");
   Evento* agenda = NULL;
   int codigo;
   int opcao;
   Data data;
   float duracao;
   char descricao[100];
   int hora, minuto;

   do {
      printf("UFFSAgenda - Menu\n");
      printf("1. Incluir\n");
      printf("2. Consultar\n");
      printf("3. Alterar\n");
      printf("4. Excluir\n");
      printf("5. Listar todos\n");
      printf("6. Sair\n");
      printf("Escolha uma opção: ");
      scanf("%d", &opcao);

      switch (opcao) {
         case 1:
            printf("Digite o código do evento: ");
            scanf("%d", &codigo);
            printf("Digite a data do evento (dd mm aaaa): ");
            scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
            printf("Digite a hora do evento (hh mm): ");
            scanf("%d %d", &data.hora, &data.minuto);
            if (data.hora < 0 || data.hora > 23 || data.minuto < 0 || data.minuto > 59) {
               printf("Hora inválida. Digite novamente.\n");
               break;
            }
            printf("Digite a duração do evento: ");
            scanf("%f", &duracao);
            printf("Digite a descrição do evento: ");
            scanf(" %[^\n]s", descricao);
            agenda = incluirEvento(agenda, criarEvento(codigo, data, duracao, descricao));
            printf("Evento incluído com sucesso.\n");
            break;
         case 2:
            if (agenda == NULL) {
               printf("A agenda está vazia.\n");
               break;
            }

            int submenuConsulta;
            printf("UFFSAgenda - Consultar Evento\n");
            printf("1. Consultar por Data\n");
            printf("2. Consultar por hora\n");
            printf("Escolha uma opção: ");
            scanf("%d", &submenuConsulta);

            switch (submenuConsulta) {
               case 1:
                  printf("Digite a data do evento (dd mm aaaa): ");
                  scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
                  Evento* eventoConsultadoPorData = buscarEventoPorData(agenda, data);
                  if (eventoConsultadoPorData != NULL) {
                     printf("Evento encontrado:\n");
                     printf("Código: %d\n", eventoConsultadoPorData->codigo);
                     printf("Data: %02d/%02d/%04d\n", eventoConsultadoPorData->dataEvento.dia, eventoConsultadoPorData->dataEvento.mes, eventoConsultadoPorData->dataEvento.ano);
                     printf("Hora: %02d:%02d\n", eventoConsultadoPorData->dataEvento.hora, eventoConsultadoPorData->dataEvento.minuto);
                     printf("Duração: %.2f\n", eventoConsultadoPorData->duracao);
                     printf("Descrição: %s\n", eventoConsultadoPorData->descricao);
                  } else {
                     printf("Evento não encontrado.\n");
                  }
                  break;
               case 2:
                  printf("Digite a hora do evento: ");
                  scanf("%d", &hora);
                  if (hora < 0 || hora > 23) {
                     printf("Hora inválida. Digite novamente.\n");
                     break;
                  }
                  printf("Eventos encontrados para a hora %02d: \n", hora);
                  buscarEventosPorHora(agenda, hora);
                  break;
               default:
                  printf("Opção inválida. Digite novamente.\n");
                  break;
            }
            break;
         case 3:
            if (agenda == NULL) {
               printf("A agenda está vazia.\n");
               break;
            }

            int submenuAlterar;
            printf("UFFSAgenda - Alterar Evento\n");
            printf("1. Alterar descrição\n");
            printf("2. Alterar duração\n");
            printf("Escolha uma opção: ");
            scanf("%d", &submenuAlterar);

            switch (submenuAlterar) {
               case 1:
                  printf("Digite o código do evento a ser alterado: ");
                  scanf("%d", &codigo);
                  Evento* eventoAlterarPorCodigo = buscarEventoPorData(agenda, data);
                  if (eventoAlterarPorCodigo != NULL) {
                     printf("Digite a nova descrição do evento: ");
                     scanf(" %[^\n]s", eventoAlterarPorCodigo->descricao);
                     printf("Descrição do evento alterada com sucesso.\n");
                  } else {
                     printf("Evento não encontrado.\n");
                  }
                  break;
               case 2:
                  printf("Digite o código do evento a ser alterado: ");
                  scanf("%d", &codigo);
                  Evento* eventoAlterarDuracao = buscarEventoPorData(agenda, data);
                  if (eventoAlterarDuracao != NULL) {
                     printf("Digite a nova duração do evento: ");
                     scanf("%f", &eventoAlterarDuracao->duracao);
                     printf("Duração do evento alterada com sucesso.\n");
                  } else {
                     printf("Evento não encontrado.\n");
                  }
                  break;
               default:
                  printf("Opção inválida. Digite novamente.\n");
                  break;
            }
            break;
         case 4:
            if (agenda == NULL) {
               printf("A agenda está vazia.\n");
               break;
            }
            printf("Digite a data do evento a ser excluído (dd mm aaaa): ");
            scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
            printf("Digite a hora do evento a ser excluído (hh mm): ");
            scanf("%d %d", &hora, &minuto);
            if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59) {
               printf("Hora inválida. Digite novamente.\n");
               break;
            }
            agenda = excluirEvento(agenda, data, hora, minuto);
            printf("Evento excluído com sucesso.\n");
            break;
         case 5:
            if (agenda == NULL) {
               printf("A agenda está vazia.\n");
            } else {
               printf("Lista de Eventos:\n");
               percorrerEmOrdem(agenda);
            }
            break;
         case 6:
            printf("Encerrando o programa.\n");
            break;
         default:
            printf("Opção inválida. Digite novamente.\n");
            break;
      }

      printf("-------------------\n");
   } while (opcao != 6);

   return 0;
}
