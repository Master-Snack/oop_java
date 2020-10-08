package bai3;

import java.text.DecimalFormat;
import java.time.LocalDate;

public class GiaoDichTienTe extends GiaoDich{
private double tiGia;
private String loaitien;

public String isLoaitien() {
	return loaitien;
}

public void setLoaitien(String loaitien) {
	this.loaitien = loaitien;
}

public double getTiGia() {
	return tiGia;
}

public void setTiGia(double tiGia) {
	if(tiGia>0)
	this.tiGia = tiGia;
	else this.tiGia=0;
}

public GiaoDichTienTe() {
	super();
}

public GiaoDichTienTe(String maGiaoDich, LocalDate ngayGiaoDich, double donGia, int soLuong, double tiGia,String loaitien)
		throws Exception {
	super(maGiaoDich, ngayGiaoDich, donGia, soLuong);
	setTiGia(tiGia);
	setLoaitien(loaitien);
}
public double thanhTien() {
	if(loaitien.equalsIgnoreCase("USD")||loaitien.equalsIgnoreCase("EURO"))
	return (super.getDonGia()*super.getSoLuong())*this.tiGia;
	else return super.getDonGia()*super.getSoLuong();
}
@Override
public String toString() {
	DecimalFormat o=new DecimalFormat("#,##0");
	return String.format("Giao dich tien te[ti gia:%10s ,loai tien:%5s ,%s]",o.format(tiGia),loaitien,super.toString());
}

}
