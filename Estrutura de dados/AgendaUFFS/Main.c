#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"UFFSagenda.h"

// Função principal do programa
int main() {
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