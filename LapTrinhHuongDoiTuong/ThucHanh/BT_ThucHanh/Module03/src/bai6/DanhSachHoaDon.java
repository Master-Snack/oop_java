package bai6;

public class DanhSachHoaDon {

	private HoaDon danhSach[];
	private int count;

	public DanhSachHoaDon(int count) {
		danhSach = new HoaDon[count];
		this.count = 0;
	}

	/**
	 * 
	 * @param hd
	 * @return false: neu them that bai | true: neu them thanh cong
	 */
	public boolean them(HoaDon hd) {
		if (count < danhSach.length) {
			for (int i = 0; i < count; i++) {
				if (danhSach[i].getMaHoaDon().equalsIgnoreCase(hd.getMaHoaDon()))
					return false;
			}
			danhSach[count] = hd;
			count++;
			return true;
		} else
			return false;
	}

	/**
	 * int ra danh sach hoa don | moi hoa don tren 1 dong
	 */
	public void xuat() {
		for (int i = 0; i < count; i++) {
			System.out.println(danhSach[i]);
		}
	}

	/**
	 * 
	 * @return so hoa don theo gio trong danh sach
	 */
	public int thongKeSoLuongHDTheoGio() {
		int dem = 0;
		for (int i = 0; i < count; i++) {
			if (danhSach[i] instanceof HoaDonTheoGio)
				dem++;
		}
		return dem;
	}

	/**
	 * 
	 * @return so hoa don theo ngay trong danh sach
	 */
	public int thongKeSoLuongHDTheoNgay() {
		int dem = 0;
		for (int i = 0; i < count; i++) {
			if (danhSach[i] instanceof HoaDonTheoNgay)
				dem++;
		}
		return dem;
	}

	/**
	 * 
	 * @param year
	 * @param month
	 * @return Tong tien trong month/year
	 */
	public double tinhTongThanhTien(int year, int month) {
		double tongTien = 0;
		for (int i = 0; i < count; i++) {
			if (danhSach[i].getNgayLapHoaDon().getMonthValue() == month
					&& danhSach[i].getNgayLapHoaDon().getYear() == year)
				tongTien += danhSach[i].thanhTien();
		}
		return tongTien;
	}
}
