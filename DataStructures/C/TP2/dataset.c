#include "dataset.h"
#include "arvores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Carregamento do arquivo CSV e armazenamento na árvore
void load_file(avl_tree * arvore, char * filename, int idx){

	key_idx = idx;

	FILE *arquivo;

	if((arquivo = fopen(filename, "r")) == NULL){
		fprintf(stderr, "O arquivo não pôde ser lido.\n");
		exit(1);
	}

  if(idx >= NUMERO_COLUNAS){
    printf("Indice escolhido fora do numero maximo de colunas do dataset.\n");
    exit(1);
  }

	char string[401];
	char * token;
	char linha[401];
  
	//Primeira linha é o cabeçalho
	fgets(string, 400, arquivo);

	avl_info avl_lin;
  bool h, final;
  
  //Leitura do arquivo CSV
	while (fgets(string, 400, arquivo) != NULL){
		//Primeiro elemento
    token = strtok(string, ";");
		strcpy(linha, token);
		str_strip(linha);
		avl_lin.dados[0] = malloc(sizeof(linha));
		strcpy(avl_lin.dados[0], linha);

    //Demais elementos
		for(int i = 1; i < NUMERO_COLUNAS; i++){
			token = strtok(NULL, ";");
			strcpy(linha, token);
			str_strip(linha);
			avl_lin.dados[i] = malloc(sizeof(linha));
			strcpy(avl_lin.dados[i], linha);
		}

    //Adicionando o elemento na árvore
		search(arvore, &avl_lin, &h, &final);
	}
	fclose(arquivo);
}

//Retirar espaços em branco do final e repetidos no meio da string
void str_strip(char * s){
  char aux[250];
  bool modificou = false;
  strcpy(aux, s);
  while(aux[0] == ' ') { //Remoção de espaços em branco ao início da string
    for(int i = 0, a = strlen(aux); i < a; i++) aux[i] = aux[i+1];
    if(!modificou) modificou = true;
  }
  while(aux[strlen(aux) - 1] == ' '){ //Remoção de espaços em branco ao final da string
    aux[strlen(aux) - 1] = '\0';
    if(!modificou) modificou = true;
  }
  for(int i = 0, a = strlen(aux); i < a; i++){ //Remoção de espaços em branco no meio da string
    while(aux[i] == ' ' && aux[i + 1] == ' '){
      for(int j = i; j < a; j++) aux[j] = aux[j + 1];
      if(!modificou) modificou = true;
      a--;
    }
  }
  if(modificou) strcpy(s, aux);
}

//Função para mostrar a coluna carregada
bool show_col(avl_tree* t, int idx){
  
  if(idx >= NUMERO_COLUNAS){
    printf("Erro, indice fora do numero maximo de colunas do dataset.\n");
    return false;
  } 

  if(key_idx != idx) key_idx = idx;
  
  if(t != NULL){
    if((*t)->esq != NULL) show_col(&(*t)->esq, key_idx);
    printf("%s\n", (*t)->dado.dados[key_idx]);
    if((*t)->dir != NULL) show_col(&(*t)->dir, key_idx);
  }
  return true;
}

//Função para mostrar todos os dados equivalentes ao filtro desejado
void filter_data(avl_tree* t, int idx, char* value){
  
  if(idx >= NUMERO_COLUNAS){
    fprintf(stderr, "Erro, indice fora do numero maximo de colunas do dataset.\n");
    exit(1);
  }

  if(key_idx != idx) key_idx = idx;
    
  if(t != NULL){
    if((*t)->esq != NULL) filter_data(&(*t)->esq, key_idx, value);
    if(strcasecmp((*t)->dado.dados[key_idx], value) == 0){ 
      for(int i = 0; i < NUMERO_COLUNAS; i++){ //Mostar o dado equivalente ao filtro
        printf("%s\n", (*t)->dado.dados[i]);
      }
    }
    if((*t)->dir != NULL) filter_data(&(*t)->dir, key_idx, value);
  }
}

//Função para adicionar uma nova linha
bool add_new_row(avl_tree* t, avl_info* x){
  bool h, final;  
  final = false;
  search(t, x, &h, &final);
  if(final) return true;
  return false;
}

//Função para salvar os dados em um arquivo CSV
void save_users(avl_tree t){
  if(t == NULL){ //Árovre vazia
    fprintf(stderr, "Erro, a'rvore vazia.\n");
    exit(1);
  }
  FILE * output;
  output = fopen("output.csv", "w+");
  browsing_avl(&t, output); //Subfunção de salvamento 
  fclose(output);
}

//Função auxiliar para salvar os dados em um arquivo CSV
void browsing_avl(avl_tree * t, FILE * arquivo){
  if(t != NULL){ //Verifica o nó, e posteriormente verifica seus filhos esquerdo e direito
    if((*t)->esq != NULL) browsing_avl(&(*t)->esq, arquivo);
    for(int i = 0; i < NUMERO_COLUNAS; i++){
      if(i != (NUMERO_COLUNAS - 1)){ //Salva os dados no formato lido em a), com ";" como delimitadores
        fprintf(arquivo, "%s;", (*t)->dado.dados[i]);
      }else{ //último arquivo da linha possui salvamento diferente. Se ele já estava na árvore será salvo normalmente,
             //Mas caso seja um elemento novo adicionado pelo usuário, deverá receber um '\n' ao final.
        if((*t)->dado.dados[i][(strlen((*t)->dado.dados[i]) - 1)] != '\n') fprintf(arquivo, "%s\n", (*t)->dado.dados[i]);
        else fprintf(arquivo, "%s", (*t)->dado.dados[i]);
      }
    }
    if((*t)->dir != NULL) browsing_avl(&(*t)->dir, arquivo);
  }
}

//Função para o menu de opções
void menu(avl_tree* t, char * filename){
  
  int idx_col, op, aux;
  op = idx_col = -1;
  printf("Os dados do arquivo '%s' serão carregados.\n", filename);
  printf("\nEscolha a coluna de ordenação: ");
  scanf("%d", &idx_col); //índice que será passado à key_idx
  load_file(t, filename, idx_col);
  printf("Os dados foram carregados com sucesso.\n");
  
  char filtro[100], novo_elemento[100];
  avl_info x;
  
  while(op != 5){ //Loop principal do menu
    printf("\nEscolha uma das seguintes opções:\n");
    printf("0 - Mostrar todos os dados da coluna %d.\n", key_idx);
    printf("1 - Mostrar todos os dados de uma linha de acordo com uma coluna e o filtro desejado.\n");
    printf("2 - Reordenar a a'rvore original a partir de outra coluna.\n");
    printf("3 - Adicionar uma nova linha 'a a'rvore atual.\n");
    printf("4 - Salvar a a'rvore em um arquivo CSV\n");
    printf("5 - Sair.\n\n");
    
    scanf("%d", &op);
    
    switch(op){
      case 0: 
        printf("\n");
        show_col(t, idx_col);
        break;
      case 1:
        aux = key_idx; //Auxiliar para manter o número da coluna ordenadora
        printf("Digite a coluna: ");
        scanf("%d", &idx_col);
        printf("Digite o filtro: ");
        scanf(" %99[^\n]", filtro);
        printf("\n");
        filter_data(t, idx_col, filtro);
        key_idx = aux;
        break;
      case 2: 
        arvore_init(t); //Reescrever a árvore original com outra coluna ordenadora
        printf("Digite a nova coluna ordenadora: ");
        scanf("%d", &idx_col);
        load_file(t, filename, idx_col);
        break;
      case 3:
        for(int i = 0; i < NUMERO_COLUNAS; i++){
          printf("Digite o novo dado referente a %d coluna: ", i);
          scanf(" %99[^\n]", novo_elemento);
          x.dados[i] = malloc(sizeof(novo_elemento));
          strcpy(x.dados[i], novo_elemento);
        }
        if(!add_new_row(t, &x)){
          fprintf(stderr, "Erro, não foi possivel adicionar os novos elementos.\n");
          exit(1);
        }
        break;
      case 4:
        save_users(*t); //Salvando a árvore no novo CSV
        printf("A'rvore salva como 'output.csv'\n");
        break;
      case 5:
        printf("Saindo...\n");
        break;
      default: printf("Opção nao reconhecida.\n"); break;
    }
  }
}