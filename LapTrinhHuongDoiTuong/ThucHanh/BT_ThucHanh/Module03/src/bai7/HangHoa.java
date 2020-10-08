package bai7;

public abstract class HangHoa {

	private String maHang;
	private String tenHang;
	private double donGia;
	private int soLuongTon;

	public String getMaHang() {
		return maHang;
	}

	private void setMaHang(String maHang) throws Exception {
		if (maHang.equals(""))
			throw new Exception("Ma hang khong duoc rong!");
		else
			this.maHang = maHang;
	}

	public String getTenHang() {
		return tenHang;
	}

	public void setTenHang(String tenHang) {
		if (tenHang.equals(""))
			this.tenHang = "xxx";
		else
			this.tenHang = tenHang;
	}

	public double getDonGia() {
		return donGia;
	}

	public void setDonGia(double donGia) throws Exception {
		if (donGia < 0)
			throw new Exception("Don gia >=0!");
		else
			this.donGia = donGia;
	}

	public int getSoLuongTon() {
		return soLuongTon;
	}

	public void setSoLuongTon(int soLuongTon) throws Exception {
		if (soLuongTon < 0)
			throw new Exception("So luong >=0!");
		else
			this.soLuongTon = soLuongTon;
	}

	public HangHoa(String maHang, String tenHang, double donGia, int soLuongTon)
			throws Exception {
		setMaHang(maHang);
		setTenHang(tenHang);
		setDonGia(donGia);
		setSoLuongTon(soLuongTon);
	}

	public HangHoa() {

	}

	@Override
	public String toString() {
		return String
				.format("| MaHang:%10s | TenHang:%20s | DonGia:%15.0f | SoLuongTon:%5d |",
						maHang, tenHang, donGia, soLuongTon);
	}

	public abstract String danhGiaMucDoBanBuon();
}
