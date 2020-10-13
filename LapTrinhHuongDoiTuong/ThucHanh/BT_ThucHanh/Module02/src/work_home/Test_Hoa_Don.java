package work_home;

import java.text.DecimalFormat;
import java.time.LocalDate;
//import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Scanner;

public class Test_Hoa_Don {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int STT = 0, lua_chon;
		String ma_hd;
		double s= 0;
		Scanner sc = new Scanner(System.in);
		HoaDon hd = new HoaDon();
		ArrayList<HoaDon> list = new ArrayList<>();
		
		System.out.println("Nhap vao Ma hoa Don: ");
		ma_hd = sc.nextLine();
		System.out.println("Nhap vao ngay lap hoa don theo dinh dang nam/thang/ngay: ");
		LocalDate date = LocalDate.of(Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine()));
		
		do {
			System.out.println("--------------MENU---------------");
			System.out.println("Nhap 1: Them mot san pham vao hoa don");
			System.out.println("Nhap 2: Ket thuc");
			System.out.println("Nhap vao lua chon: ");
			lua_chon = Integer.parseInt(sc.nextLine());
			switch(lua_chon) {
			case 1:
				hd = new HoaDon();
				hd.nhap();
				list.add(hd);
				break;
			case 2:
				break;
			default: System.out.println("Nhap lua chon bi loi!!");
			}
		}while(lua_chon != 2);
		
		System.out.println("Ma HD: "+ ma_hd);
		System.out.println("Ngay lap hoa don: "+ date);
		System.out.printf("|%-7s|%-7s|%-17s|%-15s|%-14s|%-12s", "STT", "Ma SP", "Mo Ta", "Don Gia", "S Luong", "Thanh Tien");
		System.out.println("");
		for(int i=0; i<list.size(); i++) {
			s += list.get(i).getThanh_tien();
			System.out.println("|"+ (i+1)+ "	|"+list.get(i).toString());
		}
		DecimalFormat df = new DecimalFormat("#,000 VND");
		System.out.println("Tong tien thanh toan: "+ df.format(s));
	}

}
