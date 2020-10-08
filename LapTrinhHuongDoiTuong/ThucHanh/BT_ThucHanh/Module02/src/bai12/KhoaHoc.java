package bai12;

public class KhoaHoc {
	private String tenKhoaHoc;
	private String ngayMoKhoaHoc;
	private String thoiGianHoc;
	private HocVien[] DSHV;
	
	public String getTenKhoaHoc() {
		return tenKhoaHoc;
	}
	public void setTenKhoaHoc(String tenKhoaHoc) {
		if(!tenKhoaHoc.trim().equals(""))
			this.tenKhoaHoc = tenKhoaHoc;
		else
			this.tenKhoaHoc = "Chưa xác định!";
	}
	public String getNgayMoKhoaHoc() {
		return ngayMoKhoaHoc;
	}
	public void setNgayMoKhoaHoc(String ngayMoKhoaHoc) {
		this.ngayMoKhoaHoc = ngayMoKhoaHoc;
	}
	public String getThoiGianHoc() {
		return thoiGianHoc;
	}
	public void setThoiGianHoc(String thoiGianHoc) {
		this.thoiGianHoc = thoiGianHoc;
	}
	public HocVien[] getDSHV() {
		return DSHV;
	}
	public void setDSHV(HocVien[] dSHV) {
		DSHV = dSHV;
	}
	
	
}