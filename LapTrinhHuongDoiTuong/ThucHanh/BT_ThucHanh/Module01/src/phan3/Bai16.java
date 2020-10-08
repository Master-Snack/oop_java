package phan3;
//Kiem tra so chan hay so le hay zero
import java.util.Scanner;

public class Bai16 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n;
		System.out.printf("Nhap so nguyen n: ");
		n=sc.nextInt();
		if(n==0)
			System.out.println(n+" la zero!");
		else if(n%2==0)
			System.out.println(n+" la so chan!");
		else
			System.out.println(n+" la so le!");
	}

}
