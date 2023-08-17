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