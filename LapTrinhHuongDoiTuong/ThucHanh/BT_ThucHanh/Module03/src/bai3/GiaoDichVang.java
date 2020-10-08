package bai3;

import java.time.LocalDate;

public class GiaoDichVang extends GiaoDich{
private String loaiVang;

public String getLoaiVang() {
	return loaiVang;
}

public void setLoaiVang(String loaiVang) throws Exception{
	if(loaiVang.trim().equals(""))throw new Exception("loai vang rong");
	else this.loaiVang = loaiVang;
}

public GiaoDichVang(String maGiaoDich, LocalDate ngayGiaoDich, double donGia, int soLuong, String loaiVang)
		throws Exception {
	super(maGiaoDich, ngayGiaoDich, donGia, soLuong);
	setLoaiVang(loaiVang);
}

public GiaoDichVang() {
	super();
}
public double thanhTien() {
	return super.getDonGia()*super.getSoLuong();
}
@Override
public String toString() {
	return String.format("Giao dich vang[loai vang:%10s ,%s]",loaiVang,super.toString());
}

}
