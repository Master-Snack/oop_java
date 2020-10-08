package caseStudy1;

public class Test {

	public static void main(String[] args) {
		Author a1 = new Author("Zero", "lhtdmkha@gmail.com", 'A');
		System.out.println(a1);
		Book b1 = new Book("sach", a1, 99999, 10);
		System.out.println(b1);
	}

}