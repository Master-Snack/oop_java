package bai5;

import java.time.LocalDate;

public class KhachHangVN extends KhachHang {

	// 1: Khach hang sinh hoat; 2: Khach hang kinh doanh; 3: Khach hang san xuat;
	private int doiTuongKhachHang;
	private int dinhMuc;

	public int getDoiTuongKhachHang() {
		return doiTuongKhachHang;
	}

	public void setDoiTuongKhachHang(int doiTuongKhachHang) {
		this.doiTuongKhachHang = doiTuongKhachHang;
	}

	public int getDinhMuc() {
		return dinhMuc;
	}

	public void setDinhMuc(int dinhMuc) {
		this.dinhMuc = dinhMuc;
	}

	/**
	 * 
	 * @param maKhachHang
	 * @param hoTen
	 * @param ngayLapHoaDon
	 * @param soKWTieuThu
	 * @param donGia
	 * @param doiTuongKhachHang 1: Khach hang sinh hoat; 2: Khach hang kinh doanh;
	 *                          3: Khach hang san xuat;
	 * @param dinhMuc
	 */
	public KhachHangVN(String maKhachHang, String hoTen, LocalDate ngayLapHoaDon, float soKWTieuThu, double donGia,
			int doiTuongKhachHang, int dinhMuc) {
		super(maKhachHang, hoTen, ngayLapHoaDon, soKWTieuThu, donGia);
		setDinhMuc(dinhMuc);
		setDoiTuongKhachHang(doiTuongKhachHang);
	}

	public KhachHangVN() {
		super();
	}

	/**
	 * náº¿u sá»‘ KW tiÃªu thá»¥ <= Ä?á»‹nh má»©c return (Sá»‘ KW tiÃªu thá»¥ * Ä?Æ¡n giÃ¡)
	 * <p>
	 * NgÆ°á»£c láº¡i return (Ä?Æ¡n giÃ¡ * Ä?á»‹nh má»©c)+(Sá»‘ KW tiÃªu thá»¥ vÆ°á»£t quÃ¡ Ä‘á»‹nh má»©c * Ä?Æ¡n
	 * giÃ¡ *2.5)
	 */
	@Override
	public double thanhTien() {
		if (super.getSoKWTieuThu() <= dinhMuc)
			return super.getSoKWTieuThu() * super.getDonGia();
		else
			return (super.getDonGia() * dinhMuc) + ((super.getSoKWTieuThu() - dinhMuc) * super.getDonGia() * 5/2);
	}

	/**
	 * @return | Ma Khach Hang | Ho Ten | So KW Tieu Thu | Don Gia | Doi tuong khach
	 * hang | Dinh muc |
	 */
	public static String xuatKhoa() {
		return String.format("%s %20s | %15s |", KhachHang.xuatKhoa(), "Doi tuong khach hang", "Dinh muc");
	}

	@Override
	public String toString() {
		String s;
		if (doiTuongKhachHang == 1)
			s = "Sinh hoat";
		else if (doiTuongKhachHang == 2)
			s = "Kinh doanh";
		else
			s = "San xuat";
		return String.format("%s %20s | %15d |", super.toString(), s, dinhMuc);
	}
}
