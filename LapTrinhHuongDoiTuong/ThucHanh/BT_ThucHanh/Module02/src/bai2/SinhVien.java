package bai2;

public class SinhVien {

	private int MSSV;
	private String HoTen;
	private float DiemLT;
	private float DiemTH;
	public SinhVien() {
		this(0, "", 0.0f, 0.0f);
	}
	public SinhVien(int mssv, String hoten, float diemlt, float diemth) {
		setMSSV(mssv);
		setHoTen(hoten);
		setDiemLT(diemlt);
		setDiemTH(diemth);
	}
	public void setMSSV(int mssv) {
		if(mssv<0)
			this.MSSV=0;
		else
			this.MSSV= mssv;
	}
	public int getMSSV() {
		return MSSV;
	}
	public void setHoTen(String hoten) {
			this.HoTen=hoten;
	}
	public String getHoTen() {
		return HoTen;
	}
	public void setDiemLT(float diemlt) {
		if(diemlt >= 0 && diemlt <= 10)
			this.DiemLT = diemlt;
		else
			this.DiemLT=0;
	}
	public float getDiemLT() {
		return DiemLT;
	}
	public void setDiemTH(float diemth) {
		if(diemth >= 0 && diemth <= 10)
			this.DiemTH = diemth;
		else
			this.DiemTH=0;
	}
	public float getDiemTH() {
		return DiemTH;
	}
	public float getDiemTB() {
		return (DiemLT + DiemTH)/2;
	}
	public String toString() {
		return String.format("%-5d %-30s %10.3f %10.3f %10.3f", MSSV, HoTen, DiemLT, DiemTH, getDiemTB());
	}
}
