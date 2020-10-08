package bai9;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException, InterruptedException {
		Scanner p = new Scanner(System.in);
		int n, luachon;
		ArrayList<DSCN> list = new ArrayList<>();
		DSCN cn = new DSCN();
				
		System.out.print("Nhap vao n so danh sach cong nhan: ");
		n = Integer.parseInt(p.nextLine());
		do {
			new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
			cn.menu();
			System.out.println("Nhap vao lua chon: ");
			luachon = Integer.parseInt(p.nextLine());
			switch(luachon) {
			case 1:
				if(list.size() < n) {
					cn = new DSCN();
					cn.nhap();
					list.add(cn);
				}
				else
					System.err.println("Them khong thanh cong vi vuot qua so luong danh sach cho truoc!!!");
				break;
			case 2:
				for (int i = 0; i < list.size(); i++) {
					System.out.println("Danh sach thu cong nhan thu "+(i + 1));
					System.out.println(list.get(i).toString());
				}
				break;
			case 3:
				System.out.println("So luong cong nhan co trong danh sach la: "+list.size());
				break;
			case 4:
				for (int i = 0; i < list.size(); i++) {
					list.get(i).SP();
				}
				break;
			case 5:
				Collections.sort(list, new Comparator<DSCN>() {
					@Override
					public int compare(DSCN ds1, DSCN ds2) {
						if(ds1.cn.getmSoSP() < ds2.cn.getmSoSP()) 
							return 1;
						else {
							if(ds1.cn.getmSoSP() == ds2.cn.getmSoSP()) 
								return 0;
							else 
								return -1;
						}
					}	
				});
				
				System.out.println("Danh sach sau khi sap xep");
				for (DSCN a : list) 
					System.out.println(a.toString());
				break;
			case 6:
				System.out.println("Da thoat khoi chuong trinh!!!");
				break;
			default: System.err.println("Nhap lua chon khong dung!!!");
			}
		}while(luachon != 6);
		

	}

	private static void system(String string) {
		// TODO Auto-generated method stub
		
	}

}
