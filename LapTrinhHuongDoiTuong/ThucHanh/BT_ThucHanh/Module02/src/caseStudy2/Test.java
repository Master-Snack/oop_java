package caseStudy2;


public class Test {
	public static void main(String[] args) {
		Author[] Lonely = new Author[3];
		Lonely[0] = new Author("Zero", "gacon@gmail.com", '1');
		Lonely[1] = new Author("Lelouch", "mkha@gmail.com", '2');
		Lonely[2] = new Author("HTTT", "provip@gmail.com", '3');
		Book b = new Book("Alone", Lonely, 150000, 1);
		System.out.println(b);
		System.out.println(b.getAuthorName());
	}

}
