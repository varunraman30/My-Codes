public class sib_iib 
{
	int a,b;	
	sib_iib()
	{
		a=b=8;
		System.out.println("Default Cons");
	}
	void display()
	{
		System.out.println("a:- "+a+" b:- "+b);
	}
	{
		System.out.println("Instance Initialization Block");
	}
	static
	{
		System.out.println("Static Initialization Block");
		System.out.println("Hello Everyone");
	}
	public static void main(String args[])
	{
		sib_iib x=new sib_iib();
		x.display();
	}	
}
