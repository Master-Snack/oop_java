package bai1;

import java.util.Scanner;

public class ToaDoTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ToaDo TD1 = new ToaDo();
		ToaDo TD2 = new ToaDo("Ngôi nhà", 15.6f, 62.6f);
		ToaDo TD3 = new ToaDo();
		System.out.printf("Nhap TenTD: ");
		String tentd= sc.nextLine();
		System.out.printf("Nhap Toa do X: ");
		float x = sc.nextFloat();
		System.out.printf("Nhap Toa do Y: ");
		float y = sc.nextFloat();
		
		TD3.setTenTD(tentd);
		TD3.setX(x);
		TD3.setY(y);
		System.out.println();
		System.out.printf("%-15s(%10s, %10s)\n", "Tên tọa độ", "Tọa độ X", "Tọa độ Y");
		System.out.println(TD1);
		System.out.println(TD2);
		System.out.println(TD3);
	}
}
