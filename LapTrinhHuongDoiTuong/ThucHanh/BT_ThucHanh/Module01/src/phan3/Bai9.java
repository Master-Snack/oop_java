package phan3;
//In ra so lan ky tu 'a' xuat hien trong chuoi
import java.util.Scanner;

public class Bai9 {

	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		String var;
		char kt='a';
		System.out.print("Nhap chuoi: ");
		var=sc.nextLine();
		System.out.printf("So lan ky tu 'a' xuat hien trong chuoi %s la: %d", var, tinhSL(var, kt));		
	}
	public static int tinhSL(String var, char kt)
	{
		int count=0;
		for(int i=0; i<var.length(); i++)
			if(var.charAt(i)== kt)
				count++;
		return count;
	}

}
