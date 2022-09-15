//ALuno: Vitor Cordeiro Paes Prieto
import java.util.Scanner;

public class Main{

	public static void main(String[] args){
		String m, mod;
		float cons, tanq, vel, temp;
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite a marca do veiculo: ");
		m = sc.nextLine();
		System.out.println("Digite o modelo do veiculo: ");
		mod = sc.nextLine();
		System.out.println("Digite o consumo do carro: ");
		cons = sc.nextFloat();
		System.out.println("Digite quantos litros estao no tanque: ");
		tanq = sc.nextFloat();
		Carro c1 = new Carro(cons, tanq, m, mod);
		System.out.println("Digite a velocidade media: ");
		vel = sc.nextFloat();
		System.out.println("Digite o tempo de movimento: ");
		temp = sc.nextFloat();
		while(c1.setarVelocidade(vel, temp)){
			System.out.println("\nCarro c1: "+c1.marca+" Modelo: "+
			c1.modelo+"\nOdometro: "+c1.odometro+"\nTanque: "+c1.tanque+
			"\n");
			System.out.println("Digite a nova velocidade: ");
			vel = sc.nextFloat();
			System.out.println("Digite o novo tempo de movimento: ");
			temp = sc.nextFloat();
		}
		sc.close();
	}
}
