#include "pilhas.h"
#include <stdio.h>
#include <stdbool.h>

int main(void){

  int n = -1;
  pilha p;
  stack_info item;
  bool resul;
  stack_init(&p);
  while(n != 6){
    printf("\n\nOla'! Digite a operacao desejada:\n");
    printf("1 - Verificar se a pilha esta' vazia\n");
    printf("2 - Verificar se a pilha esta' cheia\n");
    printf("3 - Adicionar um item 'a pilha\n");
    printf("4 - Retirar um item da pilha\n");
    printf("5 - Verificar o elemento no topo da pilha\n");
    scanf("%d", &n);

    switch(n){
      case 1:
        if(!stack_isempty(p)){
          printf("A pilha nao esta' vazia!\n");
          break;
        }
        printf("A pilha esta' vazia!\n");
        break;
      case 2:
        if(!stack_isfull(p)){
          printf("A pilha nao esta' cheia!\n");
          break;
        }
        printf("A pilha esta' cheia!\n");
        break;
      case 3:
        printf("Digite o nu'mero a ser inserido: ");
        scanf("%d", &item);
        resul = push_and_test(&p, item);
        if(!resul){
          printf("Operacao mal sucedida.\n");
          break;
        }
        stack_visu(p);
        break;
      case 4:
        resul = pop_and_test(&p, &item);
        if(resul){
          printf("O elemento %d foi retirado da pilha.\n", item);
          stack_visu(p);
          break;
        }
        fprintf(stderr, "Operacao mal sucedida.\n");
        break;
      case 5:
        resul = top_and_test(p, &item);
        if(resul){
          printf("O elemento no topo da pilha e': %d\n", item);
          break;
        }
        fprintf(stderr, "Operacao mal sucedida.\n");
        break;
      default:
        printf("Opcao nao reconhecida.\n");
    }

  }

  return 0;
}
