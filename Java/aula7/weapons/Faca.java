package weapons;

public class Faca extends Arma{

    private int lamina;

    public Faca(double des){
        this.lamina = 5;
        this.destruicao = des;
    }
    
    public void setLamina(int lam){
        this.lamina = lam;
    }

    public int getlamina(){
        return this.lamina;
    }

    public double golpear(){
        if(this.lamina > 0){
            this.lamina = this.lamina - 1;
            return this.destruicao;
        }else{
            System.out.println("Durabilidade fraca! Poder de ataque reduzido!");
            return 0.1;
        }
    }
    
    public String infos(){
        return ("Durabilidade da faca: " + this.lamina + "\nPoder de destruicao: " + this.destruicao);
    }

}
