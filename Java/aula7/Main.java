import weapons.Arma;
import weapons.Disparavel;
import weapons.Faca;
import weapons.Lancachama;
import weapons.Revolver;

public class Main {
   public static void main(String args[]){
       Faca f = new Faca(8.9);
       System.out.println("Dano causado: " + agredir(f));
       System.out.println("Dano causado: " + agredir(f));
       System.out.println("Dano causado: " + agredir(f));
       System.out.println("Dano causado: " + agredir(f));
       System.out.println("Dano causado: " + agredir(f));
       System.out.println("Dano causado: " + agredir(f));
       System.out.println("Dano causado: " + agredir(f));
       System.out.println(f.infos());

       Revolver r = new Revolver(3, 50);
       System.out.println("Dano causado pela coronhada: " + agredir(r));
       System.out.println("Dano causado pelo disparo: " + atirar(r));
       System.out.println("Dano causado pelo disparo: " + atirar(r));
       System.out.println("Dano causado pelo disparo: " + atirar(r));
       System.out.println("Dano causado pelo disparo: " + atirar(r));
       System.out.println(r.infos());
       r.recarregar();
       System.out.println(r.infos());

       Lancachama l = new Lancachama(40, 100);
       agredir(l);
       System.out.println("Dano causado pelas chamas: " + atirar(l));
       System.out.println("Dano causado pelas chamas: " + atirar(l));
       System.out.println("Dano causado pelas chamas: " + atirar(l));
       System.out.println("Dano causado pelas chamas: " + atirar(l));
       System.out.println("Dano causado pelas chamas: " + atirar(l));
       System.out.println(l.infos());
       l.recarregar();
       System.out.println(l.infos());
   }

   private static double agredir(Arma a){
       return a.golpear();
   }

   private static double atirar(Disparavel d){
        return d.disparar();
   }
}
