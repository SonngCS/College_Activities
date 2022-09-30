package prova;

public class Bolacha extends Produto {
    private String marca;

    public Bolacha(String mar, double custo, double taxa){
        super(custo, taxa);
        setMarca(mar);
    }

    public String getMarca(){
        return this.marca;
    }

    public void setMarca(String m){
        this.marca = m;
    }

    public double calcularValorVenda(){
        return super.calcularValorVenda();
    }
}
