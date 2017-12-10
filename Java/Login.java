package hw;

public class Login extends Register
{
   String chun,chpw;
   void login()
   {
	  System.out.println("Enter Credientials...\n");
	  System.out.print("Enter Username : ");
	  chun=sc.next();
	  System.out.print("Enter Password : ");
	  chpw=sc.next();
   }
   char validate() 
   {
	  if(chun.contentEquals(un)&&chpw.contentEquals(pw))
	  {
		  System.out.println("Login Successful !!");
		  display();
		  return 'y';
	  }
	  else
	  {
		  System.out.println("Try Again...");
		  return 'n';
	  }
	
   }
   public static void main(String[] args) 
   {
	  Login x=new Login();
	  x.register();
	  do
	    x.login();		    
	  while(x.validate()=='n');
	  	  
   }
}
