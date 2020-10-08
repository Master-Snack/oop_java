package bai7;

import java.time.LocalDate;

public class HangSanhSu extends HangHoa {

	private String nhaSanXuat;
	private LocalDate ngayNhap;

	public String getNhaSanXuat() {
		return nhaSanXuat;
	}

	public void setNhaSanXuat(String nhaSanXuat) {
		this.nhaSanXuat = nhaSanXuat;
	}

	public LocalDate getNgayNhap() {
		return ngayNhap;
	}

	public void setNgayNhap(LocalDate ngayNhap) {
		if (ngayNhap.isAfter(LocalDate.now()))
			this.ngayNhap = LocalDate.now();
		else
			this.ngayNhap = ngayNhap;
	}

	public HangSanhSu() {
		super();
	}

	public HangSanhSu(String maHang, String tenHang, double donGia,
			int soLuongTon, String nhaSanXuat, LocalDate ngayNhap)
			throws Exception {
		super(maHang, tenHang, donGia, soLuongTon);
		setNhaSanXuat(nhaSanXuat);
		setNgayNhap(ngayNhap);
	}

	public boolean soNgayTonKhoLonHon10() {
		int d,d1;
		d=ngayNhap.getDayOfYear();
		d1=LocalDate.now().getDayOfYear();
		if(d1-d>10&&ngayNhap.getYear()==LocalDate.now().getYear())return true;
		else return false;
	}
	@Override
	public String danhGiaMucDoBanBuon() {
		String s="";
		if(super.getSoLuongTon()>50&&soNgayTonKhoLonHon10());
			return "";
	}
}
