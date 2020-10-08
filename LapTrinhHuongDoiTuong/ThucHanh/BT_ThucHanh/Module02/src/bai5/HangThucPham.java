package bai5;
import java.text.DecimalFormat;
import java.text.ParseException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.text.DecimalFormatSymbols;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeFormatterBuilder;
import java.util.*;
public class HangThucPham {
	private  String maHang;
	private String tenHang;
	private double donGia;
	private String ngaySanXuat;
	private String ngayHetHang;
	public String getMaHang() {
		return maHang;
	}
	public void setMaHangg(String maHang) throws Exception
	{
		if(!maHang.trim().equals(""))
			this.maHang=maHang;
		else
			throw new Exception("Lỗi: Mã hàng rỗng");
	}
	public String getTenHang() {
		return tenHang;
	}
	public void setTenHang(String tenHang) {
		if(tenHang.equals(" "))
			this.tenHang="xxx";
		else
			this.tenHang = tenHang;
	}
	public double getDonGia() {
		
		return donGia;
	}
	public void setDonGia(double donGia) {
		this.donGia = donGia;
	}
	public String getNgaySanXuat() {
		return ngaySanXuat;
	}
	public void setNgaySanXuat(String ngaySanXuat) {
		
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		String date = ngaySanXuat;
		LocalDate localDate = LocalDate.parse(date, formatter);
		
		DateTimeFormatter formatter_2 = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		String format_2=(LocalDate.now()).format(formatter_2);
		   
		if(localDate.isAfter(LocalDate.now()))
			this.ngaySanXuat=format_2;
		else
			this.ngaySanXuat = ngaySanXuat;
	}
	public String getNgayHetHang() {
		return ngayHetHang;
	}
	public void setNgayHetHang(String ngayHetHang) {
		
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		String date = ngaySanXuat;
		LocalDate localDate = LocalDate.parse(date, formatter);
		
		String date2 = ngayHetHang;
		LocalDate localDate2 = LocalDate.parse(date2, formatter);
		
		if(localDate2.isBefore(localDate))
			this.ngayHetHang=ngaySanXuat;
		else
			this.ngayHetHang = ngayHetHang;
	}
	public HangThucPham(String maHang, String tenHang, double donGia, String ngaySanXuat, String ngayHetHan) throws Exception{
		
		
			setMaHangg(maHang);
			setTenHang(tenHang);
			setDonGia(donGia);
			setNgaySanXuat(ngaySanXuat);
			setNgayHetHang(ngayHetHan);
	}
	public HangThucPham(int maHang){
	}
	public boolean hetHan() {
		
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		String date = ngayHetHang;
		LocalDate localDate = LocalDate.parse(date, formatter);
		
		return localDate.isBefore(localDate.now())?true:false;
	}
	public String traTin() {
		String S;
		if(hetHan()==true)
			return "Hàng hết hạn";
		else
			return " ";
	}
	public String toString() {
		DecimalFormat df = new DecimalFormat("#.##0.00");
		return String.format("%-7s %10s %30s %15s %15s %25s",getMaHang(),getTenHang(),df.format(donGia),getNgaySanXuat(),getNgayHetHang(),traTin());
	}
}
