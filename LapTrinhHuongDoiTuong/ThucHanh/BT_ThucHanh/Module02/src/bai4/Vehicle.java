package bai4;

public class Vehicle {
	private String TenChuXe;
	private String LoaiXe;
	private float TriGiaXe;
	private int DungTich;
	public Vehicle() {
		this("", "", 0.0f, 0);
	}
	public Vehicle(String tenchuxe, String loaixe, float trigiaxe, int dungtich) {
		setTenChuXe(tenchuxe);
		setLoaiXe(loaixe);
		setTriGiaXe(trigiaxe);
		setDungTich(dungtich);
	}
	public void setTenChuXe(String tenchuxe) {
		this.TenChuXe=tenchuxe;
	}
	public String getChuXe() {
		return TenChuXe;
	}
	public void setLoaiXe(String loaixe) {
		this.LoaiXe=loaixe;
	}
	public String getLoaiXe() {
		return LoaiXe;
	}
	public void setTriGiaXe(float trigiaxe) {
		if(trigiaxe<0)
			this.TriGiaXe=0.0f;
		else
			this.TriGiaXe=trigiaxe;
	}
	public float getTriGiaXe() {
		return TriGiaXe;
	}
	public void setDungTich(int dungtich) {
		if(dungtich<0)
			this.DungTich=0;
		else
			this.DungTich=dungtich;
	}
	public float getDungTich() {
		return DungTich;
	}
	public float getThue() {
		if(DungTich<100)
			return (TriGiaXe*0.01f);
		else if(DungTich<200)
			return (TriGiaXe*0.03f);
		return (TriGiaXe*0.05f);		
	}
	public String toString() {
		return String.format("%-30s %-25s %15d %15.3f %15.3f", TenChuXe, LoaiXe, DungTich, TriGiaXe, getThue());
	}
}
