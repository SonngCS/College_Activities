/*
Universidade Católica de Santos
Aluno: Vitor Cordeiro Paes Prieto
N° de Matrícula: 6204033
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
    int len, cont = 0, aux_i;

    for(int i = 1; i < num; i++){
        aux_i = i - 1;
        for(int j = 0, len = strlen(lista[i]); j < len; j++){
            while(lista[aux_i][j] == ' '){
                /*
                laço while para encontrar o número (lista[i][j]) das linhas anteriores, caso ele tenha se repetido alguma vez
                e em seu lugar haja espaços em branco, adicionados pelo comando if abaixo;
                */
                aux_i--;
            }
            
            if(lista[aux_i][j] == lista[i][j] && (i > 1 ? lista[i - 1][j] == ' ': lista[i - 1][j] != ' ')){
                /*
                Caso o elemento da posição lista[i][j] seja igual ao elemento  da posição lista[aux_i][j], devemos verificar se i > 1. 
                Se verdadeiro, a omissão só ocorrerá se o elemento da linha acima for uma espaço em branco. Caso o elemento da linha 
                acima não seja um espaço em branco, só haverá omissão se i = 1;
                */
                cont++;
                lista[i][j] = ' ';
            }else{
                //se um dos elementos iniciais não puder ser omitido, não é preciso verificar se os demais podem, pois as omissões são contínuas.
                break;
            }
        }
    }
    return cont;
}
