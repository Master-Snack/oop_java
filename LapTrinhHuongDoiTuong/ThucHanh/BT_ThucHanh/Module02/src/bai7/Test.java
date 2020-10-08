package bai7;
import java.util.Scanner;
public class Test {

	public static void main(String[] args) {
		float x,y;
		double bk;
		String ten;
		HinhTron htr1=new HinhTron();
		Scanner sc=new Scanner(System.in);
		System.out.println("ChÆ°Æ¡ng trÃ¬nh Test bÃ i 07");
		System.out.println("Nháº­p tÃªn hÃ¬nh trÃ²n:");
		ten=sc.nextLine();
		sc=new Scanner(System.in);
		System.out.println("Nháº­p tá»�a Ä‘á»™ x:");
		x=sc.nextFloat();
		sc=new Scanner(System.in);
		System.out.println("Nháº­p tá»�a Ä‘á»™ y");
		y=sc.nextFloat();
		System.out.println("Nháº­p bÃ¡n kÃ­nh hÃ¬nh trÃ²n:");
		bk=sc.nextDouble();
		ToaDo tam=new ToaDo(x, y);
		htr1.setBanKinh(bk);
		htr1.setTam(tam);
		System.out.printf("HÃ¬nh trÃ²n cÃ³ tÃ¢m %s%s vá»›i bÃ¡n kÃ­nh %.1f cÃ³ diá»‡n tÃ­ch vÃ  chu vi láº§n lÆ°á»£t lÃ  %.3f vÃ  %.3f",ten,tam.toString(),htr1.getBanKinh(),htr1.tinhChuVi(),htr1.tinhDienTich());
	}

}
