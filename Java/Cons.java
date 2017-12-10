public class Cons {

	int i,j;
	Cons()
	{
		i=j=2;
		System.out.println("Default Constructor");
	}
	Cons(int i)
	{
		this.i=i;
		System.out.println("Parameterized Constructor 1");
	}
	Cons(int i,int j)
	{
		this.i=i;
		this.j=j;
		System.out.println("Parameterized Constructor 2");
	}
	void show()
	{
		System.out.println("i:- "+i+" j:- "+j);
	}
	public static void main(String args[])
	{
		Cons a=new Cons();
		Cons b=new Cons(6);
		Cons c=new Cons(5,10);
		a.show();
		b.show();
		c.show();
	}
}
