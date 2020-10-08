package bai6;

import java.time.LocalDate;

public class HoaDonTheoGio extends HoaDon {

	private int soGioChoThue;

	public int getSoGioChoThue() {
		return soGioChoThue;
	}

	public void setSoGioChoThue(int soGioChoThue) throws Exception {

		if (soGioChoThue > 30)
			throw new Exception("Loi:So gio qua qui dinh theo hoa don theo gio");
		else
			this.soGioChoThue = soGioChoThue;
	}

	public HoaDonTheoGio(String maHoaDon, LocalDate ngayLapHoaDon, String tenKhachHang, String maPhong, double donGia,
			int soGioChoThue) throws Exception {
		super(maHoaDon, ngayLapHoaDon, tenKhachHang, maPhong, donGia);
		setSoGioChoThue(soGioChoThue);
	}

	public HoaDonTheoGio() {
		super();
	}

	@Override
	public double thanhTien() {
		if (soGioChoThue < 24)
			return soGioChoThue * super.getDonGia();
		else
			return 24 * super.getDonGia();
	}

	@Override
	public String toString() {
		return String.format("%s SoGioChoThue:%2d |", super.toString(), soGioChoThue);
	}
}
