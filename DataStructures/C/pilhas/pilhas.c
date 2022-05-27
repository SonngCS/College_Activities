#include "pilhas.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void stack_init(pilha * p){
  p->topo = -1;
}

bool stack_isempty(pilha p){
  return p.topo == -1? true: false;
}

bool stack_isfull(pilha p){
  return p.topo == (STACK_MAX - 1)? true: false;
}

void push(pilha * p, stack_info x){
 if(stack_isfull(*p)){
   fprintf(stderr, "ERRO! A pilha esta' cheia\n");
   exit(1);
 }
 p->itens[++(p->topo)] = x;
}

bool push_and_test(pilha * p, stack_info x){
  if(!stack_isfull(*p)){
    p->itens[++(p->topo)] = x;
    return true;
  }
  return false;
}

stack_info pop(pilha * p){
  if(stack_isempty(*p)){
    fprintf(stderr, "ERRO! A pilha est'a vazia\n");
    exit(1);
  }
  return p->itens[p->topo--];
}

bool pop_and_test(pilha * p, stack_info * x){
  if(!stack_isempty(*p)){
    *x = p->itens[(p->topo)--];
    return true;
  }
  return false;
}

stack_info top(pilha p){
  if(stack_isempty(p)){
    fprintf(stderr, "Erro, a pilha esta' vazia\n");
    exit(1);
  }
  return p.itens[p.topo];
}

bool top_and_test(pilha p, stack_info * x){
  if(!stack_isempty(p)){
    *x = p.itens[p.topo];
    return true;
  }
  return false;
}

void stack_visu(pilha p){
  if(!stack_isempty(p)){
    printf("Os elementos da pilha sao:\n");
    for(int i = 0; i < p.topo + 1; i++){
      printf("%d ", p.itens[i]);
    }
  }else{
    fprintf(stderr, "A pilha esta vazia! Exibicao cancelada.\n");
  }
}
