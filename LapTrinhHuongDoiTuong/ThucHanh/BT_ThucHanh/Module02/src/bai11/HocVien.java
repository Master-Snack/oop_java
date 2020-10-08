package bai11;

import java.util.ArrayList;
import java.util.Scanner;

public class HocVien {
	String ho, ten, namSinh;
	float diem1, diem2, diem3, diem4, diem5, diemtb;
	public HocVien() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public HocVien(String ho, String ten, String namSinh, float diem1, float diem2, float diem3, float diem4,
			float diem5) {
		super();
		this.ho = ho;
		this.ten = ten;
		this.namSinh = namSinh;
		this.diem1 = diem1;
		this.diem2 = diem2;
		this.diem3 = diem3;
		this.diem4 = diem4;
		this.diem5 = diem5;
	}
	public String getHo() {
		return ho;
	}
	public void setHo(String ho) {
		this.ho = ho;
	}
	public String getTen() {
		return ten;
	}
	public void setTen(String ten) {
		this.ten = ten;
	}
	public String getNamSinh() {
		return namSinh;
	}
	public void setNamSinh(String namSinh) {
		this.namSinh = namSinh;
	}
	public float getDiem1() {
		return diem1;
	}
	public void setDiem1(float diem1) {
		this.diem1 = diem1;
	}
	public float getDiem2() {
		return diem2;
	}
	public void setDiem2(float diem2) {
		this.diem2 = diem2;
	}
	public float getDiem3() {
		return diem3;
	}
	public void setDiem3(float diem3) {
		this.diem3 = diem3;
	}
	public float getDiem4() {
		return diem4;
	}
	public void setDiem4(float diem4) {
		this.diem4 = diem4;
	}
	public float getDiem5() {
		return diem5;
	}
	public void setDiem5(float diem5) {
		this.diem5 = diem5;
	}
	
	public float getDiemtb() {
		diemtb = (diem1 + diem2 + diem3 + diem4 + diem5) / 5;
		return diemtb;
	}
	public void setDiemtb(float diemtb) {
		this.diemtb = diemtb;
	}
	
	//Phuong thuc nhap
	public void nhap() {
		Scanner p = new Scanner(System.in);
		System.out.print("Nhap vao ho: ");
		ho = p.nextLine();
		System.out.print("Nhap vao ten: ");
		ten = p.nextLine();
		System.out.print("Nhap vao nam sinh: ");
		namSinh = p.nextLine();
		System.out.print("Nhap lan luot diem cua 5 mon :");
		diem1 = Float.parseFloat(p.nextLine());
		diem2 = Float.parseFloat(p.nextLine());
		diem3 = Float.parseFloat(p.nextLine());
		diem4 = Float.parseFloat(p.nextLine());
		diem5 = Float.parseFloat(p.nextLine());
	}
	
	//Xuat thong tin
	@Override
	public String toString() {
		return "HocVien [ho=" + ho + ", ten=" + ten + ", namSinh=" + namSinh + ", diem1=" + diem1 + ", diem2=" + diem2
				+ ", diem3=" + diem3 + ", diem4=" + diem4 + ", diem5=" + diem5 + "]";
	}
	
	//Phuong thuc xet luan van
	public void xetLV(ArrayList<HocVien> list) {
		System.out.println("Danh sach cac thi sinh du dieu kien lam luan van tot nghiep la: ");
		for (int i = 0; i < list.size(); i++) 
			if(list.get(i).getDiemtb() > 7) 
				System.out.println(list.get(i).toString());	
	}
	
	//Phuong thuc xet tot nghiep
	public void xetTN(ArrayList<HocVien> list) {
		System.out.println("Danh sach cac thi sinh du dieu kien thi tot nghiep la: ");
		for (int i = 0; i < list.size(); i++) 
			if(list.get(i).getDiemtb() >= 5 && list.get(i).getDiemtb() <= 7) 
				System.out.println(list.get(i).toString());
	}
	
	//Phuong thuc xet thi lai
	public void xetTL(ArrayList<HocVien> list) {
		System.out.println("Danh sach cac thi thi lai la: ");
		for (int i = 0; i < list.size(); i++)
			if(list.get(i).getDiem1() < 5 || list.get(i).getDiem2() < 5 || list.get(i).getDiem3() < 5 || list.get(i).getDiem4() < 5 || list.get(i).getDiem5() < 5)
				System.out.println(list.get(i).toString());
	}
	

}
