import java.lang.Math.*;

public class Pi{

	private double pi = Math.PI;

	public double getPiDouble(){
		return pi;
	}

	public int getPiInt(){
		return (int) pi;
	}

	public float getPiFloat(){
		return (float) pi;
	}

	public String getPiString(){
		return String.valueOf(pi);
	}

	public static void main(String[] args){
		Pi pi1 = new Pi();

		System.out.println(pi1.getPiDouble() + " " + pi1.getPiInt() + " " + pi1.getPiFloat() + " " + pi1.getPiString());
	
	}
}
