import java.util.Scanner;

public class Sleep extends Thread
{
	static boolean res=false;
	public void run()
	{
		Scanner sc1=new Scanner(System.in);
		String s1="Lights Go Out And I can't Be Saved. Tides That I Tried To Swim Against.";
		String s2=new String();
		System.out.println("Please Retype The Following...");
		System.out.println(s1);
		s2=sc1.nextLine();		
		if(s1.equals(s2))
		{
			System.out.println("Congratulations!!");
			res=true;
		}		
		sc1.close();
	}
	
	public static void main(String args[]) throws InterruptedException 
	{
		Sleep X=new Sleep();
		X.setDaemon(true);
		X.start();
		sleep(25000);
		System.out.println("Time Up !!!");
		if(res==true)
			System.out.print("Well Done !!!");
		else
			System.out.print("Tough Luck !!");
	}
}
