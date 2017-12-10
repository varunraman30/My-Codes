public class B extends A
{
	int b;
	B()
	{
		System.out.println("Default Constructor - B");
		b=9;
	}
	void show2()
	{
		show1();
		System.out.println("b :- "+b);		
	}
	public static void main(String args[])
	{
		B x=new B();
		A y=new A();
		x.show2();
		y.show1();
	}
}
