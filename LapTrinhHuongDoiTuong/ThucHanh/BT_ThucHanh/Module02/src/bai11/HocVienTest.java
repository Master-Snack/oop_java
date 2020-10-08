package bai11;

import java.util.ArrayList;
import java.util.Scanner;

public class HocVienTest {

	public static void main(String[] args) {
		int luachon;
		Scanner p = new Scanner(System.in);
		ArrayList<HocVien> list = new ArrayList<HocVien>();
		HocVien hv = new HocVien();
		
		do {
			System.out.println("========Menu========");
			System.out.println("Chon 1: Them Hoc Vien");
			System.out.println("Chon 2: Xuat thong tin tat ca cac thong tin");
			System.out.println("Chon 3: Xuat ra danh sach thi sinh du dieu kien va thi lai");
			System.out.println("Chon 4: Ket thuc");
			System.out.print("Nhap vao lua chon: ");
			luachon = Integer.parseInt(p.nextLine());
			switch(luachon) {
			case 1:
				hv = new HocVien();
				hv.nhap();
				list.add(hv);
				break;
			case 2:
				System.out.println("Thong tin tat ca cac hoc vien la");
				for (int i = 0; i < list.size(); i++) 
					System.out.println(list.get(i).toString());
				break;
			case 3:
				hv.xetTN(list);
				hv.xetLV(list);
				hv.xetTL(list);
				
				break;
			default: System.err.println("Loi nhap lua chon !!!");
			}
		}while(luachon != 4);
		
		
		

	}

}
