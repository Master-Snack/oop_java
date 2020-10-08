package bai2;

import java.util.Scanner;

public class SinhVienTest {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		SinhVien SV1= new SinhVien(11111, "Hoàng Thị Tố Thùy", 6.5f, 8.5f);
		SinhVien SV2= new SinhVien(22222, "Lê Hoàng Thành Đạt", 9.5f, 9.5f);
		SinhVien SV3= new SinhVien();
		
		System.out.printf("Nhap MSSV cua SV3: ");
		int mssv= sc.nextInt();
		sc.nextLine();
		System.out.printf("Nhap HoTen cua SV3: ");
		String hoten= sc.nextLine();
		System.out.printf("Nhap DiemLT cua SV3: ");
		float diemlt= sc.nextFloat();
		System.out.printf("Nhap DiemTH cua SV3: ");
		float diemth= sc.nextFloat();
		
		SV3.setMSSV(mssv);
		SV3.setHoTen(hoten);
		SV3.setDiemLT(diemlt);
		SV3.setDiemTH(diemth);
		
		System.out.println();
		System.out.println(String.format("%-5s %-30s %10s %10s %10s", "MSSV", "Họ tên", "Điểm LT", "Điểm TH", "Điểm TB"));
		System.out.println(SV1);
		System.out.println(SV2);
		System.out.println(SV3);
		
	}

}
