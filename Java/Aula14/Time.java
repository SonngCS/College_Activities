public class Time implements Comparable<Time> {
    
    private int codigo;
    private String nome;
    private int vitorias;
    private int empates;
    private int derrotas;
    private int jogos;
    private int pontos;
    
    public Time() {
        
    }
    
    public Time(int cod, String nome, int v, int e, int d, int j) {
        this.codigo = cod;
        this.nome = nome;
        this.vitorias=v;
        this.empates = e;
        this.derrotas = d;
        this.jogos = j;
    }
    
    public int calcular() throws TimeException {
        if(this.jogos != (this.vitorias+this.empates+this.derrotas)) {
            throw new TimeException("Quantidade de jogos com erro!");
        }
        this.pontos = (this.vitorias*3)+this.empates;
        return this.pontos;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getVitorias() {
        return vitorias;
    }

    public void setVitorias(int vitorias) {
        this.vitorias = vitorias;
    }

    public int getEmpates() {
        return empates;
    }

    public void setEmpates(int empates) {
        this.empates = empates;
    }

    public int getDerrotas() {
        return derrotas;
    }

    public void setDerrotas(int derrotas) {
        this.derrotas = derrotas;
    }

    public int getJogos() {
        return jogos;
    }

    public void setJogos(int jogos) {
        this.jogos = jogos;
    }

    public int getPontos() {
        return pontos;
    }

    public void setPontos(int pontos) {
        this.pontos = pontos;
    }

    @Override
    public int compareTo(Time o) {
        if(this.codigo == o.getCodigo()) {
            return 0;
        }
        else if(this.pontos <= o.getPontos()) {
            return 1;
        }
        else {
          return -1;
        }
    }
}
