package test1_TH;

import java.text.DecimalFormat;

public abstract class Phim {
	private  String maPhim;
	private  String tenPhim;
	private  String tenDaoDien;
	private  int soSuatChieu;
	private  double giaSuatChieu;
	
	public String getMaPhim() {
		return maPhim;
	}
	public void setMaPhim(String maPhim) {
		this.maPhim = maPhim;
	}
	public String getTenPhim() {
		return tenPhim;
	}
	public void setTenPhim(String tenPhim) {
		if(tenPhim.trim().equals(""))
			this.tenPhim = "chưa cập nhập";
		else
			this.tenPhim = tenPhim;
	}
	public String getTenDaoDien() {
		return tenDaoDien;
	}
	public void setTenDaoDien(String tenDaoDien) {
		this.tenDaoDien = tenDaoDien;
	}
	public int getSoSuatChieu() {
		return soSuatChieu;
	}
	public void setSoSuatChieu(int soSuatChieu) {
		if(soSuatChieu<=0)
			this.soSuatChieu = 0;
		else
			this.soSuatChieu = soSuatChieu;
	}
	public double getGiaSuatChieu() {
		return giaSuatChieu;
	}
	public void setGiaSuatChieu(double giaSuatChieu) {
		if(giaSuatChieu<=0)
			this.giaSuatChieu =0;
		else
			this.giaSuatChieu = giaSuatChieu;
	}
	public Phim(String maPhim, String tenPhim, String tenDaoDien, int soSuatChieu, double giaSuatChieu) {
		super();
		setMaPhim(maPhim);
		setTenPhim(tenPhim);
		setTenDaoDien(tenDaoDien);
		setSoSuatChieu(soSuatChieu);
		setGiaSuatChieu(giaSuatChieu);
	}
	public Phim() {
		super();
	}
	public abstract double doanhThu();
	
	public String toString() {
		DecimalFormat df = new DecimalFormat("#,###.0 VNĐ");	
		return String.format("%-10s %-30s %-30s %5d %15lf", getMaPhim(), getTenPhim(), getTenDaoDien(), getSoSuatChieu(), df.format(getGiaSuatChieu()));
	}
	
}
