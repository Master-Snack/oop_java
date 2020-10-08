package bai4;

import java.text.DecimalFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class GiaoDich {
private String maGiaoDich;
private LocalDate ngayGiaoDich;
private double donGia;
private float dienTich;
public String getMaGiaoDich() {
	return maGiaoDich;
}
public void setMaGiaoDich(String maGiaoDich) throws Exception{
	if(maGiaoDich.trim().equals(""))throw new Exception("Ma giao dich rong");
	else this.maGiaoDich = maGiaoDich;
}
public LocalDate getNgayGiaoDich() {
	return ngayGiaoDich;
}
public void setNgayGiaoDich(LocalDate ngayGiaoDich) {
	this.ngayGiaoDich = ngayGiaoDich;
}
public double getDonGia() {
	return donGia;
}
public void setDonGia(double donGia) {
	if(donGia>0)
	this.donGia = donGia;
	else this.donGia=0;
}
public float getDienTich() {
	return dienTich;
}
public void setDienTich(float dienTich) {
	if(dienTich>0)
	this.dienTich = dienTich;
	else this.dienTich=0;
}
public GiaoDich() {
	super();
}
public GiaoDich(String maGiaoDich, LocalDate ngayGiaoDich, double donGia,float dienTich) throws Exception {
	super();
	setMaGiaoDich(maGiaoDich);
	setNgayGiaoDich(ngayGiaoDich);
	setDonGia(donGia);
	setDienTich(dienTich);
}
public double tinhThanhTien () {
	return 0;
}
@Override
public String toString() {
	DateTimeFormatter p=DateTimeFormatter.ofPattern("dd/MM/yyyy");
	DecimalFormat q= new DecimalFormat("#,##0");
	return String.format("ma giao dich:%5s ,ngay giao dich:%8s ,don gia:%11s ,dien tich:%5.2f",maGiaoDich,ngayGiaoDich.format(p),q.format(donGia),dienTich);
}

}
