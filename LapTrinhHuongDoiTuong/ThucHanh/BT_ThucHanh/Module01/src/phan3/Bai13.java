package phan3;
//In ra cac so le tu 1 den 99
public class Bai13 {
	public static void main(String[] args) {
		System.out.println("Cac so le tu 1 den 99: ");
		for(int i=0; i<100; i++) {
			if(i%2!=0)
				System.out.printf("%5d",i);
			if(i%10==0)
				System.out.println();
		}
	}
}
