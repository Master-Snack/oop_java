package test1_TH;

import java.text.DecimalFormat;

public class PhimNuocNgoai extends Phim {
	private String quocGia;
	private String chauLuc;
	
	public String getQuocGia() {
		return quocGia;
	}
	public void setQuocGia(String quocGia) {
		this.quocGia = quocGia;
	}
	public String getChauLuc() {
		return chauLuc;
	}
	public void setChauLuc(String chauLuc) {
		this.chauLuc = chauLuc;
	}

	public PhimNuocNgoai(String maPhim, String tenPhim, String tenDaoDien, int soSuatChieu, double giaSuatChieu) {
		super(maPhim, tenPhim, tenDaoDien, soSuatChieu, giaSuatChieu);
	}
	public PhimNuocNgoai(String maPhim, String tenPhim, String tenDaoDien, int soSuatChieu, double giaSuatChieu,
			String quocGia, String chauLuc) {
		super(maPhim, tenPhim, tenDaoDien, soSuatChieu, giaSuatChieu);
		setQuocGia(quocGia);
		setChauLuc(chauLuc);
	}
	public double doanhThu() {
		return getSoSuatChieu()*getGiaSuatChieu()*1.5;
	}
	
	public String toString() {
		DecimalFormat df = new DecimalFormat("#,###.0 VNĐ");
		return super.toString() + String.format("%-15s %-15s %15lf", getQuocGia(), getChauLuc(), df.format(doanhThu()));
	}
}
