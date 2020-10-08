package phan3;
//Tinh tong le neu n la so chan, tong chan neu n la so le
import java.util.Scanner;

public class Bai3 {
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);
		int n;
		do
		{
			System.out.printf("Nhap n: ");
			n = sc.nextInt();
			if(n<=0)
				System.out.println("Nhap sai! Nhap lai!");
		}while(n<=0);
		if(n%2==0)
		{
			System.out.printf("%d la so chan!\n");
			System.out.printf("Tong le = ", tinhTong(n));
		}
	}
	public static int tinhTong(int n) {
		int sum=0;
		if(n%2==0)
			for(int i=1; i<=n; i+=2)
				sum+=i;
		else
			for(int i=0; i<=n; i+=2)
				sum+=i;
		return sum;
	}

}
