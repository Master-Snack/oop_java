package bai5;

import java.util.ArrayList;

public class Test {

	public static void main(String[] args) throws Exception {
		
		System.out.println("CHƯƠNG TRÌNH TEST");
		HangThucPham htp1=new HangThucPham("001","Gạo", 100000.00,"09/11/2019","09/10/2019");
		HangThucPham htp2=new HangThucPham("002","Bánh", 5000.00,"01/05/2018","01/01/2020");
		HangThucPham htp3=new HangThucPham("003","Sữa", 10000.00,"01/03/2017","01/02/2018");
		
		System.out.println(inThongTin());
		System.out.println(htp1.toString());
		System.out.println(htp2.toString());
		System.out.println(htp3.toString());
	}
	static String inThongTin() {
		return String.format("%-7s %10s %20s %15s %15s %20s","Mã Hàng","Tên Hàng","Giá","Ngày Sản Xuất","Ngày Hết Hạn","Ghi chú");
	}
}
