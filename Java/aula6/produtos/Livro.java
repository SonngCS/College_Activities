package produtos;
public class Livro extends Produto{
    private String nome;
    private double valor;

    public void setNome(String nome2){
        this.nome = nome2;
    }

    public void setValor(double valor2){
        this.valor = valor2;
    }

    public String getNome(){
        return nome;
    }

    public double getValor(double valor2){
        return valor;
    }

    public double getValorLiquido(){
        return this.valor*0.75;
    }

}