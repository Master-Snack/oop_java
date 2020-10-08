package phan3;

import java.util.Scanner;

public class Bai7 {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int n;
		do
		{
			System.out.printf("Nhap n: ");
			n = sc.nextInt();
			if(n<0)
				System.out.println("Nhap sai! Nhap lai!");
		}while(n<2);
		System.out.printf("Tong cac so nguyen to nho hon %d la: %d", n, tinhTong(n));
	}
	public static int tinhTong(int n) {
		int sum=0;
		for(int i=0; i<n; i++) {
			if(kiemtraSNT(i)==true)
				sum+=i;
		}
		return sum;
	}
	public static boolean kiemtraSNT(int n) {
		if(n<2)
			return false;
		for(int i=2; i<= Math.sqrt((float)n); i++)
				if(n%i==0)
					return false;
		
		return true;
	}

}
