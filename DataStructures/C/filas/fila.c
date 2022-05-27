#include "fila.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void queue_init(fila * f){
  f->comeco = f->final = 0;
}

bool queue_isempty(fila f){
  return (f.comeco == f.final);
}

bool queue_isfull(fila f){
  return (f.final - f.comeco == QUEUE_MAX);
}

void enqueue(fila * f, queue_info num){
  if(!queue_isfull(*f)){
    f->itens[f->final % QUEUE_MAX] = num;
    f->final++;
  }else{
    fprintf(stderr, "Fila cheia!\n");
    exit(1);
  }
}

queue_info dequeue(fila * f){
  if(!queue_isempty(*f)){
    queue_info x = f->itens[f->comeco % QUEUE_MAX];
    f->comeco++;
    return x;
  }else{
    fprintf(stderr, "Fila vazia!\n");
    exit(1);
  }
}

void queue_print(fila f){
  if(!queue_isempty(f)){
    printf("\n\nFila: ");
    for(int i = f.comeco; i < f.final; i++){
      printf("%d ", f.itens[i]);
    }
  }
}
