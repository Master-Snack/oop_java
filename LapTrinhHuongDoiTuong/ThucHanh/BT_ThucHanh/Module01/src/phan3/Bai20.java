package phan3;
//Xuat cac hinh khi nhap m,n
import java.util.Scanner;

public class Bai20 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int m=7,n=7;
		System.out.println();
		System.out.println();
		//xuatHinh1(m,n);
		System.out.println(); 
		System.out.println();
		//xuatHinh2(m,n);
		System.out.println();
		System.out.println();
		//xuatHinh3(10);
		System.out.println();
		System.out.println();
	}
	public static void xuatHinh1(int m, int n) {
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				if(j>i)
					System.out.printf("  ");
				else
					System.out.printf("* ");
			}
			System.out.printf("\n");
		}
	}
	public static void xuatHinh2(int m, int n) {
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n+1-i; j++) {
					System.out.printf("* ");
			}
			System.out.printf("\n");
		}
	}
	public static void xuatHinh3(int n) {
		for(int i=1; i<=n;i++)
		{
			for(int j=1; j<=n-i; j++) 
				System.out.printf(" ");
			for(int j=1; j<=2*i-1;j++) {
				if(j==1 || j==2*i-1)
					System.out.printf("*");	
				else
					System.out.printf(" ");	
			}
			System.out.printf("\n");
			if(i==n-1) 
			{
				for(int j=1; j<=2*i-1;j++)
					System.out.printf("*");	
				break;
			}
		}
	}
}
