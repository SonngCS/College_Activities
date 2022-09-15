package produtos;
public class DVD extends Produto{
    private String SN;
    private double valor;

    public void setSN(String SN2){
        this.SN = SN2;
    }

    public void setValor(double valor2){
        this.valor = valor2;
    }

    public String getSN(){
        return SN;
    }

    public double getValor(double valor2){
        return valor;
    }

    public double getValorLiquido(){
        return this.valor*0.9;
    }

}