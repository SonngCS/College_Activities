//Aluno: Vitor Cordeiro Paes Prieto
import java.util.Scanner;

public class Main{

	public static void main(String[] args){
		int opt = -1;
		float max, min, quantidade;
		Scanner sc = new Scanner(System.in);
		Tanque tq = new Tanque();
		System.out.println("Digite o volume maximo do tanque: ");
		max = sc.nextFloat();
		System.out.println("Digite o volume minimo do tanque: ");
		min = sc.nextFloat();
		tq.setVolumeMin(min);
		tq.setVolumeMax(max);
		tq.setVolumeAtual(min);
		tq.setBomba(true);
		while(opt != 3){
			System.out.println("Tanque:\n" + tq.exibirInfos());
			System.out.println("Digite a opcao:\n1 - Encher\n" +
			"2 - Esvaziar\n3 - Sair\nEscolha: ");
			opt = sc.nextInt();
			if(opt == 1){
				if(tq.getBomba()){				
					System.out.println("Digite a quantidade de litros: ");
					quantidade = sc.nextFloat();
					tq.encher(quantidade);
				}else{
					System.out.println("ERRO! A bomba esta desligada");
				}
			}else{
				System.out.println("Digite a quantidade de litros: ");
				quantidade = sc.nextFloat();
				tq.esvaziar(quantidade);
			}

			
		}
	}

}
