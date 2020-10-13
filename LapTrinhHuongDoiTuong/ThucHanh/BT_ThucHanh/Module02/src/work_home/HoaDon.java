package work_home;

import java.util.Scanner;
import java.util.ArrayList;

public class HoaDon {
	String ma_sp, mo_ta;
	int so_luong;
	double don_gia, thanh_tien, tong_tien;
	public HoaDon() {
	}
	public HoaDon(String ma_sp, String mo_ta, int so_luong, double don_gia, double tong_tien) {
		this.ma_sp = ma_sp;
		this.mo_ta = mo_ta;
		this.so_luong = so_luong;
		this.don_gia = don_gia;
		this.tong_tien = tong_tien;
	}
	public String getMa_sp() {
		return ma_sp;
	}
	public void setMa_sp(String ma_sp) {
		this.ma_sp = ma_sp;
	}
	public String getMo_ta() {
		return mo_ta;
	}
	public void setMo_ta(String mo_ta) {
		this.mo_ta = mo_ta;
	}
	public int getSo_luong() {
		return so_luong;
	}
	public void setSo_luong(int so_luong) {
		this.so_luong = so_luong;
	}
	public double getDon_gia() {
		return don_gia;
	}
	public void setDon_gia(double don_gia) {
		this.don_gia = don_gia;
	}
	public double getThanh_tien() {
		thanh_tien = getDon_gia() * getSo_luong();
		return thanh_tien;
	}
	public void setThanh_tien(double thanh_tien) {
		this.thanh_tien = thanh_tien;
	}
	public double getTong_tien() {
		return tong_tien;
	}
	public void setTong_tien(double tong_tien) {
		this.tong_tien = tong_tien;
	}
	
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap vao ma san pham: ");
		ma_sp = sc.nextLine();
		System.out.println("Nhap vao mo ta san pham: ");
		mo_ta = sc.nextLine();
		System.out.println("Nhap vao don gia san pham: ");
		don_gia = Double.parseDouble(sc.nextLine());
		System.out.println("Nhap vao so luong san pham: ");
		so_luong = Integer.parseInt(sc.nextLine());
	}
	@Override
	public String toString() {
		return ma_sp + "      |" + mo_ta + "             |" + don_gia + "         |" + so_luong
				+ "		|" + getThanh_tien();
	}
	
	
}
