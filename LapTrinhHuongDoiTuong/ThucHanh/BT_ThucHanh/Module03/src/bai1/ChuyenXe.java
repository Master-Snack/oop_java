package bai1;

public class ChuyenXe {
	private String maSoChuyen;
	private String hoTenTaiXe;
	private int soXe;
	private double doanhThu;

	public String getMaSoChuyen() {
		return maSoChuyen;
	}

	public void setMaSoChuyen(String maSoChuyen)  {
		
		this.maSoChuyen = maSoChuyen;
	}

	public String getHoTenTaiXe() {
		return hoTenTaiXe;
	}

	public void setHoTenTaiXe(String hoTenTaiXe) {
		
		this.hoTenTaiXe = hoTenTaiXe;
	}

	public int getSoXe() {
		return soXe;
	}

	public void setSoXe(int soXe) {
		this.soXe = soXe;
	}

	public double getDoanhThu() {
		return doanhThu;
	}

	public void setDoanhThu(double doanhThu) {
		this.doanhThu = doanhThu;
	}

	public ChuyenXe() {
		super();
	}

	public ChuyenXe(String maSoChuyen, String hoTenTaiXe, int soXe, double doanhThu) {
		super();
		setMaSoChuyen(maSoChuyen);
		setHoTenTaiXe(hoTenTaiXe);
		setSoXe(soXe);
		setDoanhThu(doanhThu);
	}

	@Override
	public String toString() {
		return String.format(",ma so chuyen:%s  ,Name:%s  ,So xe:%d  ,Doanh thu:%f", maSoChuyen, hoTenTaiXe, soXe,
				doanhThu);
	}

}
