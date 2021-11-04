/*
Universidade Católica de Santos
Aluno: Vitor Cordeiro Paes Prieto
Projeto de Algoritmos - Atividade Prática 1
*/

#include <stdio.h>
#include <string.h>

int economia(int, char [][*]);

int main(void){

    int n;
    static char telefones[100000][201];
    scanf("%d", &n);
    
    //laço while para a repetição da leitura da variável n, até que ela seja 0;
    while (n != 0){

        //laço interno para a leitura das n strings de até 200 números;
        for(int i = 0; i < n; i++){
            scanf(" %200[^\n]", telefones[i]);
        }

        //chamada da função que fará a leitura e devolverá a quantidade de números que podem ser omitidos;
        printf("%d\n", economia(n, telefones));

        //leitura do próximo valor para n;
        scanf("%d", &n);
    }

    return 0;
}

int economia(int num, char lista[100000][201]){
    int len, cont = 0;

    for(int i = 1; i < num; i++){
        for(int j = 0, len = strlen(lista[i]); j < len; j++){
            if(lista[i - 1][j] == lista[i][j]){
                cont++;
            }else{
                break;
            }
        }
    }
    return cont;
}
