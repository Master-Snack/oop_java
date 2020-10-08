package bai6;

import java.time.LocalDate;

public class HoaDonTheoNgay extends HoaDon {

	private int soNgayChoThue;

	public int getSoNgayChoThue() {
		return soNgayChoThue;
	}

	public void setSoNgayChoThue(int soNgayChoThue) {
		this.soNgayChoThue = soNgayChoThue;
	}

	/**
	 * 
	 * @param maHoaDon
	 * @param ngayLapHoaDon
	 * @param tenKhachHang
	 * @param maPhong
	 * @param donGia
	 * @param soNgayChoThue
	 */
	public HoaDonTheoNgay(String maHoaDon, LocalDate ngayLapHoaDon, String tenKhachHang, String maPhong, double donGia,
			int soNgayChoThue) {
		super(maHoaDon, ngayLapHoaDon, tenKhachHang, maPhong, donGia);
		setSoNgayChoThue(soNgayChoThue);
	}

	public HoaDonTheoNgay() {
		super();
	}

	@Override
	public double thanhTien() {
		if (soNgayChoThue <= 7)
			return super.getDonGia() * soNgayChoThue;
		else
			return (7 * super.getDonGia()) + ((soNgayChoThue - 7) * super.getDonGia() * 80) / 100;
	}

	@Override
	public String toString() {
		return String.format("%s SoNgayChoThue:%3d |", super.toString(), soNgayChoThue);
	}
}
