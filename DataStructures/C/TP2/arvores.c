#include "arvores.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int key_idx;

//Inicialização da árvore
void arvore_init(avl_tree* t) {
	memset(t, 0, sizeof(avl_tree));
}

// Rotação para a esquerda
void rotacao_esq(avl_tree * t) {
    avl_tree p;
    p = (*t)->dir;
    (*t)->dir = p->esq;
    p->esq = *t;
    *t = p;
}

// Rotação para a direita
void rotacao_dir(avl_tree * t) {
    avl_tree p;
    p = (*t)->esq;
    (*t)->esq = p->dir;
    p->dir = *t;
    *t = p;
}


//Função search mostrada em aula e adaptada para a estrutura do trabalho
void search(avl_tree * t, avl_info * x, bool * h, bool * final) {
	*final = false;
  if (*t == NULL) {
		if((*t = (avl_tree) malloc(sizeof(struct avl_no))) == NULL) {
			fprintf(stderr,"Erro de alocação de memória!\n");
			exit(1);
		}
		*h = true;
		for (int i = 0; i < NUMERO_COLUNAS; i++) {
			(*t)->dado.dados[i] = x->dados[i];
		}
		(*t)->esq = (*t)->dir = NULL;
		(*t)->bal = 0;
    if(!(*final)) *final = true;
	}
	else if (strcmp(x->dados[key_idx],(*t)->dado.dados[key_idx]) <= 0){ // Inserir a esquerda
		search(&(*t)->esq, x, h, final);
		if (*h) { // O ramo esquerdo cresceu
			switch ((*t)->bal) {
				case 1: (*t)->bal = 0;
				*h = false;
				break;
			case 0: (*t)->bal = -1;
				break;
			case -1: // Rebalanceamento
				if ((*t)->esq->bal == -1) { //Rotação simples p/ direita
				rotacao_dir(t);
				(*t)->dir->bal = 0; //Ajusta o fator de	balanceamento
				} else { // Rotação dupla para direita
					rotacao_esq(&(*t)->esq);
					rotacao_dir(t);
					// Ajusta o fator de balanceamento
					if ((*t)->bal == -1) (*t)->dir->bal = 1;
					else (*t)->dir->bal = 0;
					if ((*t)->bal == 1) (*t)->esq->bal = -1;
					else (*t)->esq->bal = 0;
				}
				*h = false;
				(*t)->bal = 0;
        if(!(*final)) *final = true;
				break;
			} // fim do switch
		}
	} // fim do if
	else if (strcmp(x->dados[key_idx], (*t)->dado.dados[key_idx]) > 0) { // Inserir a direita
		search(&(*t)->dir, x, h, final);
		if (*h) { // O ramo direito cresceu
			switch ((*t)->bal) {
				case -1: (*t)->bal = 0;
				*h = false;
				break;
			case 0: (*t)->bal = +1;
				break;
			case 1: // Rebalanceamento
				if ((*t)->dir->bal == 1) { // Rotação simples p/ esquerda
					rotacao_esq(t);
					// Ajusta o fator de balanceamento
					(*t)->esq->bal = 0;
				} else { // Rotação dupla para esquerda
					rotacao_dir(&(*t)->dir);
					rotacao_esq(t);
					// Ajusta o fator de balanceamento
					if ((*t)->bal == +1) (*t)->esq->bal = -1;
					else (*t)->esq->bal = 0;
					if ((*t)->bal == -1) (*t)->dir->bal = 1;
					else (*t)->dir->bal = 0;
				} // fim do else
				*h = false;
				(*t)->bal = 0;
        if(!(*final)) *final = true;
				break;
			} // fim do switch
		}
	} // fim do if
  // a chave já está na árvore
	//(*t)->dado.cont++;
} // fim de search

//Função para remoção de um dado da árvore
/*
avl_tree remover_dado(avl_tree raiz, char * valor_remocao, int idx_remocao){
    if (raiz == NULL){
        return NULL;
    }else{
        //Caso em que uma folha é removida
        if (strcmp(raiz->dado.dados[idx_remocao], valor_remocao) == 0){
            if (raiz->esq == NULL && raiz->dir == NULL){
                free(raiz);
                return NULL;
            }else{
                //Caso em que um nó analisado possui os dois filhos
                if (raiz->esq != NULL && raiz->dir != NULL){
                    avl_tree aux = raiz->esq;
                    while (aux->dir != NULL) aux = aux->dir;
                    raiz->dado = aux->dado;
                    aux->dado.dados[idx_remocao] = valor_remocao;
                    raiz->esq = remover_dado(raiz->esq, valor_remocao, idx_remocao);
                    return raiz;
                }else{
                    //Caso em que um nó analisado possui apenas um filho
                    avl_tree *aux;
                    if (raiz->esq != NULL) aux = &raiz->esq;
                    else aux = raiz->dir;
                    free(raiz);
                    return aux;
                }
            }
    }else{
        if (strcmp(raiz->dado.dados[idx_remocao], valor_remocao) < 0) raiz->esq = remover_dado(raiz->esq, valor_remocao, idx_remocao);
        else raiz->dir = remover_dado(raiz->dir, valor_remocao, idx_remocao);
        }
    }
}
*/