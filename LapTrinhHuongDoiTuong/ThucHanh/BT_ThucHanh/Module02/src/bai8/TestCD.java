package bai8;

import java.util.*;
public class TestCD {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int choose = 0;
		Scanner sc= new Scanner(System.in);
		ListCD st= new ListCD(10);
		st.ThemCD(new CD(01, "Tinh Khong Phai", "Nhat Tinh Anh", 3, 300000));
		st.ThemCD(new CD(02, "Dap Mo Cuoc Tinh", "Quang Lap", 4, 4000000));
		
		do{
			System.out.println("1. Thêm CD");
			System.out.println("2. Xuất CD");
			System.out.println("3. Tổng số CD");
			System.out.println("4. Tổng Tiền CD");
			System.out.println("5. Sắp xếp giá CD tăng dần");
			System.out.println("6. Sắp xếp tựa CD tăng dần");
			System.out.println("7. Xuất ca sỹ");
			System.out.println("8. Thoát");
			System.out.println("9. Chọn chức năng:");
			choose = sc.nextInt();
			
			switch(choose){
			case 1:
				if (st.ThemCD(NhapCD())==false)
					System.out.println("Không thêm được");
					
				break;
			case 2:
				st.xuat();
				break;
			case 3:
				System.out.println("Tổng số CD là: "+ ListCD.soluongCD());
				break;
			case 4:
				System.out.println("Tổng tiền CD là: "+ ListCD.TongTien());
				break;
			case 5:
				ListCD.SxGia();
				break;
			case 6:
				ListCD.SxtuaCD();
				break;
			case 7:
				ListCD.xuatCasy("Kieu Minh Tuan");
				 break;
			default:
				choose =8;
			}
		}while (choose!=8);
		
	}

	private static CD NhapCD() {
		// TODO Auto-generated method stub
		int macd, sobai;
		String tuacd, tencs;
		double gia;
		Scanner sc= new Scanner(System.in);
		System.out.println("Nhập mã CD: ");
		macd= sc.nextInt();
		System.out.println("Nhập tựa CD:");
		sc.nextLine();
		tuacd=sc.nextLine();
		System.out.println("Nhập tên ca sỹ:");
		tencs=sc.nextLine();
		System.out.println("Nhập số bài hát:");
		sobai= sc.nextInt();
		System.out.println("Nhập giá CD:");
		gia=sc.nextDouble();
		CD cd = new CD(macd, tuacd, tencs, sobai, gia);
		
		return cd;
	}
}