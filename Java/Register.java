package hw;

import java.util.Scanner;

public class Register 
{	
	static Scanner sc=new Scanner(System.in);
	String name,pw,un;
	int age;	
	void register()
	{
		System.out.println("Enter Details...\n");
		System.out.print("Enter Name : ");
		name=sc.next();
		System.out.print("Enter Age : ");
		age=sc.nextInt();
		System.out.print("Enter Username : ");
		un=sc.next();
		System.out.print("Enter Password : ");
		pw=sc.next();
		System.out.println("Registration Successsul :)");
	}	
	protected void display()
	{
		System.out.println("Name : "+name);
		System.out.println("Age : "+age);
		System.out.println("Username : "+un);
		System.out.println("Password : "+pw);		
	}	
}
