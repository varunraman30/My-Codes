import java.io.*;
import java.util.Scanner;

public class Stud {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws IOException
	{
		File f=new File("Student.txt");
		FileWriter fout = new FileWriter(f,true);		
		BufferedWriter bout = new BufferedWriter(fout);
		String fname,lname,ch;
		int age,nos,roll;
		do
		{
			System.out.print("Enter Number of Students : ");			
			nos=sc.nextInt();
			for(int i=0;i<nos;i++)
			{
				System.out.println("Enter Student "+(i+1)+ " Details..");
				System.out.print("Enter First Name : ");
				fname=sc.next();
				System.out.print("Enter Last Name : ");
				lname=sc.next();
				System.out.print("Enter Roll No : ");
				roll=sc.nextInt();
				System.out.print("Enter Age : ");
				age=sc.nextInt();
				bout.write("Student "+i+1+" \n");
				bout.write("\nFirst Name : "+fname);
				bout.write("\nLast Name : "+lname);
				bout.write("\nRoll No : "+roll);
				bout.write("\nAge : "+age);	
			}
			System.out.print("Adding More Students ? : ");
			ch=sc.next();
		}while(ch.contentEquals("Y")||ch.contentEquals("y"));
		System.out.println("Database Updated.");
		System.out.println("Aborting....");
		bout.flush();
		bout.close();
		fout.close();
	}
}
