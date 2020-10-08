package bai9;

import java.util.Scanner;

public class DSCN {

	Scanner p = new Scanner(System.in);
	CongNhan cn = new CongNhan();

	//Menu
		public void menu() {
			System.out.println("");
			System.out.println("========Menu========");
			System.out.println("Chon 1: Them 1 cong nhan");
			System.out.println("Chon 2: Xuat toan bo thong tin cong nhan");
			System.out.println("Chon 3: Tinh so luong cong nhan co trong danh sach");
			System.out.println("Chon 4: Xuat danh sach cong nhan lam tren 200 san pham");
			System.out.println("Chon 5: Sap xep cong nhan theo so san pham giam dan");
			System.out.println("Chon 6: Thoat chuong trinh");
		}
		
		//Nhap
		public void nhap() {
			System.out.print("Nhap vao ma cong nhan: ");
			cn.maCN = p.nextLine();
			System.out.print("Nhap vao ho: ");
			cn.mHo = p.nextLine();
			System.out.print("Nhap vao ten: ");
			cn.mTen = p.nextLine();
			System.out.print("Nhap vao so san pham: ");
			cn.mSoSP = Integer.parseInt(p.nextLine());
		}
		
		//Xuat thong tin cong nhan tren 200 san pham
		public void SP() {
			if(cn.getmSoSP() > 200) 
				System.out.println(cn.toString());
		}
		
		//Xuat thong tin cong nhan
		@Override
		public String toString() {
			return "CongNhan [maCN=" + cn.maCN + ", mHo=" + cn.mHo + ", mTen=" + cn.mTen + ", mSoSP=" + cn.mSoSP + ", luong=" + cn.getLuong()
					+ "]";
		}
		
		
}
