package prova;

public class Retangulo implements Calculavel {

    private double altura;
    public double base;

    public Retangulo(double h, double b){
        this.altura = h;
        this.base = b;
    }

    public double calcularArea(){
        return this.altura*this.base;
    }

    public double calcularPerimetro(){
        return 2*this.altura+2*this.base;
    }
}
