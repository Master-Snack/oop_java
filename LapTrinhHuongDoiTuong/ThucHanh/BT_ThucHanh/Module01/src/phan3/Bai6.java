package phan3;
//Kiem tra co phai la so nguyen to?
import java.util.Scanner;

public class Bai6 {

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
		if(kiemtraSNT(n)==true) 
			System.out.printf("%d la so nguyen to!\n", n);
		else
			System.out.printf("%d khong phai nguyen to!\n", n);

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
