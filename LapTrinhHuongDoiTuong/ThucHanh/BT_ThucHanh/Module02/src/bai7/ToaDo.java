package bai7;

public class ToaDo {
	private String ten;
	private float x;
	private float y;
	public float getX() {
		return x;
	}
	public void setX(float x) {
		this.x = x;
	}
	public float getY() {
		return y;
	}
	public void setY(float y) {
		this.y = y;
	}
	public ToaDo(float x, float y) {
		super();
		setX(x);
		setY(y);
	}
	public ToaDo() {
		super();
	}
	@Override
	public String toString() {
		return String.format("(%.0f,%.0f)",getX(),getY());
	}
	
}
