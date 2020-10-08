package bai5;

import java.time.LocalDate;

public class KhachHangNgoaiQuoc extends KhachHang {

	private String quocTich;

	public String getQuocTich() {
		return quocTich;
	}

	public void setQuocTich(String quocTich) {
		this.quocTich = quocTich;
	}

	public KhachHangNgoaiQuoc(String maKhachHang, String hoTen, LocalDate ngayLapHoaDon, float soKWTieuThu,
			double donGia, String quocTich) {
		super(maKhachHang, hoTen, ngayLapHoaDon, soKWTieuThu, donGia);
		setQuocTich(quocTich);
	}

	public KhachHangNgoaiQuoc() {
		super();
	}

	@Override
	public double thanhTien() {
		return super.getDonGia() * super.getSoKWTieuThu();
	}

	/**
	 * 
	 * @return | Ma Khach Hang | Ho Ten | So KW Tieu Thu | Don Gia | Quoc tich |
	 */
	public static String xuatKhoa() {
		return String.format("%s %-15s |", KhachHang.xuatKhoa(), "Quoc tich");
	}

	@Override
	public String toString() {
		return String.format("%s %-15s |", super.toString(), quocTich);
	}
}
