import java.util.Scanner;
public class Shape {
	static Scanner s=new Scanner(System.in);
	void T()
	{		
		System.out.print("Enter Height and Base : ");
		Float h=s.nextFloat();
		Float b=s.nextFloat();
		System.out.print("Area : "+0.5*h*b);		
	}
	void R(Float a,Float b)
	{
		System.out.print("Area : "+a*b);		
	}
	Float C()
	{
		System.out.print("Enter Radius : ");
		Float r=s.nextFloat();
		return 22/7*r*r;
	}
	Float S(Float a)
	{
		return a*a;
	}
	public static void main(String args[])
	{
		Shape x=new Shape();
		System.out.println("1.Triangle\n2.Rectangle\n3.Circle\n4.Square");
		System.out.println("Enter Choice : ");
		int c=s.nextInt();
		if (c==1)
			x.T();
		else if (c==2)
		{
			System.out.println("Enter Length and Breadth : ");
			Float a=s.nextFloat();
			Float b=s.nextFloat();
			x.R(a, b);
		}
		else if(c==3)
		{
			System.out.println(x.C());
		}
		else if(c==4)
		{
			System.out.println("Enter Side : ");
			Float a=s.nextFloat();
			System.out.println("Area : "+x.S(a));
		}
		else
		{
			System.out.println("Invalid");
		}
	}	
}
