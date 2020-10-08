package bai3;

import java.text.DecimalFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

import javax.swing.text.DateFormatter;

public class GiaoDich {
	private String maGiaoDich;
	private LocalDate ngayGiaoDich;
	private double donGia;
	private int soLuong;

	public String getMaGiaoDich() {
		return maGiaoDich;
	}

	public void setMaGiaoDich(String maGiaoDich) throws Exception {
		if (maGiaoDich.trim().equals(""))
			throw new Exception("Ma giao dich rong");
		else
			this.maGiaoDich = maGiaoDich;
	}

	public LocalDate getNgayGiaoDich() {
		return ngayGiaoDich;
	}

	public void setNgayGiaoDich(LocalDate ngayGiaoDich) {
		this.ngayGiaoDich = ngayGiaoDich;
	}

	public double getDonGia() {
		return donGia;
	}

	public void setDonGia(double donGia) {
		if(donGia>0)
		this.donGia = donGia;
		else this.donGia=0;
	}

	public int getSoLuong() {
		return soLuong;
	}

	public void setSoLuong(int soLuong) {
		if(soLuong>0)
		this.soLuong = soLuong;
		else this.soLuong=0;
	}

	public GiaoDich(String maGiaoDich, LocalDate ngayGiaoDich, double donGia, int soLuong) throws Exception {
		super();
		setMaGiaoDich(maGiaoDich);
		setNgayGiaoDich(ngayGiaoDich);
		setDonGia(donGia);
		setSoLuong(soLuong);
	}

	public GiaoDich() {
		super();
	}
public double thanhTien() {
	return 0;
}
	@Override
	public String toString() {
		DateTimeFormatter p = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		DecimalFormat q = new DecimalFormat("#,##0");
		return String.format("ma giao dich:%-10s , ngay giao dich:%10s ,don gia:%10s ,so luong:%5d", maGiaoDich,
				ngayGiaoDich.format(p), q.format(donGia), soLuong);
	}

}
