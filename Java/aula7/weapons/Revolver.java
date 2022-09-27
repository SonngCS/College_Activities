package weapons;

public class Revolver extends Arma implements Disparavel{
    private int cartucho;

    public Revolver(int cart, double destruicao){
        this.destruicao = destruicao;
        setCartucho(cart);
    }

    public void setCartucho(int car){
        this.cartucho = car;
    }

    public int getCartucho(){
        return cartucho;
    }

    public double disparar(){
        if(this.cartucho > 0){
            this.cartucho = this.cartucho - 1;
            return this.destruicao;
        }
        return 0.0;
    }

    public void recarregar(){
        this.cartucho = this.cartucho + 6;
    }

    public double golpear(){
        return this.destruicao/3;
    }

    public String infos(){
        return ("Cartuchos restantes: " + this.cartucho + "\nPoder de destruicao: " + this.destruicao);
    }
}
