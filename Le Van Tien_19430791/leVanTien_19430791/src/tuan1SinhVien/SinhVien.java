package tuan1SinhVien;

public class SinhVien {
	private int maSinhVien;
	private float diemLT, diemTH;
	private String hoTen;
	
	public int getMaSinhVien() {
		return maSinhVien;
	}
	public void setMaSinhVien(int maSinhVien) {
		if(maSinhVien > 0)
			this.maSinhVien = maSinhVien;
	}
	
	public float getDiemLT() {
		return diemLT;
	}
	public void setDiemLT(float diemLT) {
		if(diemLT >=0 && diemLT <= 10)
			this.diemLT = diemLT;
		else
			this.diemLT = 0;
	}
	
	public float getDiemTH() {
		return diemTH;
	}
	public void setDiemTH(float diemTH) {
		if(diemTH >=0 && diemTH <= 10)
			this.diemTH = diemTH;
		else
			this.diemTH = 0;
	}
	
	public String getHoTen() {
		return hoTen;
	}
	public void setHoTen(String hoTen) {
		if(hoTen != null)
			this.hoTen = hoTen;
	}
	
	public SinhVien() {

	}
	public SinhVien(int maSinhVien, float diemLT, float diemTH, String hoTen) {
		super();
		this.maSinhVien = maSinhVien;
		this.diemLT = diemLT;
		this.diemTH = diemTH;
		this.hoTen = hoTen;
	}
	
	public float tinhDiemTB() {
		return (getDiemLT() + getDiemTH())/2;
	}

	@Override
	public String toString() {
		String s = "";
		s+= String.format("%15d%25s%10.2f%10.2f%10.2f", getMaSinhVien(),getHoTen(),getDiemLT(),getDiemTH(),tinhDiemTB());
		return s;
	}
}
