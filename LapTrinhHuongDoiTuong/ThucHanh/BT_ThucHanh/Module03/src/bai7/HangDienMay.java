package bai7;

public class HangDienMay extends HangHoa {

	private int thoiGianBaoHanh;
	private int congSuat;

	public int getThoiGianBaoHanh() {
		return thoiGianBaoHanh;
	}

	public void setThoiGianBaoHanh(int thoiGianBaoHanh) {
		if (thoiGianBaoHanh < 0)
			this.thoiGianBaoHanh = 0;
		else
			this.thoiGianBaoHanh = thoiGianBaoHanh;
	}

	public int getCongSuat() {
		return congSuat;
	}

	public void setCongSuat(int congSuat) {
		if (congSuat < 0)
			this.congSuat = 0;
		else
			this.congSuat = congSuat;
	}

	public HangDienMay(String maHang, String tenHang, double donGia,
			int soLuongTon, int thoiGianBaoHanh, int congSuat) throws Exception {
		super(maHang, tenHang, donGia, soLuongTon);
		setThoiGianBaoHanh(thoiGianBaoHanh);
		setCongSuat(congSuat);
	}

	public HangDienMay() {
		super();
	}

	@Override
	public String toString() {
		return String.format("%s ThoiGianBaoHanh:%2d | CongSuat:%10d |",
				super.toString(), thoiGianBaoHanh, congSuat);
	}

	@Override
	public String danhGiaMucDoBanBuon() {
		String s = "";
		if (super.getSoLuongTon() < 3)
			s = "Ban duoc";
		return s;
	}
}
