package test1_GK;

import java.text.DecimalFormat;
import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(System.in);
			DSPhim dsphim = new DSPhim(100);
			int lc;
			String phimx;
			dsphim.themPhim(new Phim(01, "Tình Không Phai Mờ", "Nhật Tinh Anh", 3, 30000));
			dsphim.themPhim(new Phim(02, "Đắp Mộ Cuộc Tình", "Quang Lập", 5, 20000));
		do {
			Menu();
			System.out.println("\tNhập lựa chọn: ");
			lc= sc.nextInt();
			switch(lc) {
			case 1:
				System.out.println("\t1. Thêm một phim mới!");
				if(dsphim.themPhim(nhapPhim())==false)
					System.out.println("Không thêm được!");
				System.out.printf("%10s |%30s |%30s |%15s |%15s |%15s\n",
						"Mã phim", "Tên phim", "Tên đạo diễn", "Số suất chiếu", "Giá suất chiếu", "Thành tiền");
				dsphim.xuatDSPhim();
				break;
			case 2:
				System.out.println("\t2. Xóa một phim trong danh sách!");
				sc.nextLine();
				System.out.println("Nhập tên phim cần xóa: ");
				phimx = sc.nextLine();
				dsphim.xoaPhim(phimx);
				System.out.printf("%10s |%30s |%30s |%15s |%15s |%15s\n",
						"Mã phim", "Tên phim", "Tên đạo diễn", "Số suất chiếu", "Giá suất chiếu", "Thành tiền");
				dsphim.xuatDSPhim();
				break;
			case 3:
				System.out.println("\t3. Xuất tổng giá thành của các phim!");
				System.out.println("Tổng giá tiền: "+ dsphim.tinhTongTien());
				break;
			case 4:
				System.out.println("\t4. Sắp xếp danh sách tăng dần theo tên phim!");
				dsphim.sapXepDS();
				System.out.printf("%10s |%30s |%30s |%15s |%15s |%15s\n",
						"Mã phim", "Tên phim", "Tên đạo diễn", "Số suất chiếu", "Giá suất chiếu", "Thành tiền");
				dsphim.xuatDSPhim();
				break;
			case 5:
				System.out.println("\t5. Xuất toàn bộ danh sách!");
				System.out.printf("%10s |%30s |%30s |%15s |%15s |%15s\n",
					"Mã phim", "Tên phim", "Tên đạo diễn", "Số suất chiếu", "Giá suất chiếu", "Thành tiền");
				dsphim.xuatDSPhim();
				break;
			default:
				System.out.println("Chương trình kết thúc!");
				break;
			}
		}while(lc!=0);
		}catch(Exception e) {
			System.out.println(e.getMessage());
		}
	}
	public static void Menu() {
		System.out.println("\n==========MENU=========");
		System.out.println("\t1. Thêm một phim mới!");
		System.out.println("\t2. Xóa một phim trong danh sách!");
		System.out.println("\t3. Xuất tổng giá thành của các phim!");
		System.out.println("\t4. Sắp xếp danh sách tăng dần theo tên phim!");
		System.out.println("\t5. Xuất toàn bộ danh sách!");
		System.out.println("\t6. Nhập 0 để kết thúc!");
	}
	public static Phim nhapPhim() throws Exception {	
				int maPhim;
				String tenPhim;
				String tenDaoDien;
				int soSuatChieu;
				float giaSuatChieu;
				Scanner sc = new Scanner(System.in);
				System.out.println("Nhập Mã phim: ");
				maPhim = sc.nextInt();
				sc.nextLine();
				System.out.println("Nhập Tên phim: ");
				tenPhim = sc.nextLine();
				sc.nextLine();
				System.out.println("Nhập Tên đạo diễn: ");
				tenDaoDien = sc.nextLine();		
				System.out.println("Nhập Số suất chiếu: ");
				soSuatChieu = sc.nextInt();
				System.out.println("Nhập Giá suất chiếu: ");
				giaSuatChieu = sc.nextFloat();
				
				Phim x = new Phim(maPhim, tenPhim, tenDaoDien, soSuatChieu, giaSuatChieu);
				
				return x;
	}
}
