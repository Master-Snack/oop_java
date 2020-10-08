package bai7;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class HangThucPham extends HangHoa {

	private String nhaCungCap;
	private LocalDate ngaySanXuat;
	private LocalDate ngayHetHan;

	public String getNhaCungCap() {
		return nhaCungCap;
	}

	public void setNhaCungCap(String nhaCungCap) {
		this.nhaCungCap = nhaCungCap;
	}

	public LocalDate getNgaySanXuat() {
		return ngaySanXuat;
	}

	public void setNgaySanXuat(LocalDate ngaySanXuat) {
		if (ngaySanXuat.isAfter(LocalDate.now()))
			this.ngaySanXuat = LocalDate.now();
		else
			this.ngaySanXuat = ngaySanXuat;
	}

	public LocalDate getNgayHetHan() {
		return ngayHetHan;
	}

	public void setNgayHetHan(LocalDate ngayHetHan) {
		if (ngayHetHan.isBefore(ngaySanXuat))
			this.ngayHetHan = this.ngaySanXuat;
		else
			this.ngayHetHan = ngayHetHan;
	}

	public HangThucPham() {
		super();
	}

	/**
	 * 
	 * @param maHang
	 * @param tenHang
	 * @param donGia
	 * @param soLuongTon
	 * @param nhaCungCap
	 * @param ngaySanXuat
	 * @param ngayHetHan
	 * @throws Exception
	 */
	public HangThucPham(String maHang, String tenHang, double donGia,
			int soLuongTon, String nhaCungCap, LocalDate ngaySanXuat,
			LocalDate ngayHetHan) throws Exception {
		super(maHang, tenHang, donGia, soLuongTon);
		setNhaCungCap(nhaCungCap);
		setNgaySanXuat(ngaySanXuat);
		setNgayHetHan(ngayHetHan);
	}

	/**
	 * 
	 * @return true neu hang het han
	 */
	public boolean tinhTrang() {
		if (ngayHetHan.isBefore(LocalDate.now()))
			return true;
		else
			return false;
	}

	@Override
	public String toString() {
		DateTimeFormatter format = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		return String.format("%s NhaCC:%20s | NgaySX:%11s | NgayHetHan:%11s |",
				super.toString(), nhaCungCap, format.format(ngaySanXuat),
				format.format(ngayHetHan));
	}

	@Override
	public String danhGiaMucDoBanBuon() {
		String s = "";
		if (super.getSoLuongTon() > 0 && tinhTrang())
			s = "Kho ban";
		return s;
	}
}
