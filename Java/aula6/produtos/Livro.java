package produtos;
public class Livro extends Produto{
    private String ISBN;
    private double valor;

    public void setISBN(String ISBN2){
        this.ISBN = ISBN2;
    }

    public void setValor(double valor2){
        this.valor = valor2;
    }

    public String getISBN(){
        return ISBN;
    }

    public double getValor(double valor2){
        return valor;
    }

    public double getValorLiquido(){
        return this.valor*0.75;
    }

}