package bai8;

import java.text.DecimalFormat;
import java.util.*;
public class CD {
	private int MaCD;
	private String tuaCD;
	private String casy;
	private int sobaihat;
	private double giathanh;
	public CD(int maCD, String tuaCD, String casy, int sobaihat, double giathanh) {
		super();
		MaCD = maCD;
		this.tuaCD = tuaCD;
		this.casy = casy;
		this.setSobaihat(sobaihat);
		this.setGiathanh(giathanh);
	}
	public CD() {
		this(0,"","",0,0);
	}
	public int getMaCD() {
		return MaCD;
	}
	public void setMaCD(int maCD) {
		MaCD = maCD;
	}
	public String getTuaCD() {
		return tuaCD;
	}
	public void setTuaCD(String tuaCD) {
		this.tuaCD = tuaCD;
	}
	public String getCasy() {
		return casy;
	}
	public void setCasy(String casy) {
		this.casy = casy;
	}
	public int getSobaihat() {
		return sobaihat;
	}
	public void setSobaihat(int sobaihat) {
		if (sobaihat>0)
			this.sobaihat = sobaihat;
		else 
			this.sobaihat = 0;
	}
	public double getGiathanh() {
		return giathanh;
	}
	public void setGiathanh(double giathanh) {
		this.giathanh = giathanh;
	}
	public String toString(){
		DecimalFormat df = new DecimalFormat("#,###.0");
		return String.format("%d%30s%15s%15d%25s", MaCD, tuaCD, casy, sobaihat, df.format(giathanh));
		
	}
}