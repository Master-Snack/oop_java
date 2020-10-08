package phan3;
//Giai phuong trinh bac 1: ax+b=0
import java.util.Scanner;

public class Bai4 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		float a, b;
		System.out.print("Nhap a: ");
		a = sc.nextFloat();
		System.out.print("Nhap b: ");
		b = sc.nextFloat();
		try {
			float x = giaiPTBac1(a, b);
			System.out.println("Nghiem x = " +x);
		}catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
	public static float giaiPTBac1(float a, float b) throws Exception {
		if(a==0)
			if(b==0)
				throw new Exception("Phuong trinh vo so nghiem!");
			else
				throw new Exception("Phuong trinh vo nghiem!");
		else
			return (-b/a);
	}

}
