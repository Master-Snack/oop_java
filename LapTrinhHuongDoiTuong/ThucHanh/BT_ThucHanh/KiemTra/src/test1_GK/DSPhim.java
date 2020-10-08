package test1_GK;

public class DSPhim {
	private int count;
	private Phim[] phim;
	
	public DSPhim(int n) {
		phim = new Phim[n];
		count = 0;
	}
	

	public boolean themPhim(Phim phimt) {
		for(int i=0; i<count; i++)
			if(phim[i].getMaPhim() == phimt.getMaPhim())
				return false;
		if(phim.length == count)
			return false;
		phim[count] = phimt;
		count++;
		return true;
	}
	
	
	public void xoaPhim(String ten) {
		for(int i=0; i<count; i++)
			if(phim[i].getTenPhim().equalsIgnoreCase(ten)) {
				for(int j=i+1;j<count; j++)
					phim[j-1]=phim[j];
				count--;
			}
	}
	
	
	public int tinhTongTien() {
		int tong = 0;
		for(int i=0; i<count; i++) {
			tong+= phim[i].getThanhTien();
		}		
		return tong;		
	}
	
	
	public void sapXepDS() {
		for(int i=0; i< count -1 ; i++)
			for(int j=i+1; j<count; j++)
				if(phim[i].getTenPhim().length() > phim[j].getTenPhim().length()) {
					Phim tamp = phim[i];
					phim[i] = phim[j];
					phim[j] = tamp;
				}
	}
	
	
	public void xuatDSPhim() {
		for(int i=0; i<count; i++)
			System.out.println(phim[i].toString());
	}

}
