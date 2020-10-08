package bai10;

import java.util.ArrayList;
import java.util.Scanner;

public class HoaDon {
	String maSP, moTa;
	int soLuong;
	double donGia, thanhTien, tongThanhTien;
	public HoaDon() {
		super();
	
	}
	public HoaDon(String maSP, String moTa, int soLuong, double donGia, double tongThanhTien) {
		super();
		this.maSP = maSP;
		this.moTa = moTa;
		this.soLuong = soLuong;
		this.donGia = donGia;
		this.tongThanhTien = tongThanhTien;
	}
	public String getMaSP() {
		return maSP;
	}
	public void setMaSP(String maSP) {
		this.maSP = maSP;
	}
	public String getMoTa() {
		return moTa;
	}
	public void setMoTa(String moTa) {
		this.moTa = moTa;
	}
	public int getSoLuong() {
		return soLuong;
	}
	public void setSoLuong(int soLuong) {
		this.soLuong = soLuong;
	}
	public double getDonGia() {
		return donGia;
	}
	public void setDonGia(double donGia) {
		this.donGia = donGia;
	}
	public double getThanhTien() {
		thanhTien = getDonGia() * getSoLuong();
		return thanhTien;
	}
	public void setThanhTien(double thanhTien) {
		this.thanhTien = thanhTien;
	}
	public double getTongThanhTien() {
		return tongThanhTien;
	}
	public void setTongThanhTien(double tongThanhTien) {
		this.tongThanhTien = tongThanhTien;
	}
	
	public void nhap() {
		Scanner p = new Scanner(System.in);
		System.out.print("Nhap vao ma san pham: ");
		maSP = p.nextLine();
		System.out.print("Nhap vao mo ta san pham: ");
		moTa = p.nextLine();
		System.out.print("Nhap vao don gia san pham: ");
		donGia = Double.parseDouble(p.nextLine());
		System.out.print("Nhap vao so luong san pham: ");
		soLuong = Integer.parseInt(p.nextLine());
	}
	
	public String toString() {
		return maSP + "      |" + moTa + "             |" + soLuong + "         |" + donGia
				+ "              |" + getThanhTien();
	}
		
}
