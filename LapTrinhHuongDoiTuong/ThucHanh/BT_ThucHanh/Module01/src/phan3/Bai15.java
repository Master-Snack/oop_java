package phan3;
//in ra GTLN va GTNN trong day cac gia tri
import java.util.Scanner;

public class Bai15 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n;
		do {
			System.out.printf("Nhap n so gia tri: ");
			n=sc.nextInt();
			if(n<1)
				System.out.println("Kiem tra lai!");
		}while(n<1);
		int[] a = new int[n];
		for(int i=0; i<n; i++) {
			System.out.printf("Nhap a[%d]: ",i);
			a[i]=sc.nextInt();
		}
		timMaxMin(a,n);

	}
	public static void timMaxMin(int a[], int n) {
		int max=a[0], min=a[0];
		for(int i=1; i<n; i++) {
			if(a[i]>max)
				max=a[i];
			if(a[i]<min)
				min=a[i];
		}
		System.out.println();
		System.out.println("Max = "+max);
		System.out.println("Min = "+min);
	}

}
