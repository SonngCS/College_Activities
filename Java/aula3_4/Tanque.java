public class Tanque{
	private float volumeMax, volumeMin, volumeAtual;
	private boolean bomba;

	public void setVolumeMax(float vol){
		this.volumeMax = vol;
	}

	public float getVolumeMax(){
		return volumeMax;
	}

	public void setVolumeMin(float vol){
		this.volumeMin = vol;
	}

	public float getVolumeMin(){
		return volumeMin;
	}

	public void setVolumeAtual(float vol){
		this.volumeAtual = vol;
	}

	public float getVolumeAtual(){
		return this.volumeAtual;
	}

	public void setBomba(boolean bmb){
		this.bomba = bmb;
	}

	public boolean getBomba(){
		return bomba;
	}

	public void esvaziar(float qtd){
		setVolumeAtual(getVolumeAtual() - qtd);
		if(getVolumeAtual() <= getVolumeMin()){
			setBomba(true);
			setVolumeAtual(getVolumeMin());
		}
	}

	public void encher(float qtd){
		setVolumeAtual(getVolumeAtual() + qtd);
		if(getVolumeAtual() >= getVolumeMax()){
			setBomba(false);
			setVolumeAtual(getVolumeMax());
		}
	}

	public String exibirInfos(){
		String bmb = "Bomba ligada\n\n";
		if(!getBomba()){
			bmb = "Bomba desligada\n\n";
		}
		return ("Volume maximo: " + getVolumeMax() + "\nVolume minimo: "
		+ getVolumeMin() + "\nVolume atual: " + getVolumeAtual() + "\n"
		+ bmb);
	}
}
