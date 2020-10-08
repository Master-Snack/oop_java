package bai2;

import java.time.LocalDate;
import java.util.Scanner;

public class Main {
public static void main(String[] args) {
	Sach a[]=new Sach[6];
a[0]=new SachGiaoKhoa("001",LocalDate.of(2015,5,3),50000,2,"Kim Dong",true);
a[1]=new SachGiaoKhoa("002",LocalDate.of(2014,5,20),95000,51,"Kim Dong",false);
a[2]=new SachGiaoKhoa("003",LocalDate.of(2010,9,1),5000,3,"Kim Dong",true);
a[3]=new SachThamKhao("004",LocalDate.of(2018,4,30),41000,15,"Tre",1000);
a[4]=new SachThamKhao("005",LocalDate.of(2019,4,30),20000,1,"Tre",5000);
a[5]=new SachThamKhao("006",LocalDate.of(2015,4,2),20000,1,"Kim Dong",15000);
for (int i = 0; i < a.length; i++) {
	System.out.println(a[i].toString());
}
//Tong tien sach giao khoa
double b=0;
for (int i = 0; i < a.length; i++) {
	if(a[i]instanceof SachGiaoKhoa)b+=a[i].thanhTien();
}
System.out.printf("Tong tien sach giao khoa: %.0f",b);
//Tong tien sach tham khao va trung binh don gia
double m=0,c=0;
int n=0;
for (int i = 0; i < a.length; i++) {
	if(a[i]instanceof SachThamKhao) {c+=a[i].thanhTien();m+=a[i].getDonGia();n++;}
}
System.out.printf("\nTong tien sach tham khao: %.0f",c);
System.out.printf("\nTrung binh don gia: %.0f",m/n);
//Tim nha xuat ban k
System.out.println("\nNhap nha xuat ban");
String key=new Scanner(System.in).nextLine(); 
for (int i = 0; i < a.length; i++) {
	if(a[i].getNhaXuatBan().equalsIgnoreCase(key))
		System.out.println(a[i].toString());
}
}
}
