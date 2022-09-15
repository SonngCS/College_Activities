import java.util.Scanner;

import produtos.DVD;
import produtos.Livro;
import produtos.Produto;

public class Aula6{

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        int escolha;
        double total = 0.0;
        String nome;
        double valor;
        Produto prod;

            for(int i = 0; i < 3; i++){
                escolha = 0;
                while((escolha != 1) & (escolha != 2)){
                System.out.println("\nDigite o produto desejado:\n1 - Livro\n2 - DVD\n");
                escolha = scanner.nextInt();
                }
                if(escolha == 1){
                    prod = new Livro();
                }else{
                    prod = new DVD();
                }
                System.out.println("Digite SN/ISBN da mercadoria: ");
                nome = scanner.next(); //Scanner do nome
                System.out.println("Digite o preco da mercadoria: ");
                scanner.nextLine(); // Lixo de memória (\n do Enter)
                valor = scanner.nextDouble(); //Scanner do real valor monetário
                prod.setNome(nome);
                prod.setValor(valor);
                total += prod.getValorLiquido();
            }
            System.out.println("\n\nO total da compra foi: " + total + "\n");
        scanner.close();
    }
}