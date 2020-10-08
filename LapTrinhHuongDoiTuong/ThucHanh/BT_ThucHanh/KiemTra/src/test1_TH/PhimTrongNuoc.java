package test1_TH;

import java.text.DecimalFormat;

public class PhimTrongNuoc extends Phim {
	private String theLoai;

	public String getTheLoai() {
		return theLoai;
	}
	public void setTheLoai(String theLoai) {
		this.theLoai = theLoai;
	}
		
	public PhimTrongNuoc(String maPhim, String tenPhim, String tenDaoDien, int soSuatChieu, double giaSuatChieu) {
		super(maPhim, tenPhim, tenDaoDien, soSuatChieu, giaSuatChieu);
	}
	public PhimTrongNuoc(String maPhim, String tenPhim, String tenDaoDien, int soSuatChieu, double giaSuatChieu,
			String theLoai) {
		super(maPhim, tenPhim, tenDaoDien, soSuatChieu, giaSuatChieu);
		this.theLoai = theLoai;
	}
	
	public double doanhThu() {
		return getSoSuatChieu()* getGiaSuatChieu();
	}
	
	public String toString() {
		DecimalFormat df = new DecimalFormat("#,###.0 VNĐ");
		return super.toString() + String.format("%-15s %15lf", getTheLoai(), df.format(doanhThu()));
	}
	
}
