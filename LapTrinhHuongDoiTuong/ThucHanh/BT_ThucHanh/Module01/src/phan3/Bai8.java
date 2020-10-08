package phan3;
//Tinh tong n so nguyen to dau tien
import java.util.Scanner;

public class Bai8 {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int n;
		do
		{
			System.out.printf("Nhap n so nguyen: ");
			n = sc.nextInt();
			if(n<0)
				System.out.println("Nhap sai! Nhap lai!");
		}while(n<2);
		System.out.printf("Tong %d so nguyen to dau tien la: %d", n, tinhTong(n));
	}
	public static int tinhTong(int n) {
		int sum=0, x=0;
		for(int i=0; x!=n; i++) {
			if(kiemtraSNT(i)==true)
			{
				sum+=i;
				x++;
			}		
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
