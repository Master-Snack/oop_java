package bai8;
import java.util.Arrays;
import java.util.Comparator;
public class ListCD {
	private static int count;
	private static CD[] ds;
	public ListCD (int n){
		ds= new CD[n];
		count=0;
	}
	public boolean ThemCD(CD cd){
		for (int i=0; i<count; i++)
			if (ds[i].getMaCD()==cd.getMaCD())
				return false;
		if (ds.length==count)
			return false;
		ds[count]=cd;
		count++;
		return true;
	}
	public static int soluongCD(){
		return count;
	}
	public static double TongTien(){
		double tien=0;
		for (int i=0; i<count; i++)
			tien += ds[i].getGiathanh();
		return tien;
	}
	public static void SxGia(){
		Arrays.sort(ds, 0, count, new Comparator<CD>(){
			public int compare (CD c1, CD c2){
				if (c1.getGiathanh()>c2.getGiathanh())
					return 1;
				else
				{
					if (c1.getGiathanh()==c2.getGiathanh())
						return 0;
					else return -1;
				}
					
			}
		});
	}
	public static void SxtuaCD(){
		Arrays.sort(ds, 0, count, new Comparator<CD>(){
			public int compare(CD c1, CD c2){
				return (c1.getTuaCD().compareToIgnoreCase(c2.getTuaCD()));
			}
		});
	}
	
	public void xuat(){
		System.out.printf("%s%20s%20s%20s%20s\n", "Mã CD", "Tựa CD",
				"Tên Ca Sỹ", "Số Bài Hát", "Giá Thành");
		for (int i=0; i<count; i++)
			System.out.println(ds[i].toString());
	}
	public static void xuatCasy(String st){
		int cc=0;
		for (int i=0; i<count; i++)
			if (ds[i].getCasy().equalsIgnoreCase(st))
			{
				System.out.println(ds[i]);
				cc++;
			}
		if (cc==0)
			System.out.println("Không tồn tại ca sỹ "+ st);
				
	}
}
