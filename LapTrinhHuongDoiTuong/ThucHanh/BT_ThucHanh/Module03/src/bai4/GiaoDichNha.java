package bai4;

import java.text.DecimalFormat;
import java.time.LocalDate;

public class GiaoDichNha extends GiaoDich{
private boolean loaiNha;
private String diaChi;
public boolean isLoaiNha() {
	return loaiNha;
}
public void setLoaiNha(boolean loaiNha) {
	this.loaiNha = loaiNha;
}
public String getDiaChi() {
	return diaChi;
}
public void setDiaChi(String diaChi) throws Exception{
	if(diaChi.trim().equals(""))throw new Exception("Dia chi rong");
	else this.diaChi = diaChi;
}

public GiaoDichNha() {
	super();
}
public GiaoDichNha(String maGiaoDich, LocalDate ngayGiaoDich, double donGia,
		float dienTich, boolean loaiNha, String diaChi) throws Exception {
	super(maGiaoDich, ngayGiaoDich, donGia, dienTich);
	setLoaiNha(loaiNha);
	setDiaChi(diaChi);
}
public double tinhThanhTien() {
	if(loaiNha)return super.getDonGia()*super.getDienTich();
	else return (super.getDonGia()*super.getDienTich()*90)/100;
}
@Override
public String toString() {
	DecimalFormat p=new DecimalFormat("#,##0");
	String k="";
	if(loaiNha)k="Cao cap";else k="Thuong";
	return String.format("Giao dich nha[%s ,loai nha:%5s ,dia chi:%10s ,thanh tien: %11s]",super.toString(),k,diaChi,p.format(tinhThanhTien()));
}

}
