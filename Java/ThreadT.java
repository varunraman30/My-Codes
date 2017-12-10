import java.util.Scanner;

class T1 extends Thread 
{
	static Scanner s = new Scanner(System.in);
	public void run(ThreadT obj) {
		if (ThreadT.bool==true) {
			System.out.print("Enter 2 Numbers : ");
			obj.a = s.nextFloat();
			obj.b = s.nextFloat();
			ThreadT.bool=false;
		}
	}
}
class T2 extends Thread 
{
	public void run(ThreadT obj) {
		if (ThreadT.bool==false) {
			System.out.println("Sum is " + (obj.a + obj.b));
			ThreadT.bool=true;
		}
	}
}

public class ThreadT
{
	float a, b;
	
	static boolean bool=true;
	
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		ThreadT ob = new ThreadT();
		String ch;
		T1 t1 = new T1();
		T2 t2 = new T2();
		
		do 
		{
			t1.run(ob);
			t2.run(ob);
			System.out.print("Run Again ? : ");
			ch=sc.next();
		}while(ch.equals("y"));
		
		System.out.println("Aborting...");
		sc.close();
	}
}
