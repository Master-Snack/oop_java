package bai9;

public class CongNhan {
	String maCN, mHo, mTen;
	int mSoSP;
	double luong, donGia;

	public CongNhan() {
		super();
	}
	
	public CongNhan(String maCN, String mHo, String mTen, int mSoSP) {
		super();
		this.maCN = maCN;
		this.mHo = mHo;
		this.mTen = mTen;
		this.mSoSP = mSoSP;
	}

	public String getMaCN() {
		return maCN;
	}

	public void setMaCN(String maCN) {
		this.maCN = maCN;
	}

	public String getmHo() {
		return mHo;
	}

	public void setmHo(String mHo) {
		this.mHo = mHo;
	}

	public String getmTen() {
		return mTen;
	}

	public void setmTen(String mTen) {
		this.mTen = mTen;
	}

	public int getmSoSP() {
		return mSoSP;
	}

	public void setmSoSP(int mSoSP) {
		this.mSoSP = mSoSP;
	}
	
	public double getDonGia() {
		if(1 <= mSoSP && mSoSP <= 199)
			return 0.5;
		else if(200 <= mSoSP && mSoSP <= 399)
			return 0.55;
		else if(400 <= mSoSP && mSoSP <= 599)
			return 0.6;
		else
			return 0.65;
	}

	public void setDonGia(double donGia) {
		this.donGia = donGia;
	}
//Phuong thuc tinh luong
	public double getLuong() {
		luong = mSoSP * getDonGia();
		return luong;
	}

	public void setLuong(double luong) {
		this.luong = luong;
	}
	
	

}
