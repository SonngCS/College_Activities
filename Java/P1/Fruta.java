package prova;

public class Fruta extends Produto{
    private double peso;

    public Fruta(double p, double custo, double taxa){
        super(custo, taxa);
        setPeso(p);
    }

    public double getPeso(){
        return this.peso;
    }

    public void setPeso(double p){
        this.peso = p;
    }

    public double calcularValorVenda(){
        return super.calcularValorVenda()*this.peso;
    }
}
