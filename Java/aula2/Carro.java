public class Carro{
	float odometro, tanque, consumoMedio;
	String marca, modelo;

	public Carro(float consumo, float tan, String n1, String n2){
		this.consumoMedio = consumo;
		this.odometro = 0;
		this.tanque = tan;
		this.marca = n1;
		this.modelo = n2;
	}

	public boolean setarVelocidade(float vm, float tempo){
		float distancia = vm*tempo;
		float litros = distancia/this.consumoMedio;
		float litrosAlt = this.tanque;
		this.tanque -= litros;
		if(this.tanque <= 0){
			this.odometro += ((litrosAlt/this.consumoMedio)*vm);
			System.out.println("Odometro final: "+this.odometro);
			System.out.println("O tanque esta' vazio!\n");
			return false;
		}
		this.odometro += distancia;
		return true;
	}

}
