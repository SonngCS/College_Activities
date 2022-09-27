package weapons;

public class Lancachama extends Arma implements Disparavel{

    private double gas;

    public Lancachama(double g, double d){
        this.gas = g;
        this.destruicao = d;
    }

    public double disparar(){
        if(this.gas > 0){
            this.gas = this.gas - 10;
            return this.destruicao;
        }
        return 0.0;
    }

    public void recarregar(){
        this.gas = this.gas + 100;
    }

    public double golpear(){
        return this.destruicao/3;
    }

    public String infos(){
        return ("Gas restante: " + this.gas + "\nPoder de destruicao: " + this.destruicao);
    }
}
