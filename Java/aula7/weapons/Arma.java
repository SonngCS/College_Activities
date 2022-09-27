package weapons;

public abstract class Arma {
    
    protected double destruicao;

    public void setDestruicao(double val){
        this.destruicao = val;
    }

    public double getDestruicao(){
        return this.destruicao;
    }

    public double golpear(){
        return this.destruicao;
    }

    public String infos(){
        return ("Poder de destruicao: " + this.destruicao);
    }

}
