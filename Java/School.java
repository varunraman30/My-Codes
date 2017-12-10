public class School implements Headm
{
	String name,board,addr;
	int yr_of_op;
		
	public void get_details() 
	{
		System.out.print("Enter Name : ");
		name=s.next();
		System.out.print("Enter Board : ");
		board=s.next();
		System.out.print("Enter Year of Opening : ");
		yr_of_op=s.nextInt();
	}
	public void get_address() 
	{
		System.out.print("Enter Address : ");
		addr=s.next();	
	}

	public void disp_all() 
	{
		System.out.println("School Details....");
		System.out.print("Name : "+name+"\nBoard : "+board+"\nAddress : "+addr+"\nYear of Opening : "+yr_of_op);		
	
	}
	public static void main(String args[])
	{
		Student x=new Student();
		Teacher y=new Teacher();
		School z=new School();
		System.out.println("Enter Student Details...");
		x.get_details();
		x.get_address();
		x.disp_all();
		System.out.println("Enter Teacher Details...");
		y.get_details();
		y.get_address();
		y.disp_all();
		System.out.println("Enter School Details...");
		z.get_details();
		z.get_address();
		z.disp_all();
	}	
}
