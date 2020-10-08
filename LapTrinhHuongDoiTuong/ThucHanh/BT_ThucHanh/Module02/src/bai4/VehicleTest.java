package bai4;

import java.util.Scanner;

public class VehicleTest {

	public static void main(String[] args) {
		Vehicle ND1 = new Vehicle("Nguyễn Thu Loan", "Future Neo", 35000000, 1000);
		Vehicle ND2 = new Vehicle("Lê Minh Tính", "Ford Ranger", 250000000, 3000);
		Vehicle ND3 = nhapThongTin();
		
		
		System.out.println();
		xuatThongTin();
		System.out.println(ND1);
		System.out.println(ND2);
		System.out.println(ND3);
	}
	static Vehicle nhapThongTin() {
		Scanner sc= new Scanner(System.in);
		Vehicle ND = new Vehicle();
		System.out.print("Nhap HoTen: ");
		String tenchuxe= sc.nextLine();
		System.out.print("Nhap LoaiXe: ");
		String loaixe= sc.nextLine();
		System.out.print("Nhap TriGiaXe: ");
		float trigiaxe= sc.nextFloat();
		System.out.print("Nhap DungTich: ");
		int dungtich= sc.nextInt();
		
		ND.setTenChuXe(tenchuxe);
		ND.setLoaiXe(loaixe);
		ND.setTriGiaXe(trigiaxe);
		ND.setDungTich(dungtich);
		return ND;
	}
	static void xuatThongTin() {
		System.out.println(String.format("%-30s %-25s %15s %15s %15s", "Tên chủ xe", "Loại xe", "Dung tích", "Trị giá xe", "Thuế"));
	}
}
