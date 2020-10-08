package bai5;

import java.time.LocalDate;

public class KhachHang {

	private String maKhachHang;
	private String hoTen;
	private LocalDate ngayLapHoaDon;
	private float soKWTieuThu;
	private double donGia;

	public String getMaKhachHang() {
		return maKhachHang;
	}

	public void setMaKhachHang(String maKhachHang) {
		this.maKhachHang = maKhachHang;
	}

	public String getHoTen() {
		return hoTen;
	}

	public void setHoTen(String hoTen) {
		this.hoTen = hoTen;
	}

	public LocalDate getNgayLapHoaDon() {
		return ngayLapHoaDon;
	}

	public void setNgayLapHoaDon(LocalDate ngayLapHoaDon) {
		this.ngayLapHoaDon = ngayLapHoaDon;
	}

	public float getSoKWTieuThu() {
		return soKWTieuThu;
	}

	public void setSoKWTieuThu(float soKWTieuThu) {
		this.soKWTieuThu = soKWTieuThu;
	}

	public double getDonGia() {
		return donGia;
	}

	public void setDonGia(double donGia) {
		this.donGia = donGia;
	}

	public KhachHang(String maKhachHang, String hoTen, LocalDate ngayLapHoaDon, float soKWTieuThu, double donGia) {
		setDonGia(donGia);
		setHoTen(hoTen);
		setMaKhachHang(maKhachHang);
		setNgayLapHoaDon(ngayLapHoaDon);
		setSoKWTieuThu(soKWTieuThu);
	}

	public KhachHang() {

	}

	/**
	 * 
	 * @return So KW tieu thu * Don gia
	 */
	public double thanhTien() {
		return soKWTieuThu * donGia;
	}

	/**
	 * 
	 * @return | Ma Khach Hang | Ho Ten | So KW Tieu Thu | Don Gia |
	 */
	public static String xuatKhoa() {
		return String.format("| %14s | %-30s | %14s | %15s |", "Ma Khach Hang", "Ho Ten", "So KW Tieu Thu", "Don Gia");
	}

	public String toString() {
		return String.format("| %14s | %-30s | %13.1f | %15.0f | ", maKhachHang, hoTen, soKWTieuThu, donGia);
	}

}
