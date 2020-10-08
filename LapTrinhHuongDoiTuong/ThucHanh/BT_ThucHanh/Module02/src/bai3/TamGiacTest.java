package bai3;

public class TamGiacTest {

	public static void main(String[] args) {
		TamGiac TG1 = new TamGiac(1, 2, 3);
		TamGiac TG2 = new TamGiac(4, 3, 8);
		TamGiac TG3 = new TamGiac(1, 2, 2.5f);
		TamGiac TG4 = new TamGiac(3, 2, 2);
		TamGiac TG5 = new TamGiac(3, 3, 3);
		
		xuatThongTin();
		System.out.println(TG1);
		System.out.println(TG2);
		System.out.println(TG3);
		System.out.println(TG4);
		System.out.println(TG5);
		
	}
	static void xuatThongTin() {
		System.out.printf("%-10s %-10s %-10s %-30s %-15s %-15s\n", "Cạnh a", "Cạnh b", "Cạnh c", "Kiểu tam giác", "Chu vi", "Diện tích");
	}

}
