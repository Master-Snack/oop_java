package bai7;
import java.lang.Math;
public class HinhTron {
	private ToaDo tam;
	private double banKinh;
	public ToaDo getTam() {
		return tam;
	}
	public void setTam(ToaDo tam) {
		this.tam = tam;
	}
	public double getBanKinh() {
		return banKinh;
	}
	public void setBanKinh(double banKinh) {
		this.banKinh = banKinh;
	}
	public HinhTron(ToaDo tam, double banKinh) {
		super();
		setBanKinh(banKinh);
		setTam(tam);
	}
	public HinhTron() {
		
	}
	public double tinhChuVi() {
		return 2*getBanKinh()*Math.PI;
	}
	public double tinhDienTich()
	{
		return getBanKinh()*getBanKinh()*Math.PI;
	}
}
