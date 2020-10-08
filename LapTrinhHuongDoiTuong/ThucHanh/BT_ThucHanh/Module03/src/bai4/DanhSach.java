package bai4;

import java.util.Arrays;

public class DanhSach {
private GiaoDich list[];
private int count;
public DanhSach(int n) {
	list=new GiaoDich[n];
	count=0;
}

public DanhSach(GiaoDich a) {
	list[count]=a;
	count++;
}

@Override
public String toString() {
	String s="";
	for (int i = 0; i < count; i++) {
		s+=list[i]+"\n";
	}
	return s;
}

}
