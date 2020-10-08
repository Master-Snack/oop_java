package bai1;

public class ChuyenXeNoiThanh extends ChuyenXe {
	private int soTuyen;
	private int soKm;

	public int getSoTuyen() {
		return soTuyen;
	}

	public void setSoTuyen(int soTuyen) {
		this.soTuyen = soTuyen;
	}

	public int getSoKm() {
		return soKm;
	}

	public void setSoKm(int soKm) {
		this.soKm = soKm;
	}

	public ChuyenXeNoiThanh() {
		super();
	}

	public ChuyenXeNoiThanh(String maSoChuyen, String hoTenTaiXe, int soXe, double doanhThu, int soTuyen, int soKm)
			{
		super(maSoChuyen, hoTenTaiXe, soXe, doanhThu);
		setSoTuyen(soTuyen);
		setSoKm(soKm);
	}

	@Override
	public String toString() {
		return String.format("Chuyen xe noi thanh[So tuyen:%d  ,So km:%d  %s]", soTuyen, soKm, super.toString());
	}

}
