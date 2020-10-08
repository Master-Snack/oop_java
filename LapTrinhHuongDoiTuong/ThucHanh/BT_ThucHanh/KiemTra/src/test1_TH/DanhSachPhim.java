package test1_TH;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class DanhSachPhim {
	private ArrayList<Phim> DanhSachPhim;
	
	public DanhSachPhim() {
		DanhSachPhim = new ArrayList<>();
	}
	
	
	public boolean Them(Phim x) {
		for(Phim y : DanhSachPhim) {
			if(x.getMaPhim().equalsIgnoreCase(y.getMaPhim()))
				return false;
		}
		DanhSachPhim.add(x);
		return true;
	}
	public boolean Xoa(Phim x) {
		for(Phim y : DanhSachPhim) {
			if(x.getMaPhim().equalsIgnoreCase(y.getMaPhim())) {
				DanhSachPhim.remove(y);
				return true;
			}
		}
		return false;
	}
	public double doanhThu_TrongNuoc() {
		double dt =0;
		for(Phim x : DanhSachPhim) {
			if(x instanceof PhimTrongNuoc)
				dt+=x.doanhThu();
		}
		return dt;
	}
	public double doanhThu_NuocNgoai() {
		double dt =0;
		for(Phim x : DanhSachPhim) {
			if(x instanceof PhimNuocNgoai)
				dt+=x.doanhThu();
		}
		return dt;
	}
	public void SapXepDoanhThu() {
		Collections.sort(DanhSachPhim, new Comparator<Phim>(){

			@Override
			public int compare(Phim o1, Phim o2) {
				if(o1.getMaPhim().compareTo(o2.getMaPhim())>0) return 1;
				else if (o1.getMaPhim().compareTo(o2.getMaPhim())<0) return -1;
				return 0;
			}
		});
	}
	
}
