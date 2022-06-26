/*
Universidade Católica de Santos
Ciência da Computação, terceiro semestre

Estrutura de dados
Professor: Guilherme Apolinário

Alunos:
Arthur Henrique Silva;
Eric Shiraishi de Freitas;
Gabriel Carvalho Santana;
Gabriel Ferreira Pereira;
Vitor Cordeiro Paes Prieto.

Data: Primeiro semestre de 2022.
*/

#include "dataset.h"
#include "arvores.h"
#include <stdio.h>

int main(void){
  
	avl_tree arvore;
  char escolha;
  escolha = key_idx = -1;
	arvore_init(&arvore); //Iniciando a árvore
  char filename[] = "precos_gasolina_etanol-03-cortado.csv"; //Nome padrão do arquivo CSV
  
  printf("Procedir com o arquivo '%s'? (s/n) ", filename);
  scanf("%c", &escolha);

  //Loop para assegurar que a escolha será "sim" ou "não"
  while((escolha != 'n' && escolha != 'N') && (escolha != 's' && escolha != 'S')){
    printf("Escolha nao reconhecida, tente novamente: ");
    scanf(" %c", &escolha);
  }

  //Caso a escolha seja sim, a função "menu" será iniciada, caso contrário ele pedirá um novo nome para o arquivo CSV
  if(escolha == 's' || escolha == 'S'){
    menu(&arvore, filename);
  }else{
    printf("Digite o nome do arquivo: ");
    scanf(" %99[^\n]", filename);
    menu(&arvore, filename);
  }
  
  return 0;
}