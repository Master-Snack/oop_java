package phan3;
//Xuat cac hinh nhu hinh voi n=9
public class Bai19 
{
	public static void main(String[] args) 
	{
		int n=9;
		xuatHinh1(n);	
		System.out.println();
		System.out.println();
		xuatHinh2(n);	
		System.out.println();
		System.out.println();
		xuatHinh3(n);				
	}
	public static void xuatHinh1(int n) {
		for(int i=1; i<=n; i++)
		{ 
			System.out.printf("* ");
			for(int j=2; j<=n; j++)
			{
				if(i!=9) {
					if(i==j)
						System.out.printf("* ");
					else
						System.out.printf("  ");
				}
				else
					System.out.printf("* ");

			}
			System.out.printf("\n");
		}
	}
	public static void xuatHinh2(int n) {
		for(int i=1; i<=n; i++) {
			
			for(int j=1; j<=n; j++) {
				if(i==1 || i==n)
					System.out.printf("* ");
				else if(j==1 || j==i || j==n)
					System.out.printf("* ");
				else if(j==n+1-i)
					System.out.printf("* ");
				else
					System.out.printf("  ");
			}
			System.out.printf("\n");
		}
	}
	public static void xuatHinh3(int n) {
for(int i=1; i<=n; i++) {
			
			for(int j=1; j<=n; j++) {
				if(i==5 )
					System.out.printf("* ");
				else if((i!=1 && i!= 5 && i!=n) && (j==1 || j==9))
					System.out.printf("  ");
				else if(j==1 || j==i || j==n)
					System.out.printf("* ");
				else if(j==n+1-i)
					System.out.printf("* ");
				else
					System.out.printf("  ");
			}
			System.out.printf("\n");
		}
	}
}
