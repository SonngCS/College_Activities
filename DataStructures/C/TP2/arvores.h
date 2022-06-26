#ifndef _ARVORES_H
#define _ARVORES_H

#define NUMERO_COLUNAS 14

#include <stdbool.h>

extern int key_idx;

typedef struct avl_no * avl_tree;

typedef struct {
  char * dados[NUMERO_COLUNAS];
}avl_info;

struct avl_no {
  avl_info dado;
  avl_tree esq;
  avl_tree dir;
  int bal; // balanceamento do nó
};

//Função para iniciar uma árvore
void arvore_init(avl_tree *);

//Função de rotação esquerda
void rotacao_esq(avl_tree *);

//Função de rotação direita
void rotacao_dir(avl_tree *);

//Função de busca e inserção na árvore AVL
void search(avl_tree *, avl_info *, bool *, bool *);

//Protótipo da Função para remoção de um dado da árvore (incompleto)
//avl_tree remover_dado(avl_tree, char *, int);

#endif