package caseStudy1;

public class Book {
	
	private String name;
	private Author author;
	private double price;
	private int qty;
	//cac get set
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
	public Author getAuthor() {
		return author;
	}
	
	public Book(String name, Author author, double price) {
		super();
		this.name = name;
		this.author = author;
		this.price = price;
	}
	public Book(String name, Author author, double price, int qty) {
		super();
		this.qty = qty;
		this.name = name;
		this.author = author;
		this.price = price;
	}

	public String toString(){
		return "Book[name=" + name + "," + author + ",price=" + price + ",qty=" + qty +"]";
	}
}