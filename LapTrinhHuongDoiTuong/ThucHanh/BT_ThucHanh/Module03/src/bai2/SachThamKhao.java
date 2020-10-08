package bai2;

import java.time.LocalDate;

public class SachThamKhao extends Sach{
private double thue;

public double getThue() {
	return thue;
}

public void setThue(double thue) {
	this.thue = thue;
}

public SachThamKhao() {
	super();
}

public SachThamKhao(String maSach, LocalDate ngayNhap, double donGia, int soLuong, String nhaXuatBan, double thue) {
	super(maSach, ngayNhap, donGia, soLuong, nhaXuatBan);
	setThue(thue);
}
public double thanhTien() {
	return super.getDonGia()*super.getSoLuong()+thue;
}

@Override
public String toString() {
	return String.format("Sach tham khao[%s ,thue:%10.0f]",super.toString(),thue);
}

}
