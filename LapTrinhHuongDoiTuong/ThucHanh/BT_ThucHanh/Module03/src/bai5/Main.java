package bai5;

import java.time.LocalDate;

public class Main {
	public static void main(String[] args) {
		// Tao moi loai 3 khach hang
		KhachHang kh[] = new KhachHang[6];
		kh[0] = new KhachHangVN("1", "Nguyen Van Nhat", LocalDate.now(), 3000, 6000, 1, 8000);
		kh[1] = new KhachHangVN("2", "Tran Thi Nhi", LocalDate.of(2018, 9, 12), 9000, 6000, 2, 8000);
		kh[2] = new KhachHangVN("3", "Truong Tam Phong", LocalDate.of(2018, 10, 2), 15000, 6000, 3, 8000);
		kh[3] = new KhachHangNgoaiQuoc("4", "Thap Tu", LocalDate.of(2018, 9, 30), 3000, 60000, "My");
		kh[4] = new KhachHangNgoaiQuoc("5", "De Ngu", LocalDate.now(), 7000, 60000, "An Do");
		kh[5] = new KhachHangNgoaiQuoc("6", "Truong Luc", LocalDate.of(2018, 9, 1), 9000, 60000, "Nhat");

		// So luong khach hang VN va Ngoai quoc && Trung binh thanh tien KH ngoai quoc
		int soLuongKHVN = 0;
		int soLuongKHNgoaiQuoc = 0;
		int dem = 0;
		double tongThanhTienKHNgoaiQuoc = 0;
		for (KhachHang khachHang : kh) {
			if (khachHang instanceof KhachHangVN)
				soLuongKHVN++;
			else {
				soLuongKHNgoaiQuoc++;
				dem++;
				tongThanhTienKHNgoaiQuoc += khachHang.thanhTien();
			}
		}
		// Xuat so luong khach hang
		System.out.println("So khach hang VN:" + soLuongKHVN);
		System.out.println("So khach hang ngoai quoc:" + soLuongKHNgoaiQuoc);
		// Xuat trung binh thanh tien khach hang ngoai quoc
		System.out.printf("Trung binh thanh tien KH ngoai quoc:%.0f\n", (tongThanhTienKHNgoaiQuoc / dem));

		// Xuat cac hoa don trong T9/2018
		System.out.println("\nHoa don T9/2018\n");
//		String hoaDonKHVN = KhachHangVN.xuatKhoa() + "\n";
//		String hoaDonKHNgoaiQuoc = KhachHangNgoaiQuoc.xuatKhoa() + "\n";
		for (KhachHang khachHang : kh) {
			if (khachHang.getNgayLapHoaDon().isAfter(LocalDate.of(2018, 8, 31))
					&& khachHang.getNgayLapHoaDon().isBefore(LocalDate.of(2018, 10, 1)))
				if (khachHang instanceof KhachHangVN) {
					System.out.println(KhachHangVN.xuatKhoa() + "\n" + khachHang);
					System.out.printf("Thanh tien:%.0f\n\n", khachHang.thanhTien());
				} else {
					System.out.println(KhachHangNgoaiQuoc.xuatKhoa() + "\n" + khachHang);
					System.out.printf("Thanh tien:%.0f\n\n", khachHang.thanhTien());

				}

		}
	}
}
