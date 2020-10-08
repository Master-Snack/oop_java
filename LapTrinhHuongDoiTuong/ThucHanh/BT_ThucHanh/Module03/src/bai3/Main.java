package bai3;

import java.time.LocalDate;


public class Main {
public static void main(String[] args) throws Exception{
	GiaoDich a[]=new GiaoDich[6];
	a[0]=new GiaoDichVang("125",LocalDate.of(2015,4,19),1500000,10,"9999");
	a[1]=new GiaoDichVang("4222",LocalDate.of(2011,4,1),2000000000,10,"9999");
	a[2]=new GiaoDichVang("12455",LocalDate.of(2015,9,9),1500000000,10,"9999");
	a[3]=new GiaoDichTienTe("313",LocalDate.of(2015,4,19),100000,50,22000,"VN");
	a[4]=new GiaoDichTienTe("44443",LocalDate.of(2015,4,1),50,50,23000,"USD");
	a[5]=new GiaoDichTienTe("313111",LocalDate.of(2015,4,9),100,50,30000,"euro");
	
//Tong so luong  tung loai
	int m=0,n=0,q=0;
	double p=0;
	for (int i = 0; i < a.length; i++) {
		if(a[i] instanceof GiaoDichTienTe) {m+=a[i].getSoLuong();p+=a[i].thanhTien();q++;}
	}
	for (int i = 0; i < a.length; i++) {
		if(a[i] instanceof GiaoDichVang) {n+=a[i].getSoLuong();}
	}
	System.out.printf("So luong giao dich vang: %d",n);
	System.out.printf("\nSo luong giao dich tien te: %d",m);
//Trung binh thanh tien giao dich tien te
	System.out.printf("\nTrung binh thanh tien giao dich tien te: %.0f\n",p);
//Giao dich don gia hon ty
	for (int i = 0; i < a.length; i++) {
		if(a[i].getDonGia()>1000000000)System.out.println(a[i].toString());
	}
}
}
