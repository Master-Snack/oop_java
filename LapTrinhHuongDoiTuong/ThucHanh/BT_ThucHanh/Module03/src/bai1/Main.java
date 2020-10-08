package bai1;

public class Main {
public static void main(String[] args)  {
	ChuyenXe a[]=new ChuyenXe[6];
	a[0]=new ChuyenXeNoiThanh("001","Tran Van A",521,900000,55,150);
	a[1]=new ChuyenXeNoiThanh("002","Le Van D",123,650000,15,10);
	a[2]=new ChuyenXeNoiThanh("003","Nguyen Thi H",221,100000,59,15);
	a[3]=new ChuyenXeNgoaiThanh("004","Nguyen Van K",460,300000,"Can Gio",30);
	a[4]=new ChuyenXeNgoaiThanh("005","Nguyen Van M",460,30000,"Can Duoc",320);
	a[5]=new ChuyenXeNgoaiThanh("006","Nguyen Van L",460,350000,"Can Tho",200);
for (int i = 0; i < a.length; i++) {
	System.out.println(a[i].toString());
}
//Tong Doanh thu
	double b=0;
	for (int i = 0; i < a.length; i++) {
	b+=a[i].getDoanhThu();
}	
	System.out.printf("Tong Doanh thu: %.0f",b);
//Doanh thu chuyen xe ngoai thanh
	double c=0;
	for (int i = 0; i < a.length; i++) {
		if(a[i] instanceof ChuyenXeNoiThanh)c+=a[i].getDoanhThu();
	}
	System.out.printf("\nDoanh thu chuyen xe ngoai thanh: %f",c);
//Doanh thu chuyen noi thanh
	double d=0;
	for (int i = 0; i < a.length; i++) {
		if(a[i] instanceof ChuyenXeNgoaiThanh)d+=a[i].getDoanhThu();
	}
	System.out.printf("\nDoanh thu chuyen xe noi thanh: %f",d);
	
}
}
