import java.util.Scanner;

public class Factorial {
	
	public static void main(String[] args) {
		
		int num,fact,i;
		String a;
		Scanner s=new Scanner(System.in);
		while(true)
		{
			fact=1;
			System.out.print("Enter Number : ");
			num=s.nextInt();
			if(num<1)
				System.out.println("No Factorial");
			else
			{
				for(i=1;i<=num;i++)
					fact*=i;
				System.out.println("The Factorial of "+num+" is : "+fact);
			}
			System.out.print("Do you wanna try again (Y/N): ");
			a=s.next();
			if(a.contentEquals("y")||a.contentEquals("Y"))
				continue;
			else
			{
				System.out.println("Aborting...");
				break;
			}
		}
		s.close();
	}

}
