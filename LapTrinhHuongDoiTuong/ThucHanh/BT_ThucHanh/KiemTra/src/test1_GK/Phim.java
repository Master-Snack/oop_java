package test1_GK;

import java.text.DecimalFormat;

public class Phim {
	private int maPhim;
	private String tenPhim;
	private String tenDaoDien;
	private int soSuatChieu;
	private float giaSuatChieu;
	
	
	public int getMaPhim() {
		return maPhim;
	}
	public void setMaPhim(int maPhim) {
		if(maPhim < 1)
			this.maPhim = 999999;
		else
			this.maPhim = maPhim;
	}
	public String getTenPhim() {
		return tenPhim;
	}
	public void setTenPhim(String tenPhim) throws Exception {
		if(!tenPhim.trim().equals(""))
			this.tenPhim = tenPhim;
		else {
			this.tenPhim = "Chưa cập nhập!";
			throw new Exception("LỖI: Tên phim rỗng!");
		}
			
		
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
	public void setSoSuatChieu(int soSuatChieu) throws Exception {
		if(soSuatChieu>0)
			this.soSuatChieu = soSuatChieu;
		else
			throw new Exception("LỖI: Số suất chiếu phải > 0!");
		
	}
	public float getGiaSuatChieu() {
		return giaSuatChieu;
	}
	public void setGiaSuatChieu(float giaSuatChieu) {
		this.giaSuatChieu = giaSuatChieu;
	}

	
	public Phim() {
		super();
	}
	public Phim(int maPhim, String tenPhim, String tenDaoDien, int soSuatChieu, float giaSuatChieu) throws Exception {
		super();
		setMaPhim(maPhim);
		setTenPhim(tenPhim);
		setTenDaoDien(tenDaoDien);
		setSoSuatChieu(soSuatChieu);
		setSoSuatChieu(soSuatChieu);
		setGiaSuatChieu(giaSuatChieu);
	}
	
	
	public float getThanhTien() {
		return (getSoSuatChieu()*getGiaSuatChieu());
	}
	
	
	@Override
	public String toString() {
		DecimalFormat df = new DecimalFormat("#,###.### VNĐ");
		return String.format("%-10d |%-30s |%-30s |%15d |%15s |%15s",
				getMaPhim(), getTenPhim(), getTenDaoDien(), getSoSuatChieu(), df.format(getGiaSuatChieu()), df.format(getThanhTien()));
	}
}
