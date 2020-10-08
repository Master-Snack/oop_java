package bai6;

import java.text.NumberFormat;
import java.util.Locale;

public class Account {

	private long accountNumber;
	private String name;
	private double balance;
	private final double RATE=0.035;
	
	//gete và seter
	
	public long getAccountNumber() {
		return accountNumber;
	}
	public void setAccountNumber(long accountNumber) {
		this.accountNumber = accountNumber;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public double getRATE() {
		return RATE;
	}
	
	//Contructor
	
	public Account() {
	}
	public Account(long accountNumber, String name, double balance) {
		super();
		setAccountNumber(accountNumber);
		setName(name);
		setBalance(balance);
	}
	public Account(long accountNumber, String name) {
		super();
		setAccountNumber(accountNumber);
		setName(name);
	}
	
	//Methords

	public boolean deposit(double amount){
		if(amount>0)
		{
			balance+=amount;
			return true;
		}
		else
			return false;
	}
	public boolean withdraw(double amount,double fee){
		if(amount>0 && amount+fee<=balance)
		{
			balance-=amount-fee;
			return true;
		}
		else
			return false;
	}
	public void addInterest(){
		balance=balance+balance*RATE;
		setBalance(balance);
	}
	public boolean transfer(Account acc,double amount){
		if(amount>0)
		{
			acc.setBalance(acc.balance+=amount);
			return true;
		}
		else
			return false;
	}
	public String toString() {
		return String.format("%15d%30s%15.2f",getAccountNumber(),getName(),getBalance());
	}
}
