package phan3;
//Xuat n so trong chuoi Fibonaci
import java.util.Scanner;

public class Bai18 {

	public static void main(String[] args) {
		Scanner sc = new  Scanner(System.in);
		int n;
		System.out.printf("Nhap n so muon xuat: ");
		n=sc.nextInt();
		System.out.printf("Day %d so Fibonaci dau tien la: \n", n);
		xuatChuoi(n);
	}
	public static void xuatChuoi(int n) {
		int[] a = new int[n];
		a[0]=1;
		a[1]=1;
		for(int i=2; i<n;i++)
			a[i]=a[i-1]+a[i-2];
		for(int i=0; i<n;i++)
			System.out.printf("%5d", a[i]);
	}
}
