package phan3;
//Tong cac so la boi cua 7 tu 1 den 100
public class Bai14 {

	public static void main(String[] args) {
		int sum=0;
		for(int i=0; i<100; i++)
			if(i%7==0)
				sum+=i;
		System.out.println("Tong cac so la boi cua 7: " + sum);
	}

}
