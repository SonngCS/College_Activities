#ifndef _DATASET_H
#define _DATASET_H

#include "arvores.h"
#include <stdio.h>

//Função para a leitura das linhas do arquivo CSV
void load_file(avl_tree *, char *, int);

//Função para retirar espaços em branco ao inicio, final ou duplicados nas strings
void str_strip(char *);

//Função para mostrar a coluna desejada
bool show_col(avl_tree* , int);

//Função para mostrar apenas os itens com o mesmo valor que o desejado
void filter_data(avl_tree*, int, char*);

bool add_new_row(avl_tree *, avl_info*);

//Função para mostrar um menu de escolhas
void menu(avl_tree*, char * filename);

//Função para salvar a árvore final em um novo arquivo CSV
void save_users(avl_tree);

//Função para passar pelos nós da árvore e salvar seus itens no CSV aberto na função save_users
void browsing_avl(avl_tree *, FILE *);

#endif