package bai4;

import java.time.LocalDate;

public class main {
public static void main(String[] args) throws Exception {
	DanhSach a=new DanhSach(10);
	a=new DanhSach(new GiaoDichDat("asd",LocalDate.of(2000,4,5),10000,15,"A"));
System.out.println(a.toString());
}


}
