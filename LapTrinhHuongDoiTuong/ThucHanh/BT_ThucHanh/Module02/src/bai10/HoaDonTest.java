package bai10;

import java.text.DecimalFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Scanner;

public class HoaDonTest {
	
	public static void main(String[] args) {
		int STT = 0, luachon;
		String maHD;
		double s = 0;
		Scanner p = new Scanner(System.in);
		HoaDon hd = new HoaDon();
		ArrayList<HoaDon> list = new ArrayList<>();
		
		System.out.print("Nhap vao ma hoa don: ");
		maHD = p.nextLine();
		System.out.print("Nhap vao ngay lap hoa don theo dang yyyy/mm/dd: ");
		LocalDate date = LocalDate.of(Integer.parseInt(p.nextLine()), Integer.parseInt(p.nextLine()), Integer.parseInt(p.nextLine()));
		
		do {
			System.out.println("======Menu======");
			System.out.println("Nhap 1: Them mot san pham");
			System.out.println("Nhap 2: Ket thuc");
			System.out.println("Nhap vao lua chon: ");
			luachon = Integer.parseInt(p.nextLine());
			switch(luachon) {
			case 1:
				hd = new HoaDon();
				hd.nhap();
				list.add(hd);
				break;
			case 2:
				break;
			default: System.err.println("Loi nhap lua chon!!!!");
			}
		}while(luachon != 2);
		//Xuat thong tin
		System.out.println("Ma HD: "+maHD);
		System.out.println("Ngay lap hoa don: "+date);
		System.out.printf("|%-5s|%-7s|%-14s|%-15s|%-10s|%-12s", "STT", "Ma SP", "Mo Ta", "Don Gia", "So Luong", "Thanh Tien");
		System.out.println("");
		for (int i = 0; i < list.size(); i++) {
			s += list.get(i).getThanhTien();
			System.out.println("|"+(i + 1)+"    |"+list.get(i).toString());
		}
		DecimalFormat df = new DecimalFormat("#,000 VNĐ");
		System.out.println("Tong tien thanh toan: "+df.format(s));
		
	}

}
