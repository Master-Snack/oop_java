package test2_GK;

import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(System.in);
			DSKhachHang dskh = new DSKhachHang(100);
			int lc = 0;
			String khachHangx;
			
			dskh.themKH(new KhachHang("001", "Vương Anh Tú", 1500000000));
			dskh.themKH(new KhachHang("002", "Trịnh Đình Quang", 500000000));
			dskh.themKH(new KhachHang("003", "Lý Hải", 2050000000));
			dskh.themKH(new KhachHang("004", "Đức Phúc", 2100000000));
			
			do {
				Menu();
				System.out.printf("\t Nhập lựa chọn: ");
				lc = Integer.parseInt(sc.nextLine());
				
				switch(lc) {
				case 1:
					System.out.println("\tDanh sách khách hàng!");
					dskh.xuatDSKH();
					break;
				case 2:
					System.out.println("\tThêm khách hàng mới!");
					if(dskh.themKH(nhapKH())== false)
						System.out.println("Không thêm được!");
					else {
						System.out.println("Thêm thành công!");
						dskh.xuatDSKH();
					}
					break;
				case 3:
					System.out.println("\tTìm khách hàng!");
					sc.nextLine();
					System.out.printf("Nhập mã khách hàng: ");
					khachHangx= sc.nextLine();
					dskh.timTTKH(khachHangx);
					break;
				case 4:
					System.out.println("\tXóa khách hàng!");
					sc.nextLine();
					System.out.printf("Nhập mã khách hàng: ");
					khachHangx= sc.nextLine();
					dskh.xoaKH(khachHangx);
					dskh.xuatDSKH();
					break;
				case 5:
					dskh.sxTen();
					System.out.println("\tDanh sách sắp xếp theo tên khách khàng!");
					dskh.xuatDSKH();
					break;
				case 6:
					dskh.sxTongTien();
					System.out.println("\tDanh sách sắp xếp theo tên tổng tiền!");
					dskh.xuatDSKH();
					break;
				case 7:
					System.out.println("\tDanh sách khách hàng VIP!");
					dskh.xuatDSKHVIP();
					break;
				default:
					System.out.println("\tChương trình kết thúc!");
					break;
				}
				
			}while(lc != 0);
		}catch(Exception e) {
			System.out.println(e.getMessage());
		}
	}
	public static void Menu() {
		System.out.println("\n\n\n==========MENU==========");
		System.out.println("\t1. Xuất danh sách khách hàng!");
		System.out.println("\t2. Thêm khách hàng mới!");
		System.out.println("\t3. Tìm khách hàng!");
		System.out.println("\t4. Xóa khách hàng!");
		System.out.println("\t5. Sắp xếp theo tên khách hàng!");
		System.out.println("\t6. Sắp xếp theo tên tổng tiền!");
		System.out.println("\t7. Xuất danh sách khách hàng VIP!");
		System.out.println("\t8. Nhập 0 để kết thúc!");
	}
	public static KhachHang nhapKH() throws Exception {
		String maKH, hoTenKH;
		long tongTien;
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhập mã khách hàng: ");
		maKH= sc.nextLine();
		sc.nextLine();
		System.out.println("Nhập họ tên khách hàng: ");
		hoTenKH=sc.nextLine();
		sc.nextLine();
		System.out.println("Nhập tổng tiền mua xe: ");
		tongTien = sc.nextLong();
		
		KhachHang x = new KhachHang(maKH, hoTenKH, tongTien);
		return x;
	}
}
