package phan3;
//Kiem tra co bao nhieu ky tu la so trong chuoi
import java.util.Scanner;

public class Bai11 {

	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		String var;
		System.out.print("Nhap chuoi can kiem tra: ");
		var=sc.nextLine();
		System.out.printf("So ky tu la so xuat hien trong chuoi %s la: %d", var, demSLSo(var));		
	}
	public static int demSLSo(String var)
	{
		int count=0;
		for(int i=0; i<var.length(); i++)
			if(var.charAt(i)>='0' && var.charAt(i)<='9')
				count++;
		return count;
	}
}
