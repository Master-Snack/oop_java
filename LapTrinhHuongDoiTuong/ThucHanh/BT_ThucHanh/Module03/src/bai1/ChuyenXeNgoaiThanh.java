package bai1;

public class ChuyenXeNgoaiThanh extends ChuyenXe{
	private String noiDen;
	private int soNgayDiDuoc;
	public String getNoiDen() {
		return noiDen;
	}
	public void setNoiDen(String noiDen) {
		this.noiDen = noiDen;
	}
	public int getSoNgayDiDuoc() {
		return soNgayDiDuoc;
	}
	public void setSoNgayDiDuoc(int soNgayDiDuoc) {
		this.soNgayDiDuoc = soNgayDiDuoc;
	}
	
	public ChuyenXeNgoaiThanh() {
		super();
	}
	public ChuyenXeNgoaiThanh(String maSoChuyen, String hoTenTaiXe, int soXe, double doanhThu, String noiDen,
			int soNgayDiDuoc) {
		super(maSoChuyen, hoTenTaiXe, soXe, doanhThu);
		setNoiDen(noiDen);
		setSoNgayDiDuoc(soNgayDiDuoc);
	}
	@Override
	public String toString() {
		return String.format("Chuyen xe ngoai thanh[noi den:%s  ,so ngay di duoc:%d  %s]",noiDen,soNgayDiDuoc,super.toString());
	}
	

}
