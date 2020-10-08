package bai3;

import java.lang.Math;

public class TamGiac {
	private float ma;
	private float mb;
	private float mc;
	
	public TamGiac(){
	}
	public TamGiac(float a, float b, float c) {
		if((a < 0 || b < 0 || c < 0) || (KiemTra(a, b, c) == false)) {
			setCanhA(0);
			setCanhB(0);
			setCanhC(0);
		}	
		else {
			setCanhA(a);
			setCanhB(b);
			setCanhC(c);
		}
			
	}
	public boolean KiemTra (float da, float db, float dc) {
		if((da+db)>dc && (da+dc)>db && (db+dc)>da)
			return true;
		return false;
	}
	
	public void setCanhA(float a) {
		this.ma=a;
	}
	public float getCanhA() {
		return ma;
	}
	public void setCanhB(float b) {
		this.mb=b;
	}
	public float getCanhB() {
		return mb;
	}
	public void setCanhC(float c) {
		this.mc=c;
	}
	public float getCanhC() {
		return mc;
	}
	
	public float getChuVi(){
		return (ma + mb + mc)/2;
	}
	public double getDienTich() {
		return Math.sqrt((getChuVi()*(getChuVi()-ma)*getChuVi()*(getChuVi()-mb)*getChuVi()*(getChuVi()-mc)));
	}
	public String KieuTamGiac() {
		if(KiemTra(ma,mb,mc)==false)
			return "Không phải là tam giác";
		else {
			if(ma==mb && ma==mc || mb==ma && mb==mc || mc==ma && mc==mb)
				return "Tam giác đều";
			else if(ma==mb || ma==mc || mb==mc)
				return "Tam giác cân";
			else
				return "Tam giác thường";
		}
							
	}
	@Override
	public String toString() {
		return String.format("%10.2f %10.2f %10.2f %-30s %10.2f %10.2f", getCanhA(), getCanhB(), getCanhC(), KieuTamGiac(), getChuVi(), getDienTich());
	}
	
	

}
