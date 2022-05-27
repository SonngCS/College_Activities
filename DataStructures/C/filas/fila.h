#ifndef _FILA_H
#define _FILA_H

#define QUEUE_MAX 50
#include <stdbool.h>

typedef int queue_info;

typedef struct{
  queue_info itens[QUEUE_MAX];
  int comeco, final;
}fila;

//Inicia uma fila
void queue_init(fila *);

//Verifica se a fila está vazia
bool queue_isempty(fila);

//Verifica se a fila está cheia
bool queue_isfull(fila);

//Adiciona um elemento ao final da fila
void enqueue(fila *, queue_info);

//Retira um elemento do inicio da fila
queue_info dequeue(fila *);

//Imprime a lista
void queue_print(fila);

#endif
