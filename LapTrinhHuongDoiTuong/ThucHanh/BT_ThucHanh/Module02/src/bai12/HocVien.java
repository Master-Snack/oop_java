package bai12;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Scanner;

public class HocVien {
	private String hoTen;
	private String diaChi;
	private int soDienThoai;
	
	public HocVien() {
	}
	public HocVien(String hoTen, String diaChi, int soDienThoai) {
		setHoTen(hoTen);
		setDiaChi(diaChi);
		setSoDienThoai(soDienThoai);
	}

	public String getHoTen() {
		return hoTen;
	}
	public void setHoTen(String hoTen) {
		if(!hoTen.trim().equals(""))
			this.hoTen = hoTen;
		else
			this.hoTen = "Chưa xác định!";
	}
	public String getDiaChi() {
		return diaChi;
	}
	public void setDiaChi(String diaChi) {
		if(!diaChi.trim().equals(""))
			this.diaChi = diaChi;
		else
			this.diaChi = "Chưa xác định!";
	}
	public int getSoDienThoai() {
		return soDienThoai;
	}
	public void setSoDienThoai(int soDienThoai) {
		if(soDienThoai>0)
			this.soDienThoai = soDienThoai;
		else
			this.soDienThoai = 0;
	}

	public void nhapThongTin() {
		Scanner sc = new Scanner(System.in);
		HocVien newHV = new HocVien();
		System.out.println("Nhập họ tên của Học viên: ");
		String hoTen = sc.nextLine();
		System.out.println("Nhập địa chỉ của Học viên: ");
		String diaChi = sc.nextLine();
		System.out.println("Nhập số điện thoại của Học viên: ");
		int soDienThoai = sc.nextInt();
		
		setHoTen(hoTen);
		setDiaChi(diaChi);
		setSoDienThoai(soDienThoai);
	}
	
	public String toString() {
		DecimalFormat df = new DecimalFormat("###,###");
		return String.format("|%-30s |%-30s |0%9s", getHoTen(), getDiaChi(), df.format(getSoDienThoai()));
	}
	
}
