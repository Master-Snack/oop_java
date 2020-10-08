package bai4;

import java.text.DecimalFormat;
import java.time.LocalDate;

public class GiaoDichDat extends GiaoDich{
 private String loaiDat;

public String getLoaiDat() {
	return loaiDat;
}

public void setLoaiDat(String loaiDat) throws Exception{
	if(loaiDat.trim().equals(""))throw new Exception("Loai dat rong");
	else this.loaiDat = loaiDat;
}

public GiaoDichDat() {
	super();
}

public GiaoDichDat(String maGiaoDich, LocalDate ngayGiaoDich, double donGia,
		float dienTich, String loaiDat) throws Exception {
	super(maGiaoDich, ngayGiaoDich, donGia, dienTich);
	setLoaiDat(loaiDat);
}
 public double tinhThanhTien() {
	 if(loaiDat.equalsIgnoreCase("A"))
	return super.getDienTich()*super.getDonGia()*1.5;
	 else return super.getDienTich()*super.getDonGia();
	 
}

@Override
public String toString() {
	DecimalFormat p=new DecimalFormat("#,##0");
	return String.format("Giao dich dat[%s ,loai:%2s ,thanh tien:11%s]",super.toString(),loaiDat,p.format(tinhThanhTien()));
}
 
}
