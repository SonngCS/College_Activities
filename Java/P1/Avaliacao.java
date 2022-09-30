package prova;

public class Avaliacao {
    
    public int n1;
    public int n2;
    public int n3;

    public Avaliacao(int nota1, int nota2, int nota3){
        this.n1 = nota1;
        this.n2 = nota2;
        this.n3 = nota3;
    }

    public double media(){
        return (double) ((this.n1 + this.n2 + this.n3)/3.00);
    }

    public double media(double p1, double p2, double p3){
        return ((this.n1*p1 + this.n2*p2 + this.n3*p3)/(p1 + p2 + p3));
    }

}
