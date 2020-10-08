package phan3;
//In ra tong 10 so chan dau tien

public class Bai12 {

	public static void main(String[] args) {
		int n=10;
		System.out.printf("Tong %d so chan dau tien la: %d", n, tinhTong(n));
	}
	public static int tinhTong(int n) {
		int sum=0, x=0;
		for(int i=0; x<=n; i++) {
			if(i%2==0) {
				sum+=i;
				x++;
			}
		}
		return sum;
	}

}
