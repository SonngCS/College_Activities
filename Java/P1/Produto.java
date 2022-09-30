package prova;

public abstract class Produto {
    
    private double valCusto;
    private double taxaLucro;

    public Produto(double custo, double taxa){
        setValCusto(custo);
        setTaxaLucro(taxa);
    }

    public double getValCusto(){
        return this.valCusto;
    }

    public void setValCusto(double val){
        this.valCusto = val;
    }

    public double getTaxaLucro(){
        return this.taxaLucro;
    }

    public void setTaxaLucro(double taxa){
        this.taxaLucro = taxa;
    }

    public double calcularValorVenda(){
        return this.valCusto*this.taxaLucro;
    }
}
