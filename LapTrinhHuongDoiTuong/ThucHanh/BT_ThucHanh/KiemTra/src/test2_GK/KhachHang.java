package test2_GK;

import java.text.DecimalFormat;

public class KhachHang {
	private String maKH;
	private String hoTenKH;
	private long tongTienMuaXe;
	private String mucDoKH;
	
	
	public String getMaKH() {
		return maKH;
	}
	public void setMaKH(String maKH) throws Exception {
		if(!maKH.trim().equals(""))
			this.maKH = maKH;
		else
			throw new Exception("LỖI: Mã khách hàng trống!");
	}
	public String getHoTenKH() {
		return hoTenKH;
	}
	public void setHoTenKH(String hoTenKH) throws Exception {
		if(!hoTenKH.trim().equals(""))
			this.hoTenKH = hoTenKH;
		else
			throw new Exception("LỖI: Tên khách hàng trống!");
	}
	public long getTongTienMuaXe() {
		return tongTienMuaXe;
	}
	public void setTongTienMuaXe(long tongTienMuaXe) throws Exception {
		if(tongTienMuaXe<=0)
			throw new Exception("LỖI: Tổng tiền mua xe phải > 0!");
		else
			this.tongTienMuaXe = tongTienMuaXe;
	}
	public String getMucDoKH() {
		setMucDoKH();
		return mucDoKH;
	}
	private void setMucDoKH() {
		if(getTongTienMuaXe()<1000000000)
			this.mucDoKH = "Thông thường";
		else if(getTongTienMuaXe()<=2000000000)
			this.mucDoKH = "Tiềm năng";
		else
			this.mucDoKH = "VIP";
		
	}
	
	
	public KhachHang() {
		super();
	}
	public KhachHang(String maKH, String hoTenKH, long tongTienMuaXe) throws Exception {
		super();
		setMaKH(maKH);
		setHoTenKH(hoTenKH);
		setTongTienMuaXe(tongTienMuaXe);
	}
	
	
	public String toString() {
		DecimalFormat df = new DecimalFormat("#,###");
		return String.format("|%15s |%-30s |%20s |%-20s", getMaKH(), getHoTenKH(), df.format(getTongTienMuaXe()), getMucDoKH());
	}
	
}
