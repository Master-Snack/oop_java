package bai2;

import java.time.LocalDate;

public class Sach {
private String maSach;
private LocalDate ngayNhap;
private double donGia;
private int soLuong;
private String nhaXuatBan;
public String getMaSach() {
	return maSach;
}
public void setMaSach(String maSach) {
	this.maSach = maSach;
}
public LocalDate getNgayNhap() {
	return ngayNhap;
}
public void setNgayNhap(LocalDate ngayNhap) {
	this.ngayNhap = ngayNhap;
}
public double getDonGia() {
	return donGia;
}
public void setDonGia(double donGia) {
	this.donGia = donGia;
}
public int getSoLuong() {
	return soLuong;
}
public void setSoLuong(int soLuong) {
	this.soLuong = soLuong;
}
public String getNhaXuatBan() {
	return nhaXuatBan;
}
public void setNhaXuatBan(String nhaXuatBan) {
	this.nhaXuatBan = nhaXuatBan;
}
public Sach() {
	super();
}
public Sach(String maSach, LocalDate ngayNhap, double donGia, int soLuong, String nhaXuatBan) {
	super();
	setMaSach(maSach);
	setNgayNhap(ngayNhap);
	setDonGia(donGia);
	setSoLuong(soLuong);
	setNhaXuatBan(nhaXuatBan);
}
public double thanhTien() {
	return donGia*soLuong;
}
@Override
public String toString() {
	return String.format("ma sach:%10s ,ngay nhap:%10s ,don gia:%10.0f ,so luong:%5d ,nha xuat ban:%10s",maSach,ngayNhap,donGia,soLuong,nhaXuatBan);
}

}
