import java.util.*;

public class Campeonato {
    private Map<Integer, Time> times;
    
    public Campeonato() {
        this.times = new HashMap<Integer, Time>(5);
    }
    
    public void addTime(Time t) {
        if(this.times.size()<5) this.times.put(t.getCodigo(), t);
    }
    
    public Time getTime(int cod) throws TimeException {
        Time t = this.times.get(cod);
        if(t == null) throw new TimeException("Time de codigo " + cod + "n�o localizado!");
        return t;
    }
    
    public TreeSet getClassificacao() throws TimeException {
        Collection<Time> ts = this.times.values();
        for(Time t : ts){
            t.calcular();
        }
        TreeSet tree = new TreeSet(ts);
        return tree;
    }
   
}
