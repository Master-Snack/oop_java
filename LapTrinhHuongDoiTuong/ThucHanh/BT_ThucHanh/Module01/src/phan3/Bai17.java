package phan3;
//In ra boi so cua 3 tu 300 den 3
public class Bai17 {
	public static void main(String[] args) {
		System.out.println("Boi so cua 3 tu 300 den 3 la: ");
		for(int i=300; i>=3; i--) {
			if(i%3==0)
				System.out.printf("%7d", i);
			if(i%50==0 && i!=300)
				System.out.println();
		}
			
	}
}
