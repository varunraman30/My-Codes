public class Teacher implements Headm
{
	String name,addr;
    Float salary;
    int ID;
	public void get_details() 
	{
		System.out.print("Enter Your Name : ");
		name=s.next();
		System.out.print("Enter ID : ");
		ID=s.nextInt();
		System.out.print("Enter Salary : ");
		salary=s.nextFloat();		
	}	
	public void get_address() 
	{
		System.out.print("Enter Address : ");
		addr=s.next();	
	}	
	public void disp_all() 
	{
		System.out.println("Teacher Details....");
		System.out.print("Name : "+name+"\nID : "+ID+"\nAddress : "+addr+"\nSalary : "+salary);		
	}
}
