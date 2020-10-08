package bai2;

import java.time.LocalDate;

public class SachGiaoKhoa extends Sach{
private boolean tinhTrang;

public boolean isTinhTrang() {
	return tinhTrang;
}

public void setTinhTrang(boolean tinhTrang) {
	this.tinhTrang = tinhTrang;
}

public SachGiaoKhoa(String maSach, LocalDate ngayNhap, double donGia, int soLuong, String nhaXuatBan,
		boolean tinhTrang) {
	super(maSach, ngayNhap, donGia, soLuong, nhaXuatBan);
	setTinhTrang(tinhTrang);
}

public SachGiaoKhoa() {
	super();
}
public double thanhTien() {
	if(tinhTrang)
	return super.getDonGia()*super.getSoLuong();
	else return (super.getDonGia()*super.getSoLuong()*50)/100;
}

@Override
public String toString() {
	String s="";
	if(tinhTrang)s="moi";else s="cu";
	return String.format("Sach giao khoa[%s ,tinh trang:%5s]",super.toString(),s);
}

}
