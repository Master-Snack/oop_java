package caseStudy2;

public class Book {
	
	private String name;
	private Author[] authors;
	private double price;
	private int qty;
	
	public Book(String name, Author[] authors, double price) {
		super();
		this.name = name;
		this.authors = authors;
		this.price = price;
	}
	public Book(String name, Author[] authors, double price, int qty) {
		super();
		this.name = name;
		this.authors = authors;
		this.price = price;
		this.qty = qty;
	}
	
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public int getQty() {
		return qty;
	}
	public void setQty(int qty) {
		this.qty = qty;
	}
	public String getName() {
		return name;
	}
	public Author[] getAuthors() {
		return authors;
	}
	
	public String toString(){
		String s = "";
		for (Author author : authors) {
			s += author + ",";
		}
		return String.format("Book[name=%s, authors{%s}, price=%f, qty=%d", name, s.substring(0, s.length() - 1), price, qty);
	}
	public String getAuthorName(){
		String s = "";
		for (Author author : authors) {
			s += author.getName() + ", ";
		}
		return s.substring(0, s.length() - 2);
	}
}