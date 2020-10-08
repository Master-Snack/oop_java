package bai1;

public class ToaDo {
	private float X;
	private float Y;
	private String TenTD;
	
	public ToaDo(){
		this("", 0.0f, 0.0f);
	}
	public ToaDo(String tentd, float x, float y) {
		setTenTD(tentd);
		setX(x);
		setY(y);
		
	}
	
	public void setX(float x){
		if(x<0)
			this.X=0;
		else
			this.X=x;
	}
	public float getX() {
		return X;
	}
	public void setY(float y){
		if(y<0)
			this.Y=0;
		else
			this.Y=y;
	}
	public float getY() {
		return Y;
	}
	public void setTenTD(String tentd){
		this.TenTD=tentd;
	}
	public String getTenTD() {
		return TenTD;
	}
	
	public String toString() {
		return String.format("%-15s(%5.3f, %5.3f)", TenTD, X, Y);
	}
}