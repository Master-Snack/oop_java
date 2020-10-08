package phan3;
//Tim USCLN cua 2 so nhap vao
import java.util.Scanner;

public class Bai5 {

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner (System.in);
		int a, b;
		System.out.print("Nhap a: ");
		a = sc.nextInt();
		System.out.print("Nhap b: ");
		b = sc.nextInt();
		System.out.printf("USCLN cua %d va %d la: %d", a, b, USCLN(a,b));
		
	}
	public static int USCLN (int a, int b) {
		if(b==0)
			return a;
		return USCLN(b, a%b);	
	}
}
