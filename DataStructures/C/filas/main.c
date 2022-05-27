#include <stdio.h>
#include <stdbool.h>
#include "fila.h"

int main(void){
  fila f;
  queue_info x;
  int opt = 0;

  queue_init(&f);

  while(opt != 5){
    printf("\n\nDigite a operacao desejada:\n");
    printf("1-Verificar se a fila esta vazia\n2-Verificar se a fila esta cheia\n");
    printf("3-Adicionar um elemento 'a fila\n4-Remover um elemento da fila\n");
    printf("5-Sair\n");
    scanf("%d", &opt);

    switch(opt){
      case 1:
        if(queue_isempty(f)){
          printf("A fila esta' vazia\n");
        }else{
          printf("A fila nao esta vazia\n");
        }
        break;
      case 2:
        if(queue_isfull(f)){
          printf("A fila esta cheia\n");
        }else{
          printf("A fila nao esta cheia\n");
        }
        break;
      case 3:
        printf("Digite o novo elemento: ");
        scanf("%d", &x);
        enqueue(&f, x);
        break;
      case 4: printf("O elemento %d foi removido\n", dequeue(&f)); break;
      case 5: break;
      default: printf("Erro, opcao nao reconhecida\n"); break;
    }
    queue_print(f);
  }

  return 0;
}
