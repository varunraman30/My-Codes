public class Student implements Headm
{
	String name,addr;
	int roll,total_m;
	public void get_details() 
	{
		System.out.print("Enter Your Name : ");
		name=s.next();
		System.out.print("Enter Roll No : ");
		roll=s.nextInt();
		System.out.print("Enter Total Mark : ");
		total_m=s.nextInt();
	}
	public void get_address() 
	{
		System.out.print("Enter Address : ");
		addr=s.next();	
	}
	public void disp_all() 
	{
		System.out.println("Student Details....");
		System.out.print("Name : "+name+"\nRoll No : "+roll+"\nAddress : "+addr+"\nTotal Mark : "+total_m);		
	}    
}

