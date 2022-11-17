import java.util.TreeSet;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Hello Wordl!");
        Time t1 = new Time();
        t1.setCodigo(0);
        t1.setJogos(10);
        t1.setNome("TIMAO");
        t1.setDerrotas(8);
        t1.setEmpates(1);
        t1.setVitorias(1);
        
        Time t2 = new Time(1, "SFC", 9, 1, 0, 10);
        Time t3 = new Time(2, "Parmera", 7, 2, 1, 10);
        Time t4 = new Time(3, "Vasco", 0, 8, 2, 10);
        Time t5 = new Time(4, "America", 5, 4, 1, 10);
        
        Campeonato c = new Campeonato();
        c.addTime(t1);
        c.addTime(t2);
        c.addTime(t3);
        c.addTime(t4);
        c.addTime(t5);
        
        Time t;
        try {
            t = c.getTime(1);
            t.calcular();
            System.out.println("Time: "+t.getNome());
            System.out.println("Total de pontos: "+t.getPontos());
            
            TreeSet<Time> ts = c.getClassificacao();
            for(Time time : ts) {
                System.out.println("Time: "+time.getNome()+ " Pontos: "+time.getPontos());
            }
        }
        catch(TimeException te) {
            System.out.println(te.getMessage());
        } 
        
        
    }
    
}
