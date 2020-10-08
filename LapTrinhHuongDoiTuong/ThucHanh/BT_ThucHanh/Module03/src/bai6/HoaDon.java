package bai6;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public abstract class HoaDon {

	private String maHoaDon;
	private LocalDate ngayLapHoaDon;
	private String tenKhachHang;
	private String maPhong;
	private double donGia;

	public String getMaHoaDon() {
		return maHoaDon;
	}

	public void setMaHoaDon(String maHoaDon) {
		this.maHoaDon = maHoaDon;
	}

	public LocalDate getNgayLapHoaDon() {
		return ngayLapHoaDon;
	}

	public void setNgayLapHoaDon(LocalDate ngayLapHoaDon) {
		this.ngayLapHoaDon = ngayLapHoaDon;
	}

	public String getTenKhachHang() {
		return tenKhachHang;
	}

	public void setTenKhachHang(String tenKhachHang) {
		this.tenKhachHang = tenKhachHang;
	}

	public String getMaPhong() {
		return maPhong;
	}

	public void setMaPhong(String maPhong) {
		this.maPhong = maPhong;
	}

	public double getDonGia() {
		return donGia;
	}

	public void setDonGia(double donGia) {
		this.donGia = donGia;
	}

	public HoaDon(String maHoaDon, LocalDate ngayLapHoaDon, String tenKhachHang, String maPhong, double donGia) {
		setDonGia(donGia);
		setMaHoaDon(maHoaDon);
		setMaPhong(maPhong);
		setNgayLapHoaDon(ngayLapHoaDon);
		setTenKhachHang(tenKhachHang);
	}

	public HoaDon() {

	}

	public abstract double thanhTien();

	DateTimeFormatter dateform = DateTimeFormatter.ofPattern("dd/MM/yyyy");

	public String toString() {
		return String.format("| MaHoaDon:%9s | NgayHoaDon:%11s | TenKhachHang:%20s | MaPhong:%5s | DonGia:%5.0f |",
				maHoaDon, dateform.format(ngayLapHoaDon), tenKhachHang, maPhong, donGia);
	}
}
