package bai6;

import java.text.NumberFormat;
import java.util.Locale;

public class Test {

	public static void main(String[] args) {
		
		Locale local=new Locale("vi","vn");
		NumberFormat formater=NumberFormat.getCurrencyInstance(local);
		
		Account acc1=new Account(72354,"Ted Murphy",102.56);
		Account acc2=new Account(69713,"Jane Smith", 40.00);
		Account acc3=new Account(93757,"Edward Demsey", 759.32);
		
		doTest(acc1,acc2,acc3);
	}
	static String xuatTitle()
	{
		return String.format("%15s%30s%15s\n","Sá»‘ tÃ i khoáº£n","TÃªn ngÆ°á»�i dÃ¹ng","Sá»‘ dÆ°");
	}
	static boolean guiThemTien(Account acc,double amount){
		if(acc.deposit(amount))
			return true;
		else 
			return false;
	}
	static boolean rutTien(Account acc,double amount,double fee){
		if(acc.withdraw(amount, fee))
			return true;
		else 
			return false;
	}
	static void tinhLai(Account acc)
	{
		acc.addInterest();
	}
	static boolean kiemTraSoDu(Account acc,double amount)
	{
		if(acc.getBalance()>amount)
			return true;
		else
			return false;
	}
	static boolean chuyenTien(Account acc2,Account acc1,double amount)
	{
		if(kiemTraSoDu(acc2, amount))
		{
			if(acc1.transfer(acc1,amount))
			{
				acc2.setBalance(acc2.getBalance()-amount);
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	static void doTest(Account acc1,Account acc2,Account acc3)
	{
		
		System.out.println("ChÆ°Æ¡ng trÃ¬nh test lá»›p Account");
	
		boolean check=guiThemTien(acc1,25.85);
		if(check==true)
			System.out.println("Gá»­i tiá»�n thÃ nh cÃ´ng");
		else
			System.out.println("Gá»­i tiá»�n khÃ´ng thÃ nh cÃ´ng");
		
	
		boolean check1=guiThemTien(acc2, 500.00);
		if(check1==true)
			System.out.println("Gá»­i tiá»�n thÃ nh cÃ´ng");
		else
			System.out.println("Gá»­i tiá»�n khÃ´ng thÃ nh cÃ´ng");
		
	
		boolean check2=rutTien(acc2, 430.75, 1.50);
		if(check2==true)
			System.out.println("RÃºt tiá»�n thÃ nh cÃ´ng");
		else
			System.out.println("RÃºt tiá»�n khÃ´ng thÃ nh cÃ´ng");
		
		System.out.printf("LÃ£i cá»§a account 3 lÃ :%.2f\n",acc3.getBalance());
		

		System.out.print(xuatTitle());
		System.out.println(acc1.toString());
		System.out.println(acc2.toString());
		System.out.println(acc3.toString());
		
		
		boolean check3=chuyenTien(acc2, acc1,100.00);
		if(check3==true)
			System.out.println("Chuyá»ƒn tiá»�n thÃ nh cÃ´ng");
		else
			System.out.println("Chuyá»ƒn tiá»�n khÃ´ng thÃ nh cÃ´ng");
		
		
		System.out.print(xuatTitle());
		System.out.println(acc1.toString());
		System.out.println(acc2.toString());
	}
}
