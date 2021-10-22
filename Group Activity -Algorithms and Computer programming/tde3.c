#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
PROGRAMAÇÃO DE COMPUTADORES
Integrantes:
Matheus Emmanuel 7129437
Victor Jacinto dos Santos 
victor Henrique Menegasso 
Vitor Cordeiro Paes Prieto 
*/

void opcao_e_saida(int, char[1347][100], int[1347][3], bool);

int main(void) {
  FILE *arquivo;
  int n, i;
  int num[1347][3];
  n = i = 0;
  char cidade[1347][100], leitura[100];
  bool escolha;

  arquivo = fopen("fonte.csv", "r");

  if(arquivo == NULL) {
      printf("Erro! Arquivo nao encontrado.\n");
      return 1;
  }
  fgets(leitura, 100, arquivo);

  char *token; 
//leitura e gravação dos dados contidos no arquivo
  while(fgets(leitura, 100, arquivo) != NULL){
    token = strtok(leitura, ",");
    num[i][0] = atoi(token);
    token = strtok(NULL,",");
    num[i][1] = atoi(token);
    token = strtok(NULL,",");
    strcpy(cidade[i], token);
    token = strtok(NULL,",");
    num[i][2] = atoi(token);
    i++;
  }

  fclose(arquivo);

//Ordenação decrescente da matriz (pelo número de vacinados ) 
 int j, k;
  int reserva[3];
  char reserva_nome_cidade[100];
  for(i = 1; i < 1347; i++){
    for(k = 0; k < 3; k++){
      reserva[k] = num[i][k];
    }
    strcpy(reserva_nome_cidade, cidade[i]);
    j = i - 1;
    while ((num[j][2] < reserva[2]) && (j >= 0)){
      for(k = 0; k < 3; k++){
        num[j+1][k] = num[j][k];
      }
      strcpy(cidade[j+1], cidade[j]);
      j -= 1;
    }
    for(k = 0; k < 3; k++){
      num[j+1][k] = reserva[k];
    }
    strcpy(cidade[j+1], reserva_nome_cidade);
  }
  
//menu principal
  while (n !=3){
    printf("\n*************************************************\n");
    printf("*Pesquisa vacinas cidades do Norte do Brasil*****\n");
    printf("*************************************************\n");
    printf("1- Pesquisa por ano\n2- Pesquisa por codigo da cidade\n3- Sair\nDigite uma opcao: ");
    scanf("%d", &n);
    if(n == 1){
      escolha = true;
      opcao_e_saida(n, cidade, num, escolha);
    }else{
      if(n == 2){
        escolha = false;
        opcao_e_saida(n, cidade, num, escolha);
      }else{
        if(n == 3){
          return 0;
        }else{
          printf("Opcao inválida!\n");
        }
      }
    }
  }
  return 0;
}

//funcao que realiza as opções 1 e 2. Caso o sinal seja verdadeiro, executará o comando 1, caso contrário, executará o comando 2.
void opcao_e_saida(int num, char nomescidades[1347][100], int quantidades[1347][3], bool sinal){
  FILE *fim;
  int ano, codigo, i, j, cont, cont2, numcidade[3][2], maisvacinados[5];
  i = j = codigo = cont = cont2 = 0;
  char cidades[100], maiorescidades[5][100], enter, salvar, nomedoarquivo[9], leiturafim[150];
  salvar = enter = 0;

  if(sinal){
    printf("Digite o ano: ");
    scanf("%d",&ano);

    //reconhecimento do ano digitado
    while(((ano != 2016) && (ano != 2017) && (ano != 2018))){
      printf("Dados não encontrados, digite outro ano: ");
      scanf("%d", &ano);
    }

    //while para escrever as primeiras cidades com maior número de vacinados no ano escolhido
    while(cont < 5){
      if(quantidades[i][1] == ano){
        printf("%s %d\n", nomescidades[i], quantidades[i][2]);
        strcpy(maiorescidades[cont], nomescidades[i]);
        maisvacinados[cont] = quantidades[i][2];
        cont++;
      }
      i++;
    }
  }else{
    printf("Digite o co'digo: ");
    scanf("%d", &codigo);

    //reconhecimento do código e recolhimento de dados da matriz principal
    for(i = 0; i < 1347; i++){
      if(quantidades[i][0] == codigo){
        numcidade[cont2][0] = quantidades[i][1];
        numcidade[cont2][1] = quantidades[i][2];
        cont2++;
      }
      if(cont2 == 3){
        break;
      }
    }

    //recolhimento do nome da cidade, caso ela exista
    if(cont2 != 0){
      strcpy(cidades,nomescidades[i]);
      printf("%s\n", cidades);

      //ordenacao crescente da matriz pela coluna do ano
      int aux[2];
      for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
          if(numcidade[i][0] < numcidade[j][0]){
            aux[0] = numcidade[i][0];
            aux[1] = numcidade[i][1];
            numcidade[i][0] = numcidade[j][0];
            numcidade[i][1] = numcidade[j][1];
            numcidade[j][0] = aux[0];
            numcidade[j][1] = aux[1];
          }
        }
      }
      for(i = 0; i < 3; i++){
        printf("%d = %d\n", numcidade[i][0], numcidade[i][1]);
      }
    }else{
      printf("Co'digo nao encontrado! Retornando ao menu principal\n");
    }
  }

  //salvamento de arquivos
  if((sinal) || cont2 != 0){
    printf("\nDeseja salvar esse resultado (S/N)?");
    do{
      scanf("%c", &salvar);
    }while(((salvar != 'S') && (salvar != 'N')) && ((salvar != 's') && (salvar != 'n')));
  }

  //Se a resposta for positiva e sinal = true, então salvaremos os resultados da 1° opção
  if((salvar == 'S' || salvar == 's') && sinal){
    char maisvacinadoschar[10];
    sprintf(nomedoarquivo, "%d.csv", ano);
    printf("Resultado salvo no arquivo %s\n", nomedoarquivo);

    fim = fopen(nomedoarquivo, "w");

    for(i = 0; i < 5; i++){
      strcpy(leiturafim, maiorescidades[i]);
      strcat(leiturafim,",");
      sprintf(maisvacinadoschar, "%d", maisvacinados[i]);
      strcat(leiturafim, maisvacinadoschar);
      fprintf(fim, "%s\n", leiturafim);
    }

    fclose(fim);

  }else{

      //Se a resposta for positiva e sinal = false, salvaremos os resultados da 2° opção
    if(salvar == 'S' || salvar == 's'){
      char num_ano[10];
      char num_vacinados[10];
      sprintf(nomedoarquivo, "%d.csv", codigo); 
      printf("Resultado salvo no arquivo %s\n", nomedoarquivo);

      fim = fopen(nomedoarquivo, "w");

      strcpy(leiturafim, cidades);
      fprintf(fim, "%s\n", leiturafim);

      for(i = 0; i < 3; i++){
        sprintf(num_ano, "%d", numcidade[i][0]);
        strcpy(leiturafim, num_ano);
        sprintf(num_vacinados, "%d", numcidade[i][1]);
        strcat(leiturafim, ",");
        strcat(leiturafim, num_vacinados);
        fprintf(fim, "%s\n", leiturafim);
      }

      fclose(fim);

    }
  }

  //mensagem para voltar ao menu
  do{
    printf("\nDigite [ENTER] para retornar ao menu anterior\n");
    enter = getchar();
  }while(getchar() != '\n');
}
