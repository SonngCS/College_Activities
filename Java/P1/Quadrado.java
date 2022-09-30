package prova;

public class Quadrado implements Calculavel {
    
    private double lado;

    public Quadrado(double l){
        this.lado = l;
    }

    public double calcularArea(){
        return this.lado*this.lado;
    }

    public double calcularPerimetro(){
        return 4*this.lado;
    }
}
