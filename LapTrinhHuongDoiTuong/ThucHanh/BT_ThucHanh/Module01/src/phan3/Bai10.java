package phan3;
//Tach chuoi thanh chuoi con
import java.util.Scanner;
import java.util.StringTokenizer;

public class Bai10 {

	public static void main(String[] args) {
	    String test = "";
	    Scanner sc=new Scanner(System.in);
	    System.out.printf("Nhap chuoi can tach: ");
	    test=sc.nextLine();
	    tachChuoi(test);
	}
	public static void tachChuoi(String test) {
		StringTokenizer token = new StringTokenizer(test, " ");
		System.out.printf("Chuoi goc: %s\n", test);
		System.out.println("Chuoi sau khi tach: ");
	    while (token.hasMoreTokens()) {
	      System.out.printf("\t%s\n", token.nextToken());
	    } 
	}
}
