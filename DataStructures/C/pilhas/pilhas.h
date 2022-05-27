#ifndef _PILHAS_H
#define _PILHAS_H

#define STACK_MAX 100
#include <stdbool.h>
typedef int stack_info;
typedef struct{
  stack_info itens[STACK_MAX];
  int topo;
} pilha;

//Inicializa uma pilha
void stack_init(pilha *);

//Verifica se a pilah está vazia
bool stack_isempty(pilha);

//Verifica se a pilha está cheia
bool stack_isfull(pilha);

//Adiciona um elemento ao final da pilha
void push(pilha *, stack_info);

//Adiciona um elemento ao final da pilha se possível
//ou retorna falso caso a operação seja impossível
bool push_and_test(pilha *, stack_info);

//Retira o elemento do topo da pilha
stack_info pop(pilha *);

//Retira um elemento ao final da pilha se possível
//ou retorna falso caso a operação seja impossível
bool pop_and_test(pilha *, stack_info *);

//Retorna o elemento do topo da pilha
stack_info top(pilha);

//Retorna o elemento do topo da lista se possível
//ou retorna falso caso a operação seja impossível
bool top_and_test(pilha, stack_info *);

//Visualiza todos os elementos da pilha
void stack_visu(pilha);

#endif
