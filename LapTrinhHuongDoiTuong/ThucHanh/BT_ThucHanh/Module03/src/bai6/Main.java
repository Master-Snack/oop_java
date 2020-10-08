package bai6;

import java.time.LocalDate;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner data = new Scanner(System.in);
		String maHD, tenKH, maPhong;
		int dk1, dk2, day, month, year, n, thoiGianThue;
		double donGia;
		HoaDon hd;
		DanhSachHoaDon danhsach = null;
		System.out.println("\t\t\tQuan Ly Danh Sach Hoa Don");
		do {
			System.out.println("0.Ket Thuc");
			System.out.println("1.Khoi Tao Danh Sach Hoa Don");
			System.out.println("2.Them Hoa Don Vao Danh Sach");
			System.out.println("3.In Danh Sach Hoa Don");
			System.out.println("4.Thong Ke So Luong Hoa Don Theo Gio");
			System.out.println("5.Thong Ke So Luong Hoa Don Theo Ngay");
			System.out.println("6.Tinh Tong Tien Trong Thang");
			dk1 = data.nextInt();
			switch (dk1) {
			case 1: {
				System.out.println("Nhap so luong hoa don can khoi tao cho danh sach:");
				n = data.nextInt();
				danhsach = new DanhSachHoaDon(n);
				break;
			}
			case 2: {
				System.out.println("0.Ket Thuc");
				System.out.println("1.Them Hoa Don Theo Gio");
				System.out.println("2.Them Hoa Don Theo Ngay");
				dk2 = data.nextInt();
				switch (dk2) {
				case 1: {
					try {
						System.out.println("Nhap ma hoa don:");
						data = new Scanner(System.in);
						maHD = data.nextLine();
						System.out.println("Nhap ten khach hang:");
						data = new Scanner(System.in);
						tenKH = data.nextLine();
						System.out.println("Nhap ma phong:");
						data = new Scanner(System.in);
						maPhong = data.nextLine();
						System.out.println("Nhap thoi gian thue(gio):");
						data = new Scanner(System.in);
						thoiGianThue = data.nextInt();
						System.out.println("Nhap don gia:");
						donGia = data.nextDouble();
						System.out.println("Nhap ngay lap hoa don:");
						System.out.print("Ngay:");
						day = data.nextInt();
						System.out.print("Thang:");
						month = data.nextInt();
						System.out.println("Nam:");
						year = data.nextInt();
						hd = new HoaDonTheoGio(maHD, LocalDate.of(year, month, day), tenKH, maPhong, donGia,
								thoiGianThue);
						if (danhsach.them(hd) == false)
							System.out.println("Them that bai!");
					} catch (Exception e) {
						System.out.println(e.getMessage());
					}

					break;
				}
				case 2: {
					System.out.println("Nhap ma hoa don:");
					data = new Scanner(System.in);
					maHD = data.nextLine();
					System.out.println("Nhap ten khach hang:");
					data = new Scanner(System.in);
					tenKH = data.nextLine();
					System.out.println("Nhap ma phong:");
					data = new Scanner(System.in);
					maPhong = data.nextLine();
					System.out.println("Nhap thoi gian thue(ngay):");
					data = new Scanner(System.in);
					thoiGianThue = data.nextInt();
					System.out.println("Nhap don gia:");
					donGia = data.nextDouble();
					System.out.println("Nhap ngay lap hoa don:");
					System.out.print("Ngay:");
					day = data.nextInt();
					System.out.print("Thang:");
					month = data.nextInt();
					System.out.print("Nam:");
					year = data.nextInt();
					hd = new HoaDonTheoNgay(maHD, LocalDate.of(year, month, day), tenKH, maPhong, donGia, thoiGianThue);
					if (danhsach.them(hd) == false)
						System.out.println("Them that bai!");
					break;
				}

				default:
					break;
				}

				break;
			}
			case 3: {
				System.out.println("Danh sach hoa don:");
				danhsach.xuat();
				break;
			}
			case 4: {
				System.out.println("->So luong hoa don theo gio:" + danhsach.thongKeSoLuongHDTheoGio());
				break;
			}
			case 5: {
				System.out.println("->So luong hoa don theo ngay:" + danhsach.thongKeSoLuongHDTheoNgay());
				break;
			}
			case 6: {
				System.out.println("Tinh tong thanh tien trong ");
				System.out.println("thang:");
				month = data.nextInt();
				System.out.print("nam:");
				year = data.nextInt();
				System.out.printf("->Tong thanh tien trong thang %d nam %d la: %.0f\n", month, year,
						danhsach.tinhTongThanhTien(year, month));
				break;
			}
			default:
				break;

			}
		} while (dk1 != 0);
	}
}
