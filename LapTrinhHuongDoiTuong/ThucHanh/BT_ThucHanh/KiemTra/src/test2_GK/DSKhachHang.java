package test2_GK;

public class DSKhachHang {
	private int count;
	private KhachHang[] MangKH;
	
	public DSKhachHang(int n) {
		MangKH = new KhachHang[n];
		count = 0;
	}
	
	public void xuatDSKH() {
		System.out.printf("|%15s |%-30s |%20s |%-20s\n", "Mã Khách Hàng", "Tên Khách Hàng", "Tổng tiền mua xe", "Mức độ Khách Hàng");
		for(int i=0; i<count; i++)
			System.out.println(MangKH[i].toString());
	}
	

	public boolean themKH(KhachHang khachHangm) {
		for(int i=0; i< count; i++)
			if(MangKH[i].getMaKH().equalsIgnoreCase(khachHangm.getMaKH()))
				return false;
		if(MangKH.length == count)
			return false;
		MangKH[count] = khachHangm;
		count ++;
		return true;
	}


	private int timKH(String khachHangx) {
		for(int i=0; i<count;i++)
			if(MangKH[i].getMaKH().equalsIgnoreCase(khachHangx))
				return i;
		return -1;
	}
	public void timTTKH(String khachHangx) {
		int kq = timKH(khachHangx);
		if(kq == -1)
			System.out.println("Không tìm thấy!");
		else {
			System.out.printf("|%15s |%-30s |%20s |%-20s\n", "Mã Khách Hàng", "Tên Khách Hàng", "Tổng tiền mua xe", "Mức độ Khách Hàng");
			System.out.println(MangKH[kq].toString());
		}
			
	}
	
	public void xoaKH(String khachHangx) {
		int kq = timKH(khachHangx);
		if(kq == -1)
			System.out.println("Không tìm thấy!");
		else {
			System.out.println("Xóa thành công!");
			for(int i=0; i<count; i++)
				if(MangKH[i].getMaKH().equalsIgnoreCase(khachHangx)) {
					for(int j= i+1; j<count; j++)
						MangKH[j-1] = MangKH[j];
					count--;
				}
		}	
	}
	
	public void sxTen() {
		for(int i=0; i<count -1; i++)
			for(int j=i+1; j<count; j++)
				if(MangKH[i].getHoTenKH().length() > MangKH[j].getHoTenKH().length())
				{
					KhachHang tamp = MangKH[i];
					MangKH[i] = MangKH[j];
					MangKH[j] = tamp;
				}
	}
	
	public void sxTongTien() {
		for(int i=0; i<count -1; i++)
			for(int j=i+1; j<count; j++)
				if(MangKH[i].getTongTienMuaXe() > MangKH[j].getTongTienMuaXe())
				{
					KhachHang tamp = MangKH[i];
					MangKH[i] = MangKH[j];
					MangKH[j] = tamp;
				}
	}
	
	public void xuatDSKHVIP() {
		System.out.printf("|%15s |%-30s |%20s |%-20s\n", "Mã Khách Hàng", "Tên Khách Hàng", "Tổng tiền mua xe", "Mức độ Khách Hàng");
		for(int i=0; i<count; i++)
			if(MangKH[i].getMucDoKH() == "VIP")
				System.out.println(MangKH[i].toString());
	}
}
